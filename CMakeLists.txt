cmake_minimum_required(VERSION 3.22)
project(kapec-engine
        VERSION 0.0.1
        DESCRIPTION "3D-движок на C++ и SFML"
        HOMEPAGE_URL "https://github.com/rkolovanov/kapec-engine"
        LANGUAGES CXX)

option(WITH_SANDBOX "С песочницей" OFF)
option(WITH_MANUAL_TESTS "С ручными тестами" ON)
option(WITH_TESTS "С тестами" ON)

set(CMAKE_CXX_STANDARD 23)
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/sources)
set(PROJECT_MODULES common)

include(cmake/Libraries.cmake)

add_custom_target(${PROJECT_NAME})

foreach(MODULE_NAME ${PROJECT_MODULES})
  set(MODULE_TARGET ${PROJECT_NAME}-${MODULE_NAME})
  add_subdirectory(${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/${MODULE_NAME})
  add_dependencies(${PROJECT_NAME} ${MODULE_TARGET})
endforeach()

add_subdirectory(sandbox)
add_subdirectory(tests)

include(cmake/Pack.cmake)
