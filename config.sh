rm -rf build
mkdir build
cd build
conan install ..
cmake -G "Visual Studio 15 2017 Win64" ..
