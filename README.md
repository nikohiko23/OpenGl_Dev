# OpenGl_Dev

An educational project written in C++ and modern OpenGL (4.6 Core Profile), created to learn the fundamentals of computer graphics, the rendering pipeline, shaders, and 3D space.

## Implemented Features
* **Window & Context Initialization:** Window creation and input handling using GLFW, OpenGL function loading via GLAD.
* **Graphics Pipeline:** Working with Vertex Buffer Objects (VBO), Vertex Array Objects (VAO), and Element Buffer Objects (EBO).
* **Shaders:** Custom `Shader` class for loading, compiling, and managing GLSL vertex and fragment shaders.
* **Texturing:** Image loading using `stb_image`, configuring texture wrapping, filtering, and blending multiple textures.
* **3D Space & Transformations:** Implementing Model, View, and Projection (MVP) matrices with GLM and enabling depth testing (Z-buffer).
* **Camera System:** Free-look first-person `Camera` class with keyboard movement and Euler-angle mouse look.

## Controls
* **W / A / S / D** — Move camera
* **Mouse** — Look around
* **Scroll Wheel** — Zoom in / out (FOV)
* **ESC** — Exit application

## Technologies & Libraries
* **C++17**
* **CMake** (build system)
* **OpenGL 4.6** (Core Profile)
* **GLFW** — Window management and input
* **GLAD** — OpenGL function loader
* **GLM** — OpenGL Mathematics (vectors and matrices)
* **stb_image** — Texture loading

## Build & Run

### Prerequisites
* A C++17 compliant compiler (MSVC, GCC, or Clang)
* CMake 3.15 or higher
* GLFW, GLAD, and GLM libraries (by default, `CMakeLists.txt` looks for them in `D:/OpenGl_Dev` on Windows)

### Build Instructions (Terminal)
```bash
# 1. Clone the repository
git clone https://github.com
cd OpenGl_Dev

# 2. Create a build directory and generate project files
mkdir build
cd build
cmake ..

# 3. Compile the project
cmake --build . --config Debug
```
*Note: CMake will automatically copy the shaders and textures into the executable output directory after building.*