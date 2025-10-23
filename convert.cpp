#include<iostream>
#include<string>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

unsigned char* downsampleImage(unsigned char* originalData, int* width, int* height, int* channels, int scale) {
    int scaledX = scale;
    int scaledY = scale * 2;
    int newWidth  = *width / scaledX;
    int newHeight = *height / scaledY;

    unsigned char* newData = new unsigned char[newWidth * newHeight * (*channels)];

    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {

            int sumR = 0;
            int sumG = 0;
            int sumB = 0;
            int count = 0;

            // Loop over each pixel in the original block
            for (int dy = 0; dy < scaledY; dy++) {
                for (int dx = 0; dx < scaledX; dx++) {
                    int origX = x * scaledX + dx;
                    int origY = y * scaledY + dy;

                    // compute the index in original image
                    int index = (origY * *width + origX) * *channels;

                    sumR += originalData[index + 0];
                    sumG += originalData[index + 1];
                    sumB += originalData[index + 2];
                    count += 1;
                }
            }

            // Compute average color for this block
            int avgR = sumR / count;
            int avgG = sumG / count;
            int avgB = sumB / count;

            // Store in new downsampled image array
            int newIndex = (y * newWidth + x) * *channels;
            newData[newIndex + 0] = avgR;
            newData[newIndex + 1] = avgG;
            newData[newIndex + 2] = avgB;
        }
    }
    
    // Update width and height to new dimensions
    *width = newWidth;
    *height = newHeight;
    
    return newData;
}

void createImage(const char* path = "image.png", int scale = 1, bool color = true) {
    string ascii = " .:-=+*#%@";
    int width, height, channels;

    unsigned char* data = stbi_load(path, &width, &height, &channels, 3);

    channels = 3;

    std::cout << "Image Width: " << width << ", Height: " << height << ", Channels: " << channels << endl;

    data = downsampleImage(data, &width, &height, &channels, scale);

    cout << "Downsampled Image Width: " << width << ", Height: " << height << ", Channels: " << channels << endl;

    if (data) {
        
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int index = (y * width + x) * channels;
                int R = data[index + 0];
                int G = data[index + 1];
                int B = data[index + 2];

                int brightness = 0.2126 * R + 0.7152 * G + 0.0722 * B;
                int c = (brightness * (ascii.length() - 1)) / 255;
                if (!color) {
                    cout << ascii[c];
                    continue;
                }
                string colorCode = "\033[38;2;" + to_string(R) + ";" + to_string(G) + ";" + to_string(B) + "m";
                cout << colorCode << ascii[c] << "\033[0m";
            }
            cout << endl;
        }

        stbi_image_free(data); // Free the allocated memory after use
    } else {
        cout << "Error loading image: " << stbi_failure_reason() << endl;
    }
}

int main() {
    // ToDo: Add command line arguments for image path, scale, and color option

    // Image Data
    createImage("image2.PNG", 8);
    createImage("image1.jpg", 1, false);
    //createImage("image2.png", 32);

    return 0;
}