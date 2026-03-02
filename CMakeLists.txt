cmake_minimum_required(VERSION 3.16)
project(ELIT21_core VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(elit21_core
    src/chain.cpp
    src/chainparams.cpp
    src/common/args.cpp
    src/chainparamsbase.cpp
    src/consensus/params.cpp
    src/consensus/merkle.cpp
    src/crypto/hash.cpp
    src/init.cpp
    src/kernel/chainstate.cpp
    src/net_processing.cpp
    src/node/chainman.cpp
    src/node/context.cpp
    src/node/mempool.cpp
    src/node/node.cpp
    src/policy/policy.cpp
    src/pow.cpp
    src/rpc/blockchain.cpp
    src/rpc/mining.cpp
    src/rpc/mempool.cpp
    src/validation/block_validator.cpp
    src/validation/validation.cpp
    src/validation/tx_validator.cpp
    src/validationinterface.cpp
)

target_include_directories(elit21_core PUBLIC src)

add_executable(ELIT21d src/ELIT21d.cpp)
target_link_libraries(ELIT21d PRIVATE elit21_core)

enable_testing()

add_executable(node_validation_tests test/unit/node_validation_tests.cpp)
target_link_libraries(node_validation_tests PRIVATE elit21_core)
add_test(NAME node_validation_tests COMMAND node_validation_tests)

add_executable(mempool_policy_tests test/unit/mempool_policy_tests.cpp)
target_link_libraries(mempool_policy_tests PRIVATE elit21_core)
add_test(NAME mempool_policy_tests COMMAND mempool_policy_tests)

add_executable(chainparams_tests test/unit/chainparams_tests.cpp)
target_link_libraries(chainparams_tests PRIVATE elit21_core)
add_test(NAME chainparams_tests COMMAND chainparams_tests)

add_executable(merkle_pow_tests test/unit/merkle_pow_tests.cpp)
target_link_libraries(merkle_pow_tests PRIVATE elit21_core)
add_test(NAME merkle_pow_tests COMMAND merkle_pow_tests)

add_executable(chainman_tests test/unit/chainman_tests.cpp)
target_link_libraries(chainman_tests PRIVATE elit21_core)
add_test(NAME chainman_tests COMMAND chainman_tests)


add_executable(chain_tests test/unit/chain_tests.cpp)
target_link_libraries(chain_tests PRIVATE elit21_core)
add_test(NAME chain_tests COMMAND chain_tests)

add_executable(validationinterface_tests test/unit/validationinterface_tests.cpp)
target_link_libraries(validationinterface_tests PRIVATE elit21_core)
add_test(NAME validationinterface_tests COMMAND validationinterface_tests)

add_executable(args_tests test/unit/args_tests.cpp)
target_link_libraries(args_tests PRIVATE elit21_core)
add_test(NAME args_tests COMMAND args_tests)
