# SimpleLib

This is a simple library that calculates fibonacci numbers.

# Build

## Windows

Install Visual Studio 2019 and run the x64 Native Tools Command Prompt for VS 2019 which is installed with it.

To ensure the compiling will work with 64 bit systems, run the following command (may need to look it up if your path differs):
```
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
```

Compile the library into an object file:
```
cl /c /EHsc fiblib.cpp
```

Turn the object file into a .lib:
```
lib fiblib.obj
```

Compile the program with the library:
```
cl /EHsc main.cpp fiblib.lib
```

## Mac

Install XCode and ensure that `clang++` is in your path.

Compile the library into a shared object:
```
clang++ -shared fiblib.cpp -o fiblib.so
```

Compile the program with the library:
```
clang++ main.cpp fiblib.so -o main
```
