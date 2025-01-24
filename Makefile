# Compiler and flags
CXX = g++
CXXFLAGS = -I${LIB_INC} -Wall

# Directories and files
LIB_DIR = ./MathLib
LIB_INC = ${LIB_DIR}/include
SHARED_LIB = ${LIB_DIR}/build/shared/libmath.so
OUT_DIR = ./out

# Create directories 
$(shell mkdir -p $(OUT_DIR))

# Output files
PROGRAM = main
BUILD_STATIC = ${OUT_DIR}/${PROGRAM}
BUILD_SHARED = ${OUT_DIR}/${PROGRAM}

# Default
all: run

# Preprocessor
${OUT_DIR}/${PROGRAM}.i: ${PROGRAM}.cpp
	${CXX} ${CXXFLAGS} -E $< -o $@

# Compiler
${OUT_DIR}/${PROGRAM}.s: ${OUT_DIR}/${PROGRAM}.i
	${CXX} ${CXXFLAGS} -S $< -o $@

# Assembler
${OUT_DIR}/${PROGRAM}.o: ${OUT_DIR}/${PROGRAM}.s
	${CXX} ${CXXFLAGS} -c $< -o $@

# Linker
${BUILD_SHARED}: ${OUT_DIR}/${PROGRAM}.o
	${CXX} $< ${SHARED_LIB} -o $@

# Actions
.PHONY: clean run build_shared

clean: 
	rm -rf ${OUT_DIR}

build_shared: ${BUILD_SHARED}

run: ${BUILD_SHARED}
	${OUT_DIR}/${PROGRAM}
