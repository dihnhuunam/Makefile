CXX := g++
CXXFLAGS += -Wall -Wextra -I./includes

PRO_DIR := .

SOURCE_DIR := $(PRO_DIR)/sources
SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp)

BUILD_DIR := $(PRO_DIR)/build
PROGRAM := $(BUILD_DIR)/main
OBJ_DIR := $(BUILD_DIR)/obj
OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCE_FILES))

LIB_DIR := ../Libs/build
SHARED_DIR := $(LIB_DIR)/shared
SHARED_FILES := $(notdir $(wildcard $(SHARED_DIR)/lib*.so))
STATIC_DIR := $(LIB_DIR)/static
STATIC_FILES := $(notdir $(wildcard $(STATIC_DIR)/lib*.a))

all: shared
.PHONY: all

SHARED_FLAGS := -Wl,-rpath=$(SHARED_DIR) $(patsubst lib%.so,-l%,$(SHARED_FILES))
shared: $(OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	$(CXX) $^ -L$(SHARED_DIR) $(SHARED_FLAGS) -o $(PROGRAM)
.PHONY: shared

STATIC_FLAGS :=$(patsubst lib%.so,-l%,$(SHARED_FILES))
static: $(OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	$(CXX) $^ -L$(STATIC_DIR) $(STATIC_FLAGS) -o $(PROGRAM)
.PHONY: static

build: $(OBJ_FILES)
$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
.SECONDARY: $(OBJ_FILES)
.PHONY: build

log:
	@echo "------------------------------------INFO------------------------------------"
	@echo "Source directory: $(SOURCE_DIR)"
	@echo "Source files: $(SOURCE_FILES)"
	@echo "Object directory: $(OBJ_DIR)"
	@echo "Object files: $(OBJ_FILES)"
	@echo "Shared directory: $(SHARED_DIR)"
	@echo "Shared libraries: $(SHARED_FILES)"
	@echo "Static directory: $(STATIC_DIR)"
	@echo "Static libraries: $(STATIC_FILES)"
	@echo "Executable: $(BUILD_DIR)/main"
	@echo "CXX: $(CXX)"
	@echo "CXXFLAGS: $(CXXFLAGS)"
	@echo "SHARED_FLAGS: $(SHARED_FLAGS)"
	@echo "STATIC_FLAGS: $(STATIC_FLAGS)"
.PHONY: log

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean