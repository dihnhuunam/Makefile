# Project Build System

This project uses a Makefile to compile C++ source files into both static and shared libraries. The build system automatically organizes source files, include files, and build artifacts into structured directories.

## 1. Directory Structure

```
MathLib/
│── include/                # Header files (*.h)
│── source/                 # Source files (*.cpp)
│── build/                  # Build output directory
│   ├── obj/                # Compiled object files (*.o)
│   ├── static/             # Static library (*.a)
│   ├── shared/             # Shared library (*.so)
│── test/                   # Test directory
│   ├── build/              # Test build directory
│   │   ├── obj/            # Compiled object files
│   │   ├── bin/            # Final test executable
│   │   ├── preprocess/     # Preprocessed source files (.i files)
│   │   ├── asm/            # Assembly files (.s files)
│   ├── Makefile            # Build system configuration for tests
│   ├── main.cpp            # Test source files
│── Makefile                # Build system configuration for the library
```

## 2. Build Targets

The Makefile defines several targets for compiling and cleaning the project:

- **`all`**: Builds both static and shared libraries.
- **`static`**: Compiles the static library (`libmath.a`).
- **`shared`**: Compiles the shared library (`libmath.so`).
- **`clean`**: Removes all compiled files and build directories.
- **`log`**: Displays information about the source files, object files, and generated libraries.

### Test Build System

A separate Makefile is included in the `test/` directory for building and running test executables:

- **`build`**: Builds the test executable.
- **`run`**: Runs the test executable.
- **`clean`**: Removes test build artifacts.
- **`log`**: Displays test build information.

## 3. Compilation Flags

- `-Wall -Wextra`: Enables compiler warnings for better code quality.
- `-fPIC`: Generates position-independent code for shared libraries.
- `-Iinclude/`: Adds the `include/` directory to the compiler's search path.

## 4. Usage

To build the project, run:
```sh
make
```

To build only the static library:
```sh
make static
```

To build only the shared library:
```sh
make shared
```

To clean all build artifacts:
```sh
make clean
```

To log the build details:
```sh
make log
```

To build and run tests:
```sh
cd test && make run
```

## 5. Notes

- The Makefile automatically detects all `.cpp` files in `source/` and `.h` files in `include/`.
- Ensure that the `include/` directory contains all necessary header files.
- The generated libraries are stored in `build/static/` and `build/shared/`.

## 6. License

This project is licensed under the MIT License.

