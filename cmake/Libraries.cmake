# Project header files
include_directories(${PROJECT_SOURCE_DIR})

# Find libraries
find_package(cmake-build-system 0.0.2 REQUIRED)
find_package(auxiliary-cpp 1.0.0 REQUIRED)
find_package(SFML 2.5.1 COMPONENTS system graphics window REQUIRED)

if(WITH_TESTS)
  find_package(GTest 1.11.0 REQUIRED)
endif()
