CXX := g++
CXXFLAGS := -Wall -Wextra -fPIC
AR := ar
ARFLAGS := rcs 

PRO_DIR := .

INCLUDE_DIR := $(PRO_DIR)/includes
INCLUDE_FILES := $(wildcard $(INCLUDE_DIR)/*.h)

SOURCE_DIR := $(PRO_DIR)/sources
SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp)

vpath %.h $(INCLUDE_DIR)
vpath %.cpp $(SOURCE_DIR)

BUILD_DIR := $(PRO_DIR)/build
OBJ_DIR := $(BUILD_DIR)/obj
OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCE_FILES))

SHARED_DIR := $(BUILD_DIR)/shared
STATIC_DIR := $(BUILD_DIR)/static
SHARED_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(SHARED_DIR)/lib%.so, $(SOURCE_FILES))
STATIC_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(STATIC_DIR)/lib%.a, $(SOURCE_FILES))

CXXFLAGS += -I$(INCLUDE_DIR)

all: shared static
.PHONY: shared clean log

shared: $(SHARED_FILES)
$(SHARED_DIR)/lib%.so: $(OBJ_DIR)/%.o
	$(CXX) $(CXXFLAGS) -shared $^ -o $@

static: $(STATIC_FILES)
$(STATIC_DIR)/lib%.a: $(OBJ_DIR)/%.o
	$(AR) $(ARFLAGS) $@ $^ 

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.SECONDARY: $(OBJ_FILES)

log:
	@echo "------INFO------"
	@echo "Include directory: $(INCLUDE_DIR)"
	@echo "Include files: $(INCLUDE_FILES)"
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

$(shell mkdir -p $(OBJ_DIR) $(SHARED_DIR) $(STATIC_DIR))