include(GoogleTest)

find_package(GTest REQUIRED)

file(GLOB_RECURSE TEST_SOURCES tests *.cc)
foreach(TEST_SOURCE IN ITEMS ${TEST_SOURCES})
    message(STATUS "found test ${TEST_SOURCE}")
    get_filename_component(TEST_NAME "${TEST_SOURCE}" NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} PUBLIC GTest::Main)
    target_link_libraries(${TEST_NAME} PUBLIC gnssxx-static)
    gtest_add_tests(TARGET ${TEST_NAME} SOURCES ${TEST_SOURCE})
endforeach()
