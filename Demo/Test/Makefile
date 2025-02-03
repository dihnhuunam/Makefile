# CXX := g++

# PRO_DIR := .

# INCLUDE_DIR := $(PRO_DIR)/includes
# INCLUDE_FILES := $(wildcard $(INCLUDE_DIR)/*.h)
# CXXFLAGS += -I$(INCLUDE_DIR) 

# SOURCE_DIR := $(PRO_DIR)/sources
# SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp)

# vpath %.h $(INCLUDE_DIR)
# vpath %.cpp $(SOURCE_DIR)

# BUILD_DIR := $(PRO_DIR)/build
# OBJ_DIR := $(BUILD_DIR)/obj
# OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCE_FILES))

# LIB_DIR := ../Libs
# SHARED_DIR := $(LIB_DIR)/build/shared
# LIB_CALCULATE := calculate
# LIB_DISPLAY := display
# LDFLAGS := -Wl,-rpath=$(SHARED_DIR) -l$(LIB_CALCULATE) -l$(LIB_DISPLAY)
	
# .PHONY: build shared static clean log

# build: $(OBJ_DIR)/main.o
# $(OBJ_DIR)/main.o: $(SOURCE_DIR)/main.cpp | $(OBJ_DIR)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)

# shared: $(OBJ_DIR)/main.o | $(BUILD_DIR)
# 	$(CXX) $^ -L$(SHARED_DIR) $(LDFLAGS) -o $(BUILD_DIR)/main

# static: $(OBJ_DIR)/main.o | $(BUILD_DIR)
# 	$(CXX) $^ -L$(SHARED_DIR) $(LDFLAGS) -o $(BUILD_DIR)/main

# $(BUILD_DIR):
# 	mkdir -p $(BUILD_DIR)

# log:
# 	@echo "------INFO------"
# 	@echo "Include directory: $(INCLUDE_DIR)"
# 	@echo "Include files: $(INCLUDE_FILES)"
# 	@echo "Source directory: $(SOURCE_DIR)"
# 	@echo "Source files: $(SOURCE_FILES)"
# 	@echo "Object directory: $(OBJ_DIR)"
# 	@echo "Object files: $(OBJ_FILES)"
# 	@echo "Shared libraries: $(SHARED_LIBS)"
# 	@echo "Executable: $(BUILD_DIR)/main"
# 	@echo "CXX: $(CXX)"
# 	@echo "CXXFLAGS: $(CXXFLAGS)"
# 	@echo "LDDFLAGS: $(LDFLAGS)"

# clean:
# 	rm -rf $(BUILD_DIR)

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

# Tự động lấy danh sách thư viện
SHARED_LIBS := $(notdir $(wildcard $(SHARED_DIR)/lib*.so))
LDFLAGS := -Wl,-rpath=$(SHARED_DIR) $(patsubst lib%.so,-l%,$(SHARED_LIBS))

.PHONY: build shared static clean log

build: $(OBJ_DIR)/main.o
$(OBJ_DIR)/main.o: $(SOURCE_DIR)/main.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

shared: $(OBJ_DIR)/main.o | $(BUILD_DIR)
	$(CXX) $^ -L$(SHARED_DIR) $(LDFLAGS) -o $(BUILD_DIR)/main

static: $(OBJ_DIR)/main.o | $(BUILD_DIR)
	$(CXX) $^ -L$(SHARED_DIR) $(LDFLAGS) -o $(BUILD_DIR)/main

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

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
	@echo "LDFLAGS: $(LDFLAGS)"

clean:
	rm -rf $(BUILD_DIR)
