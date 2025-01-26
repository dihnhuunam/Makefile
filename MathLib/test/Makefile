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
STATIC_LIBS = ${wildcard ${STATIC_DIR}/*.a}
SHARED_LIBS = ${wildcard ${SHARED_DIR}/*.o}

# Test library
TEST_DIR = .
TEST_BUILD = $(TEST_DIR)/build
TEST_OBJ = $(TEST_BUILD)/obj
TEST_BIN = $(TEST_BUILD)/bin
TEST_PRE = $(TEST_BUILD)/preprocess
TEST_ASM = $(TEST_BUILD)/asm

# Compilation C/C++ files 
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_PRE_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_PRE)/%.i,$(TEST_SRCS))
TEST_ASM_FILES = $(patsubst $(TEST_PRE)/%.i,$(TEST_ASM)/%.s,$(TEST_PRE_FILES))
TEST_OBJS = $(patsubst $(TEST_ASM)/%.s,$(TEST_OBJ)/%.o,$(TEST_ASM_FILES))
TEST_BIN_FILE = $(TEST_BIN)/main

$(shell mkdir -p $(TEST_PRE) $(TEST_ASM) $(TEST_OBJ) $(TEST_BIN))

.PRECIOUS: $(TEST_PRE)/%.i $(TEST_ASM)/%.s

# Test
.PHONY: test
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
$(TEST_BIN_FILE): $(TEST_OBJS) $(STATIC_LIBS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean test build
.PHONY: clean
clean:
	rm -rf $(TEST_BUILD)