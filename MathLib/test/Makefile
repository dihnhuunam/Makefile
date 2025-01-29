# 1. Compiler and Flags
CXX := g++
CXXFLAGS := -Wall -Wextra

# 2. Directories and Files
# Base project and library directories
PRO_DIR := .
LIB_DIR := ..

# Library directories and files
LIB_STATIC := $(LIB_DIR)/build/static
LIB_SHARED := $(LIB_DIR)/build/shared
STATIC_FILES := $(wildcard $(LIB_STATIC)/*.a)
SHARED_FILES := $(wildcard $(LIB_SHARED)/*.so)

# Source and include directories
SOURCE_DIRS := $(PRO_DIR)/source
INCLUDE_DIRS := $(PRO_DIR)/include $(LIB_DIR)/include

# Build directories for object and binary files
BUILD_DIR := $(PRO_DIR)/build
OBJ_DIR := $(BUILD_DIR)/obj
BIN_DIR := $(BUILD_DIR)/run

# Executable target
TARGET := $(BIN_DIR)/test

# 3. File Identification
# Use vpath to specify locations of source and header files
vpath %.h $(INCLUDE_DIRS)
vpath %.cpp $(SOURCE_DIRS)

# Identify header files and source files
INCLUDE_FILES := $(foreach INCLUDE_DIR, $(INCLUDE_DIRS), $(wildcard $(INCLUDE_DIR)/*.h))
SOURCE_FILES := $(foreach SOURCE_DIR, $(SOURCE_DIRS), $(wildcard $(SOURCE_DIR)/*.cpp))

# Generate object files corresponding to source files
OBJ_FILES := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SOURCE_FILES)))

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
$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# 6. Additional Commands
# Run the program after building
.PHONY: run
run: build
	$(TARGET)

# Display useful information about the build
.PHONY: log
log:
	@echo "Include files: $(INCLUDE_FILES)" 
	@echo "Source files: $(SOURCE_FILES)"
	@echo "Object files: $(OBJ_FILES)"
	@echo "CXX: $(CXX)"
	@echo "CXXFLAGS: $(CXXFLAGS)"

# Clean up the build directory
.PHONY: clean
clean: 
	rm -rf $(BUILD_DIR)

# 7. Create necessary directories
# Create the necessary build directories (objects and binaries)
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))
