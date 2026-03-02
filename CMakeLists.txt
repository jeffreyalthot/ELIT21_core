cmake_minimum_required(VERSION 3.16)
project(ELIT21_core VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(elit21_core
    src/consensus/params.cpp
    src/crypto/hash.cpp
    src/kernel/chainstate.cpp
    src/node/node.cpp
    src/rpc/blockchain.cpp
    src/validation/block_validator.cpp
)

target_include_directories(elit21_core PUBLIC src)

add_executable(ELIT21d src/ELIT21d.cpp)
target_link_libraries(ELIT21d PRIVATE elit21_core)

enable_testing()

add_executable(node_validation_tests test/unit/node_validation_tests.cpp)
target_link_libraries(node_validation_tests PRIVATE elit21_core)
add_test(NAME node_validation_tests COMMAND node_validation_tests)
