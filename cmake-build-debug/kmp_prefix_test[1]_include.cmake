if(EXISTS "/Users/gernotohner/CLionProjects/CS6420/Assignment3/cmake-build-debug/kmp_prefix_test[1]_tests.cmake")
  include("/Users/gernotohner/CLionProjects/CS6420/Assignment3/cmake-build-debug/kmp_prefix_test[1]_tests.cmake")
else()
  add_test(kmp_prefix_test_NOT_BUILT kmp_prefix_test_NOT_BUILT)
endif()
