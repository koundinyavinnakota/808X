# Valgrind Excercise
- This program is to understand the functionality of Valgrind


## Dependencies
- C++ 
- CMake
- googletest
- lcov
- cpplint
- cppcheck
## Steps to run the project
```
cd <project_directory>
mkdir build
cd build
cmake ..
make
Run program: ./app/Checker
```
## Steps to run the Valgrind
```
cd <project_directory>
mkdir build
cd build
cmake ..
make
Run program: valgrind ./app/Checker
```
