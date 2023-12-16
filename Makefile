# Default is x86_64
.PHONY: default
default: build

cpp_source_files := $(shell find src -name *.cpp)
h_source_files := $(shell find src -name *.h)
cpp_object_files := $(patsubst src/%.cpp, build/%.o, $(cpp_source_files))

CPP_INCLUDE_PATH := include

OUT_NAME := GroMath

LLVM_INCLUDE := `llvm-config --cxxflags`
LLVM_LIBS := `llvm-config --cxxflags --ldflags --system-libs --libs core orcjit native` -rdynamic
OPTS := -std=c++20 -march=znver3 -g -O3

CC := clang++

$(cpp_object_files): build/%.o : src/%.cpp
	@echo $(patsubst build/%.o, src/%.cpp, $@)
	@mkdir -p $(dir $@) && \
	$(CC) $(OPTS) -c -Wall -I $(CPP_INCLUDE_PATH) $(patsubst build/%.o, src/%.cpp, $@) -o $@ $(LLVM_INCLUDE)

.PHONY: build
build: $(cpp_object_files)
# @echo "[CPP Files] :"
# @echo $(cpp_source_files)
# @echo "[CPP OBJ Files] :"
# @echo $(cpp_object_files)
	@$(CC) $(OPTS) -Wall -o $(OUT_NAME) $(cpp_object_files) $(LLVM_LIBS)
	@echo "DONE"

CLEAN:
	@rm -rfv build/
	@mkdir build
	@echo "CLEAN"