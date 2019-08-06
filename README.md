# donut

![](https://files.facepunch.com/Layla/2019/July/28/donut2.gif)

donut is an open source reimplementation of The Simpsons: Hit & Run.

# Building

Clone the code using: `git clone --recursive https://github.com/plowteam/donut.git`

## Windows

* Install [Visual Studio 2019](https://visualstudio.microsoft.com/downloads/)
* Install [CMake](https://cmake.org/download/)
* Open CMake GUI and point it to `donut` folder, set build directory to `donut/build`
* Set `BULLET_ROOT` to the Bullet directory, everything else is automatically set.
* Press Configure, Generate, Open Project and then build.

### Building Bullet

* Download [Bullet](https://github.com/bulletphysics/bullet3)
* Build using CMake or Premake, making sure `USE_MSVC_RUNTIME_LIBRARY_DLL` is enabled.

## Linux

First you'll need to install the following dependencies to build donut:

```bash
apt install build-essential libsdl2-dev cmake libglm-dev libbullet-dev libopenal-dev
```

Then to build run CMake in a build directory:

```bash
mkdir build && cd build
cmake ../
make
```

### Contributing
Contributions are always welcome, whether it's modifying source code to add new
features or bug fixes, documenting new file formats or simply editing some
grammar.

## License
donut is released as open source software under the [GPL v3](https://opensource.org/licenses/gpl-3.0.html) 
license, see the [LICENSE.md](./LICENSE.md) file in the project root for the full license text.