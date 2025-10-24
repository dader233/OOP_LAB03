# CMake generated Testfile for 
# Source directory: /workspaces/OOP_LAB03
# Build directory: /workspaces/OOP_LAB03/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(lab03Tests "/workspaces/OOP_LAB03/build/tests")
set_tests_properties(lab03Tests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/OOP_LAB03/CMakeLists.txt;35;add_test;/workspaces/OOP_LAB03/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
