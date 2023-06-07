@echo off

echo.
echo Create build folder...
mkdir build

echo.
echo Running CMake...
cmake -G "MinGW Makefiles" -S . -B ./build

echo.
echo Build With mingw32-make
cd build
mingw32-make