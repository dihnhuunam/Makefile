CXX := g++
CXXFLAGS := -Wall -Wextra -fPIC -I./includes
AR := ar
ARFLAGS := rcs 

PRO_DIR := .

SOURCE_DIR := $(PRO_DIR)/sources
SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp)

BUILD_DIR := $(PRO_DIR)/build
OBJ_DIR := $(BUILD_DIR)/obj
OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCE_FILES))

SHARED_DIR := $(BUILD_DIR)/shared
SHARED_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(SHARED_DIR)/lib%.so, $(SOURCE_FILES))
STATIC_DIR := $(BUILD_DIR)/static
STATIC_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(STATIC_DIR)/lib%.a, $(SOURCE_FILES))

all: shared static
.PHONY : all

shared: $(SHARED_FILES)
$(SHARED_DIR)/lib%.so: $(OBJ_DIR)/%.o
	mkdir -p $(SHARED_DIR)
	$(CXX) $(CXXFLAGS) -shared $^ -o $@
.PHONY: shared 

static: $(STATIC_FILES)
$(STATIC_DIR)/lib%.a: $(OBJ_DIR)/%.o
	mkdir -p $(STATIC_DIR)
	$(AR) $(ARFLAGS) $@ $^ 
.PHONY: static

build: $(OBJ_FILES)
$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
.SECONDARY: $(OBJ_FILES)
.PHONY: build

log:
	@echo "------INFO------"
	@echo "Source directory: $(SOURCE_DIR)"
	@echo "Source files: $(SOURCE_FILES)"
	@echo "Object directory: $(OBJ_DIR)"
	@echo "Object files: $(OBJ_FILES)"
	@echo "Shared libraries: $(SHARED_FILES)"
	@echo "Static libraries: $(STATIC_FILES)"
	@echo "Executable: $(BUILD_DIR)/main"
	@echo "CXX: $(CXX)"
	@echo "CXXFLAGS: $(CXXFLAGS)"

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean