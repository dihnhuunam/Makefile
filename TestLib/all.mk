# 1. Compiler and Flags
CXX := g++
CXXFLAGS := -Wall -Wextra
AR := ar
ARFLAGS := rcs

# 2. Directories and Files
# Base project directory
PRO_DIR := .

# Include directories and files
INCLUDE_DIR := $(PRO_DIR)/include
INCLUDE_FILES := $(wildcard $(INCLUDE_DIR)/*.h)

# Source directories and files
SOURCE_DIR := $(PRO_DIR)/source
SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp)

# Use vpath to specify locations of source and header files
vpath %.h $(INCLUDE_DIR)
vpath %.cpp $(SOURCE_DIR)

# Build directories for object and binary files
BUILD_DIR := $(PRO_DIR)/build

# Object directory and files
OBJ_DIR := $(BUILD_DIR)/obj
OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCE_FILES))

# Directories for static and shared libraries
STATIC_DIR := $(BUILD_DIR)/static
SHARED_DIR := $(BUILD_DIR)/shared

# Library files
STATIC_LIBS := $(patsubst $(SOURCE_DIR)/%.cpp, $(STATIC_DIR)/%.a, $(SOURCE_FILES))
SHARED_LIBS := $(patsubst $(SOURCE_DIR)/%.cpp, $(SHARED_DIR)/%.so, $(SOURCE_FILES))
	
# 3. Compilation Flags
# Add include directories to CXXFLAGS
CXXFLAGS += -I$(INCLUDE_DIR)

# 4. Default Target
.PHONY: all
all: static shared

# 5. Clean Build Files
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# 6. Build Static Library
.PHONY: static
static: $(STATIC_DIR)/mylib.a

$(STATIC_DIR)/mylib.a: $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $^

# 7. Build Shared Library
.PHONY: shared
shared: $(SHARED_DIR)/mylib.so

CXXFLAGS += -fPIC
$(SHARED_DIR)/mylib.so: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -shared $^ -o $@

# 8. Compile Object Files
$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 9. Display Build Information
.PHONY: log
log:
	@echo "------INFO------"
	@echo "Include directory: $(INCLUDE_DIR)"
	@echo "Include files: $(INCLUDE_FILES)" 
	@echo "Source directory: $(SOURCE_DIR)"
	@echo "Source files: $(SOURCE_FILES)"
	@echo "Object directory: $(OBJ_DIR)"
	@echo "Object files: $(OBJ_FILES)"
	@echo "Static libraries: $(STATIC_LIBS)"
	@echo "Shared libraries: $(SHARED_LIBS)"
	@echo "CXX: $(CXX)"
	@echo "CXXFLAGS: $(CXXFLAGS)"

# 10. Create Build Directories
# Ensure necessary build directories exist
$(shell mkdir -p $(OBJ_DIR) $(STATIC_DIR) $(SHARED_DIR))