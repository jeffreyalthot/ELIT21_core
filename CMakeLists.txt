cmake_minimum_required(VERSION 3.16)
project(ELIT21_core VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(elit21_core
    src/amount.cpp
    src/addrman.cpp
    src/banman.cpp
    src/checkpoint.cpp
    src/chain.cpp
    src/chainparams.cpp
    src/coins.cpp
    src/deploymentstatus.cpp
    src/common/args.cpp
    src/chainparamsbase.cpp
    src/consensus/params.cpp
    src/consensus/merkle.cpp
    src/crypto/hash.cpp
    src/init.cpp
    src/kernel/chainstate.cpp
    src/net.cpp
    src/net_processing.cpp
    src/node/blockmanager.cpp
    src/node/chainman.cpp
    src/node/context.cpp
    src/node/peerman.cpp
    src/node/utxo_snapshot.cpp
    src/node/mempool.cpp
    src/node/node.cpp
    src/policy/policy.cpp
    src/pow.cpp
    src/protocol.cpp
    src/txdb.cpp
    src/txmempool.cpp
    src/rpc/blockchain.cpp
    src/rpc/register.cpp
    src/rpc/server.cpp
    src/rpc/mining.cpp
    src/rpc/mempool.cpp
    src/versionbits.cpp
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

add_executable(network_stack_tests test/unit/network_stack_tests.cpp)
target_link_libraries(network_stack_tests PRIVATE elit21_core)
add_test(NAME network_stack_tests COMMAND network_stack_tests)

add_executable(protocol_tests test/unit/protocol_tests.cpp)
target_link_libraries(protocol_tests PRIVATE elit21_core)
add_test(NAME protocol_tests COMMAND protocol_tests)

add_executable(bitcoin_layout_tests test/unit/bitcoin_layout_tests.cpp)
target_link_libraries(bitcoin_layout_tests PRIVATE elit21_core)
add_test(NAME bitcoin_layout_tests COMMAND bitcoin_layout_tests)

add_executable(bitcoin_parity_modules_tests test/unit/bitcoin_parity_modules_tests.cpp)
target_link_libraries(bitcoin_parity_modules_tests PRIVATE elit21_core)
add_test(NAME bitcoin_parity_modules_tests COMMAND bitcoin_parity_modules_tests)

add_executable(bitcoin_source_parity_layout_tests test/unit/bitcoin_source_parity_layout_tests.cpp)
target_compile_definitions(bitcoin_source_parity_layout_tests PRIVATE PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}")
add_test(NAME bitcoin_source_parity_layout_tests COMMAND bitcoin_source_parity_layout_tests)
