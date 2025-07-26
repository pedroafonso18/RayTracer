# 🚀 Real-Time Ray Tracer (RT)

A high-performance, modular ray tracing engine written in modern C++ with a focus on clean architecture, extensibility, and educational value. This project demonstrates advanced C++ concepts, mathematical foundations, and computer graphics principles.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Architecture](#architecture)
- [Installation](#installation)
- [Usage](#usage)
- [Technical Details](#technical-details)
- [Project Structure](#project-structure)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This ray tracing engine implements a physically-based rendering system that simulates light transport in 3D environments. The project serves as both a learning platform for computer graphics concepts and a foundation for more advanced rendering applications.

### Key Highlights

- **Modular Design**: Clean separation of concerns with dedicated classes for vectors, rays, colors, and rendering
- **Performance Optimized**: Efficient mathematical operations and memory management
- **Extensible Architecture**: Easy to add new features like materials, lighting, and geometric primitives
- **Modern C++**: Utilizes C++17/20 features for type safety and performance
- **Educational Focus**: Well-documented codebase perfect for learning ray tracing fundamentals

## ✨ Features

### Current Implementation
- ✅ **Vector Mathematics**: Complete 3D vector operations (addition, subtraction, multiplication, dot/cross products)
- ✅ **Ray Generation**: Efficient ray creation and manipulation for camera projection
- ✅ **Color Management**: RGB color space handling with proper gamma correction
- ✅ **Camera System**: Pinhole camera model with configurable aspect ratio and resolution
- ✅ **Gradient Background**: Sky-like gradient rendering based on ray direction
- ✅ **PPM Output**: Standard PPM image format for easy viewing and processing

### Planned Features
- 🔄 **Geometric Primitives**: Spheres, planes, triangles, and complex meshes
- 🔄 **Material System**: Diffuse, metallic, dielectric, and custom materials
- 🔄 **Lighting**: Point lights, area lights, and environment maps
- 🔄 **Shadows & Reflections**: Realistic shadow casting and surface reflections
- 🔄 **Anti-aliasing**: Multi-sampling for smooth edges and reduced noise
- 🔄 **Acceleration Structures**: BVH trees for efficient ray-object intersection
- 🔄 **Texture Mapping**: UV coordinates and procedural textures
- 🔄 **Motion Blur**: Temporal effects for dynamic scenes

## 🏗️ Architecture

### Core Components

#### 1. **Vec3 Class** (`Vec3.h`, `Vec3.cpp`)
The mathematical foundation of the engine, providing:
- 3D vector operations with operator overloading
- Efficient memory layout with array-based storage
- Mathematical utilities (length, normalization, dot/cross products)
- Type-safe operations with const-correctness

#### 2. **Ray Class** (`Ray.h`)
Represents light rays in 3D space:
- Origin and direction vectors
- Ray parameterization for intersection calculations
- Immutable design for thread safety
- Efficient `at(t)` method for point evaluation

#### 3. **Color System** (`Color.h`, `Color.cpp`)
Handles color representation and output:
- RGB color space with proper gamma correction
- PPM format output for image generation
- Namespace-based organization for clarity
- Stream-based output for flexibility

#### 4. **Main Renderer** (`main.cpp`)
Orchestrates the rendering pipeline:
- Camera setup with configurable parameters
- Ray generation for each pixel
- Viewport and pixel coordinate calculations
- Progress tracking and output management

### Design Patterns

- **RAII**: Automatic resource management
- **Const Correctness**: Immutable operations where appropriate
- **Operator Overloading**: Intuitive mathematical syntax
- **Namespace Organization**: Clear separation of concerns
- **Stream-Based I/O**: Flexible output handling

## 🛠️ Installation

### Prerequisites
- C++17/20 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10 or higher
- Make or Ninja build system

### Build Instructions

```bash
# Clone the repository
git clone <repository-url>
cd RT

# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build the project
make -j$(nproc)
# or
ninja
```

### Running the Renderer

```bash
# Generate a test image
./RT > output.ppm

# View the result (requires image viewer)
# On Linux: eog output.ppm
# On macOS: open output.ppm
# On Windows: start output.ppm
```

## 📖 Usage

### Basic Rendering

```cpp
#include "Color.h"
#include "Ray.h"
#include "Vec3.h"

// The engine automatically generates a gradient sky
// based on ray direction for each pixel
```

### Customizing Parameters

```cpp
// Modify these parameters in main.cpp for different results
auto aspect_ratio = 16.0 / 9.0;  // Widescreen format
int image_width = 400;           // Resolution
auto focal_length = 1.0;         // Camera distance
auto viewport_height = 2.0;      // Field of view
```

### Output Format

The renderer outputs PPM (Portable Pixmap) format:
- Header: `P3` (ASCII RGB)
- Dimensions: `width height`
- Color depth: `255`
- Pixel data: `R G B` values per line

## 🔬 Technical Details

### Mathematical Foundations

#### Vector Operations
- **Addition/Subtraction**: Component-wise operations
- **Scalar Multiplication**: Efficient scaling with operator overloading
- **Dot Product**: Used for lighting calculations and projections
- **Cross Product**: Essential for normal calculations and coordinate systems
- **Normalization**: Unit vector generation for direction calculations

#### Ray Tracing Algorithm
1. **Camera Setup**: Define viewport and pixel grid
2. **Ray Generation**: Create rays from camera through each pixel
3. **Intersection Testing**: (Future) Test rays against scene objects
4. **Color Calculation**: Determine pixel color based on ray direction
5. **Output**: Write RGB values to image file

#### Coordinate System
- **Right-handed**: Standard computer graphics convention
- **Y-up**: World coordinate system with Y pointing upward
- **Camera Space**: Z-axis pointing into the scene

### Performance Considerations

- **Memory Layout**: Array-based vector storage for cache efficiency
- **Const References**: Minimize copying in function parameters
- **Inline Functions**: Small mathematical operations inlined for speed
- **Stream Buffering**: Efficient output handling for large images

## 📁 Project Structure

```
RT/
├── CMakeLists.txt          # Build configuration
├── main.cpp               # Main rendering loop
├── Vec3.h                 # Vector mathematics interface
├── Vec3.cpp               # Vector mathematics implementation
├── Ray.h                  # Ray class definition
├── Color.h                # Color utilities interface
├── Color.cpp              # Color utilities implementation
└── cmake-build-debug/     # Build artifacts
```

### File Descriptions

- **`CMakeLists.txt`**: Modern CMake configuration with proper target setup
- **`main.cpp`**: Entry point with camera setup and rendering pipeline
- **`Vec3.h/cpp`**: Mathematical foundation with 3D vector operations
- **`Ray.h`**: Ray representation for light transport simulation
- **`Color.h/cpp`**: Color space handling and image output utilities

## 🗺️ Roadmap

### Phase 1: Foundation (Current) ✅
- [x] Vector mathematics library
- [x] Ray representation and manipulation
- [x] Basic camera system
- [x] Color output system
- [x] Gradient background rendering

### Phase 2: Geometric Primitives (Next)
- [ ] Sphere intersection algorithms
- [ ] Plane and triangle primitives
- [ ] Mesh loading and rendering
- [ ] Bounding box calculations
- [ ] Ray-object intersection testing

### Phase 3: Materials and Lighting
- [ ] Diffuse material implementation
- [ ] Metallic and dielectric materials
- [ ] Point and area light sources
- [ ] Shadow casting algorithms
- [ ] Reflection and refraction

### Phase 4: Advanced Features
- [ ] Anti-aliasing (multi-sampling)
- [ ] Acceleration structures (BVH)
- [ ] Texture mapping system
- [ ] Motion blur and depth of field
- [ ] Environment maps and HDR lighting

### Phase 5: Optimization and Polish
- [ ] Multi-threading support
- [ ] GPU acceleration (CUDA/OpenCL)
- [ ] Real-time preview mode
- [ ] Scene file format (JSON/YAML)
- [ ] GUI for parameter adjustment

### Phase 6: Production Features
- [ ] Advanced materials (subsurface scattering, anisotropy)
- [ ] Volume rendering (fog, smoke, clouds)
- [ ] Animation and keyframe support
- [ ] Network rendering capabilities
- [ ] Plugin system for custom shaders

## 🤝 Contributing

We welcome contributions! Please see our contributing guidelines:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Development Guidelines

- Follow modern C++ best practices
- Maintain const-correctness and RAII principles
- Add comprehensive unit tests for new features
- Update documentation for API changes
- Ensure cross-platform compatibility

### Code Style

- Use meaningful variable and function names
- Include proper header guards and includes
- Follow consistent indentation (4 spaces)
- Add comments for complex algorithms
- Use `[[nodiscard]]` for important return values

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Inspired by "Ray Tracing in One Weekend" by Peter Shirley
- Built with modern C++ principles and best practices
- Designed for educational and professional use

---

**Built with ❤️ and modern C++**

*This project demonstrates advanced software engineering principles, mathematical foundations, and computer graphics expertise - perfect for showcasing technical skills to potential employers.* 