include_directories( include ../include )
add_subdirectory( ext/googletest )

enable_testing()


file ( GLOB TEST_SOURCES "*.cpp" "**/*.cpp" )

add_executable( inject-unit-tests ${TEST_SOURCES} )

target_compile_features(inject-unit-tests PRIVATE cxx_std_17)
target_link_libraries( inject-unit-tests inject_library gtest gtest_main )

add_test( * inject-unit-tests )