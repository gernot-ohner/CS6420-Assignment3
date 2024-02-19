cmake_minimum_required(VERSION 3.28)
project(Assignment3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment3 src/main.cpp
        src/alg_strings.cpp
        src/RabinKarp2D.cpp
        src/RabinKarp2D.h
        src/KMPPrefixFunction.cpp
        src/KMPPrefixFunction.h
        src/rabinkarp2d2.cpp
        src/rabinkarp2d2.h)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        rabin_karp_test
        src/RabinKarp2D.cpp
        src/RabinKarp2D.h
        tests/test-rabin-karp.cpp

)


add_executable(
        roll_hash_test
        src/RabinKarp2D.cpp
        src/RabinKarp2D.h
        tests/test-roll-hash.cpp
)

add_executable(
        kmp_prefix_test
        src/KMPPrefixFunction.cpp
        src/KMPPrefixFunction.h
        tests/test-kmp-prefix.cpp
)



target_link_libraries(
        rabin_karp_test
        GTest::gtest_main
)
target_link_libraries(
        kmp_prefix_test
        GTest::gtest_main
)

target_link_libraries(
        roll_hash_test
        GTest::gtest_main
)



include(GoogleTest)
gtest_discover_tests(rabin_karp_test)
gtest_discover_tests(kmp_prefix_test)
gtest_discover_tests(roll_hash_test)
