# 1. Compiler and Flags
CXX := g++
CXXFLAGS := -Wall -Wextra

# 2. Library directories and files
LIB_DIR := ..

# Static library
STATIC_DIR := $(LIB_DIR)/build/static
STATIC_FILES := $(wildcard $(STATIC_DIR)/*.a)

# Shared library
SHARED_DIR := $(LIB_DIR)/build/shared
SHARED_FILES := $(wildcard $(SHARED_DIR)/*.so)

# 3. Base directories and files
TEST_DIR := .

# Include directories and files
INCLUDE_DIRS := $(TEST_DIR)/include $(LIB_DIR)/include
INCLUDE_FILES := $(foreach INCLUDE_DIR, $(INCLUDE_DIRS), $(wildcard $(INCLUDE_DIR)/*.h))

# Source directories and files
SOURCE_DIR := $(TEST_DIR)/source
SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp) 

# Use vpath to specify locations of source and header files
vpath %.h $(INCLUDE_DIRS)
vpath %.cpp $(SOURCE_DIR)

# Build directories for object and binary files
BUILD_DIR := $(TEST_DIR)/build

# Object directory and files
OBJ_DIR := $(BUILD_DIR)/obj
OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCE_FILES))

# Binary directory and execatable file
BIN_DIR := $(BUILD_DIR)/run
TARGET := $(BIN_DIR)/test

# 4. Flags for Compilation
# Add include directories to CXXFLAGS
CXXFLAGS += $(foreach INCLUDE_DIR, $(INCLUDE_DIRS), -I$(INCLUDE_DIR))

# 5. Targets
# The default target (entry point)
all: build

# Build the executable from object files and static libraries
.PHONY: build
build: $(TARGET)

$(TARGET): $(OBJ_FILES) $(STATIC_FILES) 
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 6. Additional Commands
# Run the program after building
.PHONY: run
run: build
	$(TARGET)

# Display useful information about the build
.PHONY: log
log:
	@echo "------INFO------"
	@echo "Include directories: $(INCLUDE_DIRS)"
	@echo "Include files: $(INCLUDE_FILES)" 
	@echo "Source directory: $(SOURCE_DIR)"
	@echo "Source files: $(SOURCE_FILES)"
	@echo "Object directory: $(OBJ_DIR)"
	@echo "Object files: $(OBJ_FILES)"
	@echo "Static libraries: $(STATIC_FILES)"
	@echo "Shared libraries: $(SHARED_FILES)"
	@echo "CXX: $(CXX)"
	@echo "CXXFLAGS: $(CXXFLAGS)"

# Clean up the build directory
.PHONY: clean
clean: 
	rm -rf $(BUILD_DIR)

# 7. Create necessary directories
# Create the necessary build directories (objects and binaries)
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))
