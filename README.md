# 🎨 ASCII Image Converter

Convert images into **ASCII art** directly in your terminal!  

This project takes any image file, downsamples it, and maps each pixel to an ASCII character based on brightness — creating a fun text-based representation of your images. 🖼️➡️💻

---

## 📸 Preview
<div align="left">
  <img src="/sample-image.jpeg" alt="Test Image" width="45%"/>
  <img src="/sample-result.png" alt="ASCII Preview" width="45%"/>
</div>

---

## 🚀 Features
- 🖼️ Supports PNG, JPG, JPEG, GIF, BMP, and other common formats.
- 📏 Able to downsample images to fit terminal dimensions.
- 🎨 Maps pixel brightness to ASCII characters for high-fidelity output.
- 🌈 Optionally supports RGB color channels for advanced output.
- ⚡ Lightweight, fast, and terminal-friendly.

---

## 🛠️ Tech Stack
- **Language:** C++  
- **Dependencies:** [STB Image](https://github.com/nothings/stb) (`stb_image.h`)  

---

## 📦 Getting Started

### Prerequisites
- C++ compiler (G++ / MSVC / Clang) 🛠️
- `stb_image.h` header file 📎

### Installation
```bash
git clone https://github.com/Ure-B/ascii-image-converter.git
cd ascii-image-converter
```

### Compile
```bash
g++ convert.cpp -o ascii_converter
```

### Run Locally
```bash
./ascii_converter
```

---

## 🎯 Usage
The program can take a file path, scale, and color option as input:
```cpp
createImage("image.png", scale, color);
```

**Parameters:**
- filePath — Path to your image file 🖼️
- scale — Downsampling factor (higher = smaller ASCII image) 📏
- color — Consider RGB channels? (true/false) 🌈

**Example**
```text
Enter the image path (string), scale factor (int), and color option (Y/N). (All separated by a space): image.png 2 Y
```
The image will be printed in ASCII directly to your terminal 💻.

---

## 📄 License
MIT License © [Brendan Ure](LICENSE)
