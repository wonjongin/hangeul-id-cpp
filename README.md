# Hangeul ID C++

Unique shorter id using Hangeul inspired by Hashids

## About Hangeul

A character of Hangeul has 2 or 3 subcharacter. For example, subcharacters of `글` are `ㄱ`, `ㅡ`, `ㄹ` and subcharacters
of `나` are `ㄴ`, `ㅏ`. First subcharacter called consonant can be `ㄱ ㄲ ㄴ ㄷ ㄸ ㄹ ㅁ ㅂ ㅃ ㅅ ㅆ ㅇ ㅈ ㅉ ㅊ ㅋ ㅌ ㅍ ㅎ(19)`, second
subcharacter called vowel can be `ㅏ ㅐ ㅑ ㅒ ㅓ ㅔ ㅕ ㅖ ㅗ ㅘ ㅙ ㅚ ㅛ ㅜ ㅝ ㅞ ㅟ ㅠ ㅡ ㅢ ㅣ (21)`, and last subcharacter called final
consonant can be `(null) ㄱ ㄲ ㄳ ㄴ ㄵ ㄶ ㄷ ㄹ ㄺ ㄻ ㄼ ㄽ ㄾ ㄿ ㅀ ㅁ ㅂ ㅄ ㅅ ㅆ ㅇ ㅈ ㅊ ㅋ ㅌ ㅍ ㅎ (28)`. Last subcharacter is optional. So
the number of cases of Hangeul one character is `19*21*28 = 11172`. It is very many cases. It is hard to contol Hangeul
and make font glyphs. So 2350 characters frequently used were selected as KS X 1001. Most of Korean fonts support
characters of KS X 1001. And Unicode has all characters of Hangeul (U+AC00 ~ U+D7A3).

## Features

- Generate Hangeul id from decimal integer.
- Generate Hangeul id with UUID v4.

## Pre-Built

1. Download include.zip and library file on [release](https://github.com/wonjongin/hangeul-id-cpp/releases).
2. Remove platform name from library file name and unzip include.zip
3. Install include folder and library file. (e.g. /usr/local/include and /usr/local/lib)

## Setup with vcpkg

### Pre-requirement

- [cmake](https://cmake.org)
- c++ compiler (like clang, gcc)
- [make](https://www.gnu.org/software/make/) or [ninja](https://github.com/ninja-build/ninja)
- [vcpkg](https://github.com/microsoft/vcpkg) (optional)

### Building

1. We manage dependencies with [vcpkg](https://github.com/microsoft/vcpkg). Please set up vcpkg.
2. Clone this project and go to project directory.
3. `vcpkg install` to install dependencies with vcpkg
4. `export VCPKG_ROOT=/path/to/vcpkg`
5. Ninja -> 5.i, Make -> 5.ii

    1. Ninja
        ```shell
       cmake \
       -G Ninja \
       -B build \
       -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake 
       
       ninja -C build
       
       # Administer permission may be required.
       ninja -C build install 
       ```
    2. Make
       ```shell
       cmake \
       -G "Unix Makefiles" \
       -B build \
       -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake 
       
       make -C build
       
       # Administer permission may be required.
       make -C build install 
       ```

## Usage

- main.cpp

```c++
#include <hangeul_id/HangeulId.h>

int main() {
    HangeulId id;
    std::cout << id.integer_to_hangel_id(31415926535) << std::endl;
    // "간붇즘믄" will be printed.
    return 0;
}
```

- Add lines in CMakeLists.txt

```cmake
find_library(HANGEUL_ID_LIB_PATH libhangeul-id.a)
find_path(HANGEUL_ID_INCLUDE_DIR NAMES hangeul_id/HangeulId.h)
add_executable(main main.cpp)

target_include_directories(main PRIVATE ${HANGEUL_ID_INCLUDE_DIR})
target_link_libraries(main PRIVATE ${HANGEUL_ID_LIB_PATH})
```
