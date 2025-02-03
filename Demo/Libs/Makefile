CXX := g++
CXXFLAGS := -Wall -Wextra -fPIC

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
SHARED_LIBS := $(patsubst $(SOURCE_DIR)/%.cpp, $(SHARED_DIR)/lib%.so, $(SOURCE_FILES))

CXXFLAGS += -I$(INCLUDE_DIR)

all: shared
.PHONY: shared clean log

shared: $(SHARED_LIBS)
$(SHARED_LIBS): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -shared $^ -o $@

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

log:
	@echo "------INFO------"
	@echo "Include directory: $(INCLUDE_DIR)"
	@echo "Include files: $(INCLUDE_FILES)"
	@echo "Source directory: $(SOURCE_DIR)"
	@echo "Source files: $(SOURCE_FILES)"
	@echo "Object directory: $(OBJ_DIR)"
	@echo "Object files: $(OBJ_FILES)"
	@echo "Shared libraries: $(SHARED_LIBS)"
	@echo "Executable: $(BUILD_DIR)/main"
	@echo "CXX: $(CXX)"
	@echo "CXXFLAGS: $(CXXFLAGS)"

clean:
	rm -rf $(BUILD_DIR)

$(shell mkdir -p $(OBJ_DIR) $(SHARED_DIR))