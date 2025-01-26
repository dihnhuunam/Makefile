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

# Clean all builds
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

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