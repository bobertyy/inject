project ( inject )
cmake_minimum_required( VERSION 3.11 )

option( test "Build all tests" ON )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

include_directories( include )

# Testing
if ( test ) 
  if ( APPLE ) 
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
  endif ( APPLE )

  include_directories( test/include )
  add_subdirectory( ext/googletest )

  enable_testing()

  file ( GLOB TEST_SOURCES "test/*.cpp" "test/**/*.cpp" )

  add_executable( inject-unit-tests ${TEST_SOURCES} )
  target_link_libraries( inject-unit-tests gtest gtest_main )

  add_test( * inject-unit-tests )
endif ( test )
