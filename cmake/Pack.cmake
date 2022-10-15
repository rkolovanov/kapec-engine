# Add package information
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_DEBIAN_BUILDREQUIRES "cmake >= 3.16") # TODO: Add
set(CPACK_DEBIAN_PACKAGE_DEPENDS "") # TODO: Add

# Include cmake-build-system Pack.cmake
if(DEFINED CMAKE_BUILD_SYSTEM_DIR)
  include(${CMAKE_BUILD_SYSTEM_DIR}/Pack.cmake)
endif()

# Dependencies for cmake-build-system pack targets
add_dependencies(pack-deb ${PROJECT_NAME})
add_dependencies(pack-rpm ${PROJECT_NAME})
