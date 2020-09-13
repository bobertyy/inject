
file( GLOB HEADER_LIST CONFIGURE_DEPENDENCIES "${Inject_SOURCE_DIR}/include/*.hpp" "${Inject_SOURCE_DIR}/include/**/*.hpp" )
file( GLOB SRC_LIST CONFIGURE_DEPENDENCIES "${Inject_SOURCE_DIR}/src/*.cpp" "${Inject_SOURCE_DIR}/src/**/*.cpp" )

add_library( inject_library ${HEADER_LIST} ${SRC_LIST} )

target_include_directories( inject_library PUBLIC ../include )
target_compile_features( inject_library PUBLIC cxx_std_17 )

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
