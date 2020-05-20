add_subdirectory(lib/googlemock)
enable_testing()

add_executable(runAllTests
  # Add all new test files to the list here.
  # Place each file name on a separate line.
#        Dummy.cpp # This file is a placeholder and tests nothing.
        TriangleTest.cpp
        Hailstone_test.cpp
#        test.cpp
#        MockTurtleTest.cpp
        Awards_test.cpp
#        Mock_test.cpp ../include/student.h)
        )

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary)

add_test(NAME AllTests COMMAND runAllTests)

