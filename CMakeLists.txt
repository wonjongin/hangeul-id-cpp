cmake_minimum_required(VERSION 3.21)
project(hangeul-id VERSION 0.1.1 DESCRIPTION "Unique id using hangeul" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE HEADER_FILES "src/*.h")
file(GLOB_RECURSE CODE_FILES "src/*.cpp")
list(FILTER CODE_FILES EXCLUDE REGEX ".*\\.UnitTest\\.cpp")
list(FILTER CODE_FILES EXCLUDE REGEX "src/main.cpp")
#list(REMOVE_ITEM CODE_FILES "src/*.UnitTest.cpp")
file(GLOB_RECURSE TEST_FILES "src/*.UnitTest.cpp")
file(REMOVE_RECURSE "include")
file(MAKE_DIRECTORY "include")
foreach(ITEM ${HEADER_FILES})
    get_filename_component(FILENAME ${ITEM} NAME)
    string(REPLACE ${CMAKE_CURRENT_SOURCE_DIR}/src/ "" FILEPATH ${ITEM})
    message("src/${FILEPATH} -> include/${FILEPATH}")
    string(REPLACE ${FILENAME} "" FILEDIR ${FILEPATH})
    file(COPY ${ITEM} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/${FILEDIR})
endforeach()

find_package(Boost REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
add_library(hangeul-id STATIC ${HEADER_FILES} ${CODE_FILES})
add_executable(test src/main.cpp ${HEADER_FILES} ${CODE_FILES} ${TEST_FILES})

target_include_directories(hangeul-id PUBLIC include)
target_link_libraries(test PRIVATE Boost::boost)
target_link_libraries(test PRIVATE Catch2::Catch2)
target_link_libraries(hangeul-id PRIVATE Boost::boost)
set_target_properties(hangeul-id PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS hangeul-id
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include/hangeul_id)