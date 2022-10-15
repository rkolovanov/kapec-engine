if(WITH_TESTS)
  enable_testing()
  add_subdirectory(auto)

  if(WITH_MANUAL_TESTS)
    add_subdirectory(manual)
  endif()
endif()
