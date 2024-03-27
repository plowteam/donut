# donut

[![GitHub Stars](https://img.shields.io/github/stars/plowteam/donut?logo=github)](https://github.com/plowteam/donut/stargazers)
[![Discord chat](https://img.shields.io/discord/611594006803120148?logo=discord&logoColor=white)](https://discord.gg/U7jFGJKuW4)
[![License](https://img.shields.io/github/license/plowteam/donut)](LICENSE.md)

donut is an open source reimplementation of [The Simpsons: Hit & Run](https://en.wikipedia.org/wiki/The_Simpsons:_Hit_&_Run)
written in modern C++ and modern OpenGL.

You still need to have the original game assets in order to use this.

---

<a href="https://files.facepunch.com/Layla/2019/August/11/2019-08-09_22-12-28.png">
    <img src="https://files.facepunch.com/Layla/2019/August/11/2019-08-09_22-12-28.png" width="45%">
</a>
<a href="https://files.facepunch.com/Layla/2019/August/11/2019-08-09_22-11-26.png">
    <img src="https://files.facepunch.com/Layla/2019/August/11/2019-08-09_22-11-26.png" width="45%">
</a>

# Building

Clone the code using: `git clone --recursive https://github.com/plowteam/donut.git`

The simplest way to obtain all the required dependencies is through [vcpkg](https://github.com/Microsoft/vcpkg).

```bash
PS> .\vcpkg install sdl2 bullet3 openal-soft fmt
Linux:~/$ ./vcpkg install sdl2 bullet3 openal-soft fmt
```

If you don't want to use vcpkg; CMake will fallback on installed system dependencies, or manually specified
package directories.

## Windows

* Install [Visual Studio 2019](https://visualstudio.microsoft.com/downloads/)
* Install [CMake](https://cmake.org/download/)

You can either:

1. [Open the `donut` folder directly in Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=vs-2019).
2. Or generate project files with the following:

```bash
cd donut
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows
```

## Linux

*Note: These instructions are for Ubuntu, but can be easily applied to other distros.*

Ensure you have dependencies first
```bash
sudo apt install cmake
cd donut
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-linux
cmake --build build -j 5
```

**Mesa drivers on Linux:** if you are trying to run with Mesa drivers and are getting issues with OpenGL context try messing with `MESA_GL_VERSION_OVERRIDE` when running like so: `MESA_GL_VERSION_OVERRIDE=4.3FC MESA_GLSL_VERSION_OVERRIDE=430 bin/donut`

## Running

The binary called `donut` should be launched from the root of the original game deployment (similar to original `Simpsons` binary). Additional assets from the `assets` source directory (both `windows` and `shaders`) should also be copied to the root of the original game deployment.

## Docs
* [Chunks](dev/Chunks.md)
* [Commands](dev/Commands.md)

## Contributing
Contributions are always welcome, whether it's modifying source code to add new
features or bug fixes, documenting new file formats or simply editing some
grammar.

You can also join the [Discord for development discussion]((https://discord.gg/xpdbWzG))
if you are unsure of anything.

## License
donut is released as open source software under the [GPL v3](https://opensource.org/licenses/gpl-3.0.html)
license, see the [LICENSE.md](./LICENSE.md) file in the project root for the full license text.
