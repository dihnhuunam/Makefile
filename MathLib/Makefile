# Compiler and flags
CXX = g++
CXXFLAGS = -I$(INCLUDE_DIR) -Wall

# Directories and files
INCLUDE_DIR = ./include
SRC_DIR = ./source
BUILD_DIR = ./build
OBJ_DIR = ${BUILD_DIR}/obj
STATIC_DIR = ${BUILD_DIR}/static
SHARED_DIR = ${BUILD_DIR}/shared

# Create build directory
$(shell mkdir -p $(BUILD_DIR) $(OBJ_DIR) $(STATIC_DIR) $(SHARED_DIR))

# Library files
STATIC_LIB = $(STATIC_DIR)/libmath.a
SHARED_LIB = ${SHARED_DIR}/libmath.so

# Object files
MATH_OBJ = $(OBJ_DIR)/math_ultis.o

# Build static library
$(STATIC_LIB): $(MATH_OBJ)
	ar rcs $@ $^

# Build shared library
${SHARED_LIB}: $(MATH_OBJ)
	$(CXX) $(CXXFLAGS) -shared $< -o $@

# Compile source files
$(MATH_OBJ): $(SRC_DIR)/math_ultis.cpp $(INCLUDE_DIR)/math_ultis.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Actions
.PHONY: clean shared static

all: $(STATIC_LIB) $(SHARED_LIB)

clean:
	rm -rf $(BUILD_DIR)

shared: ${SHARED_LIB}

static: ${STATIC_LIB}