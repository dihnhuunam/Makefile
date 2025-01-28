# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -I$(INCLUDE_DIR)

# Directories
INCLUDE_DIR = ../include
BUILD_DIR = ../build
OBJ_DIR = $(BUILD_DIR)/obj
STATIC_DIR = $(BUILD_DIR)/static
SHARED_DIR = $(BUILD_DIR)/shared

# Static and shared libraries
STATIC_LIBS = $(wildcard $(STATIC_DIR)/*.a)
SHARED_LIBS = $(wildcard $(SHARED_DIR)/*.o)

# Test library
TEST_DIR = .
TEST_BUILD = $(TEST_DIR)/build
TEST_OBJ = $(TEST_BUILD)/obj
TEST_BIN = $(TEST_BUILD)/bin
TEST_PRE = $(TEST_BUILD)/preprocess
TEST_ASM = $(TEST_BUILD)/asm

# Source, preprocess, assembly, object, and binary files
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_PRE_FILES = $(patsubst $(TEST_DIR)/%.cpp, $(TEST_PRE)/%.i, $(TEST_SRCS))
TEST_ASM_FILES = $(patsubst $(TEST_PRE)/%.i, $(TEST_ASM)/%.s, $(TEST_PRE_FILES))
TEST_OBJS = $(patsubst $(TEST_ASM)/%.s, $(TEST_OBJ)/%.o, $(TEST_ASM_FILES))
TEST_BIN_FILE = $(TEST_BIN)/main

# Create necessary directories
$(shell mkdir -p $(TEST_PRE) $(TEST_ASM) $(TEST_OBJ) $(TEST_BIN))

.PRECIOUS: $(TEST_PRE)/%.i $(TEST_ASM)/%.s $(TEST_OBJ)/%.o

# Test target
.PHONY: test build clean build1 build2 build3 build4
all: test

test: build
	$(TEST_BIN_FILE)

# Build all stages
build: build4

# Stage 1: Preprocess source files (.cpp -> .i)
build1: $(TEST_PRE_FILES)

$(TEST_PRE)/%.i: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -E $< -o $@

# Stage 2: Generate assembly files (.i -> .s)
build2: $(TEST_ASM_FILES)

$(TEST_ASM)/%.s: $(TEST_PRE)/%.i
	$(CXX) $(CXXFLAGS) -S $< -o $@

# Stage 3: Compile assembly files to object files (.s -> .o)
build3: $(TEST_OBJS)

$(TEST_OBJ)/%.o: $(TEST_ASM)/%.s
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Stage 4: Link object files to binary (.o -> binary)
build4: $(TEST_BIN_FILE)

$(TEST_BIN_FILE): $(TEST_OBJS) $(STATIC_LIBS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean build directories
clean:
	rm -rf $(TEST_BUILD)
