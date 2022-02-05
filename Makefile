SHELL=/bin/bash

.PHONY: clean
clean:
	ninja -C build clean

.PHONY: clean-make
clean-make:
	make -C build clean

.PHONY: clean-all
clean-all:
	rm -r build

.PHONY: format
format:
	clang-format -i src/**/*.cpp src/**/*.h

.PHONY: cmake
cmake:
	@cmake \
		-G Ninja \
		-B build \
		-DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake

.PHONY: build
build:
	@cmake \
        -G Ninja \
        -B build \
        -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake
	@ninja -C build;

.PHONY: build-make
build-make:
	@cmake \
        -G "Unix Makefiles" \
        -B build \
        -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake
	@make -C build;

.PHONY: test
test:
	@make build
	@./build/test

.PHONY: test-make
test-make:
	@make build-make
	@./build/test

.PHONY: install
install:
	@make build
	@ninja -C build install

.PHONY: install-make
install-make:
	@make build-make
	@make -C build install