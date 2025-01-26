# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -I$(INCLUDE_DIR) -fPIC
AR = ar
ARFLAGS = rcs

# Directories
INCLUDE_DIR = ./include
SRC_DIR = ./source
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj
STATIC_DIR = $(BUILD_DIR)/static
SHARED_DIR = $(BUILD_DIR)/shared

# Create build directories
$(shell mkdir -p $(BUILD_DIR) $(OBJ_DIR) $(STATIC_DIR) $(SHARED_DIR))

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Library files
STATIC_LIB = $(STATIC_DIR)/libmath.a
SHARED_LIB = $(SHARED_DIR)/libmath.so

# Default target
.PHONY: all
all: static shared info

# Static library
.PHONY: static
static: $(STATIC_LIB)

$(STATIC_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Shared library
.PHONY: shared
shared: $(SHARED_LIB)

$(SHARED_LIB): $(OBJS)
	$(CXX) $(CXXFLAGS) -shared $^ -o $@

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Additional information
.PHONY: info
info:
	@echo "------INFO------"
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"
	@echo "Static library: $(STATIC_LIB)"
	@echo "Shared library: $(SHARED_LIB)"

# Test library
.PHONY: test
TEST_DIR = ./test
TEST_BUILD = $(TEST_DIR)/build
TEST_OBJ = $(TEST_BUILD)/obj
TEST_BIN = $(TEST_BUILD)/bin
TEST_PRE = $(TEST_BUILD)/preprocess
TEST_ASM = $(TEST_BUILD)/asm
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_PRE_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_PRE)/%.i,$(TEST_SRCS))
TEST_ASM_FILES = $(patsubst $(TEST_PRE)/%.i,$(TEST_ASM)/%.s,$(TEST_PRE_FILES))
TEST_OBJS = $(patsubst $(TEST_ASM)/%.s,$(TEST_OBJ)/%.o,$(TEST_ASM_FILES))
TEST_BIN_FILE = $(TEST_BIN)/main

$(shell mkdir -p $(TEST_PRE) $(TEST_ASM) $(TEST_OBJ) $(TEST_BIN))

# Test target
test: $(TEST_BIN_FILE)
	$(TEST_BIN_FILE)

# Preprocess source files: (.cpp -> .i)
$(TEST_PRE)/%.i: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -E $< -o $@

# Generate assembly files: (.i -> .s)
$(TEST_ASM)/%.s: $(TEST_PRE)/%.i
	$(CXX) $(CXXFLAGS) -S $< -o $@

# Compile assembly files to object files: (.s -> .o)
$(TEST_OBJ)/%.o: $(TEST_ASM)/%.s
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to binary: (.o -> binary)
$(TEST_BIN_FILE): $(TEST_OBJS) $(STATIC_LIB)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean test build
.PHONY: clean-test
clean-test:
	rm -rf $(TEST_BUILD)/obj $(TEST_BUILD)/bin

# Clean all builds
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEST_BUILD)
