message(STATUS "Building genogrove_structure tests")
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# gather all test sources
FILE(GLOB TEST_SOURCES "*.cpp")

# create test executable
add_executable(genogrove_structure_tests ${TEST_SOURCES})

target_link_libraries(genogrove_structure_tests
        genogrove_data_type
        genogrove_structure
        GTest::gtest
        GTest::gtest_main
)