set(MODULE "${DIR_NAME}")
set(LIBRARY "lib_${MODULE}")
set(TESTS "test_${MODULE}")
set(APPLICATION "app_${MODULE}")

# Include directory with public headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add all submodules
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(application)

#############################################
##### Testing
#############################################

include("CTestTests.txt")