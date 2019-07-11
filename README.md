# donut

simsons hit and run engine

# building

clone using: `git clone --recursive https://github.com/plowteam/donut.git`
or if using desktop client make sure you do: `git submodule update --init --recursive`

## windows

* download [vs2019](https://visualstudio.microsoft.com/downloads/) (vs2017 or higher is fine)
* download [cmake](https://cmake.org/download/)
* open cmake gui and point it to `donut` folder, then set build directory to `donut/build`, press configure & generate
* open project in vs2019 and build

## linux

```bash
apt install build-essential libsdl2-dev cmake libglm-dev
mkdir build && cd build
cmake ../
make
```