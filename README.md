# Build System for Math Library and Test Framework

This project contains a build system for compiling a static and shared math library, along with a test framework to verify functionality. The Makefile provided automates the compilation, archiving, organization, and testing processes.

## Directory Structure

```
.
├── include             # Header files directory
├── source              # Source files directory
├── build               # Build directory
│   ├── obj             # Object files for the main library
│   ├── static          # Static library (.a files)
│   └── shared          # Shared library (.so files)
├── test                # Test directory
│   ├── build           # Test build directory
│   │   ├── obj         # Compiled object files
│   │   ├── bin         # Final test executable
│   │   ├── preprocess  # Preprocessed source files (.i files)
│   │   └── asm         # Assembly files (.s files)
│   ├── Makefile        # Build system configuration for tests
│   └── *.cpp           # Test source files
└── Makefile            # Build system configuration for the library
```

## Build Targets

### Library Makefile Targets

#### `all`

Builds both the static and shared libraries and displays additional build information.

#### `static`

Compiles the object files and archives them into a static library (`libmath.a`).

#### `shared`

Compiles the object files and links them into a shared library (`libmath.so`).

#### `clean`

Removes all generated files and directories under the `build/` directory.

#### `info`

Displays information about the source files, object files, and generated libraries.

### Test Makefile Targets

#### `test`

Compiles, links, and runs the test executable.

#### `clean`

Cleans the test build directory by removing all generated files.

## Build Process

### Library Build Process

#### 1. Compile Object Files

Source files (`.cpp`) in `source/` are compiled into object files in `build/obj/`:

```bash
g++ -Wall -Wextra -I./include -fPIC -c source/math_utils.cpp -o build/obj/math_utils.o
```

#### 2. Create Static Library

Object files are archived into `libmath.a` in the `build/static` directory using `ar`:

```bash
ar rcs build/static/libmath.a build/obj/math_utils.o
```

#### 3. Create Shared Library

Object files are linked into `libmath.so` in the `build/shared` directory:

```bash
g++ -Wall -Wextra -I./include -fPIC -shared build/obj/math_utils.o -o build/shared/libmath.so
```

### Test Build Process

#### 1. Preprocessing

Test source files (`.cpp`) are preprocessed into `.i` files:

```bash
g++ -Wall -Wextra -I../include -E test/math_utils.cpp -o test/build/preprocess/math_utils.i
```

#### 2. Assembly

Preprocessed files (`.i`) are converted to assembly files (`.s`):

```bash
g++ -Wall -Wextra -I../include -S test/build/preprocess/math_utils.i -o test/build/asm/math_utils.s
```

#### 3. Object Files

Assembly files (`.s`) are compiled into object files (`.o`):

```bash
g++ -Wall -Wextra -I../include -c test/build/asm/math_utils.s -o test/build/obj/math_utils.o
```

#### 4. Linking

Object files (`.o`) and any static libraries are linked into an executable:

```bash
g++ -Wall -Wextra test/build/obj/math_utils.o ../build/static/libmath.a -o test/build/bin/main
```

#### 5. Execution

The resulting binary is executed when the `test` target is invoked.

## Usage

### Library Usage

#### Build All

Run the following command to build both the static and shared libraries:

```bash
make
```

#### Build Static Library Only

```bash
make static
```

#### Build Shared Library Only

```bash
make shared
```

#### Clean Build Artifacts

```bash
make clean
```

#### Display Build Information

```bash
make info
```

### Test Usage

#### Run Tests

To build and execute the tests:

```bash
make test
```

#### Clean Test Build Artifacts

To clean up all generated files:

```bash
make clean
```

## Example Output

After building the project, the directory structure will look like this:

```
.
├── include             # Header files
├── source              # Source files
├── build               # Build directory
│   ├── obj             # Object files
│   ├── static          # Static library
│   │   └── libmath.a
│   └── shared          # Shared library
│       └── libmath.so
├── test                # Test directory
│   ├── build           # Test build directory
│   │   ├── obj         # Compiled object files
│   │   ├── bin         # Final test executable
│   │   ├── preprocess  # Preprocessed source files
│   │   └── asm         # Assembly files
│   ├── Makefile        # Test build system
│   └── main.cpp           # Test source files
└── Makefile            # Main build system
```

## Notes

- Ensure all `.cpp` and `.h` files are correctly placed in the `source/` and `include/` directories, respectively.
- Test source files (`*.cpp`) must be located in the `test/` directory.
- Static libraries (`*.a`) and shared libraries (`*.o`) should be present in `build/static/` and `build/shared/` respectively.

## License

This project is open-source and can be used, modified, and distributed freely.
