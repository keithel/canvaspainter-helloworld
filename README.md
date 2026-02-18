# CanvasPainter HelloWorld Example

This is a minimal example application demonstrating the use of the new Qt 6.11 CanvasPainter module, an accelerated canvas API for Qt Quick and Qt Widgets applications.

## Features
- Uses the CanvasPainter module
- Simple C++ and QML integration
- Demonstrates custom item rendering

## Requirements
- Qt 6.11 with CanvasPainter Technical Preview module
- CMake
- A C++17 compatible compiler

## Building
1. Ensure you have Qt 6.11 with Qt Canvas Painter TP installed and available in your PATH.
2. Clone this repository.
3. Configure and build with CMake:
   ```sh
   <path to Qt bin>/qt-cmake -B build -S .
   <path to Qt bin>/qt-cmake --build build
   ```
4. Run the application from the build directory.

## Notes
- This project is for demonstration and experimentation with the new CanvasPainter API.

## License
This project is licensed under the BSD License. See the LICENSE file for details.
