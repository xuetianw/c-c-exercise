# CMake generated Testfile for 
# Source directory: /home/fred/CLionProjects/CMPT135/test
# Build directory: /home/fred/CLionProjects/CMPT135/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AllTests "/home/fred/CLionProjects/CMPT135/bin/runAllTests")
set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "/home/fred/CLionProjects/CMPT135/test/CMakeLists.txt;19;add_test;/home/fred/CLionProjects/CMPT135/test/CMakeLists.txt;0;")
subdirs("lib/googlemock")
