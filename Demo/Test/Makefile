CXX := g++

PRO_DIR := .

INCLUDE_DIR := $(PRO_DIR)/includes
INCLUDE_FILES := $(wildcard $(INCLUDE_DIR)/*.h)
CXXFLAGS += -I$(INCLUDE_DIR)

SOURCE_DIR := $(PRO_DIR)/sources
SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp)

vpath %.h $(INCLUDE_DIR)
vpath %.cpp $(SOURCE_DIR)

BUILD_DIR := $(PRO_DIR)/build
OBJ_DIR := $(BUILD_DIR)/obj
OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCE_FILES))

LIB_DIR := ../Libs
SHARED_DIR := $(LIB_DIR)/build/shared
SHARED_LIBS := $(wildcard $(SHARED_DIR)/*.so)
LDFLAGS := -Wl,-rpath=$(SHARED_DIR)
	
.PHONY: build link clean log

build: $(OBJ_DIR)/main.o
$(OBJ_DIR)/main.o: $(SOURCE_DIR)/main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

link: $(OBJ_DIR)/main.o 
	mkdir -p $(BUILD_DIR)
	$(CXX) $^ -L$(SHARED_DIR) $(LDFLAGS) $(addprefix -l:,$(notdir $(SHARED_LIBS))) -o $(BUILD_DIR)/main

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