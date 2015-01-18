cmake_minimum_required (VERSION 2.6)

project (IFCPP)

SET(CMAKE_BUILD_TYPE "Debug")
IF("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
  IF(CMAKE_COMPILER_IS_GNUCXX)
    SET_PROPERTY(DIRECTORY APPEND PROPERTY  
      COMPILE_DEFINITIONS $<$<CONFIG:Debug>:_DEBUG>
    )
  ENDIF()
ENDIF()


# if directories for external carve are not provided us internal carve 
# has to be done here because all other cMakes need the source dir too
message(STATUS   "------------------------------------------------------------------------")
IF(NOT CARVE_SOURCE_DIR)
  message(STATUS "CARVE_SOURCE_DIR not specified at cmake run! set it to internal carve")
  set(CARVE_SOURCE_DIR ${IFCPP_SOURCE_DIR}/Carve )
ENDIF(NOT CARVE_SOURCE_DIR)
IF(NOT CARVE_BINARY_DIR)
  message(STATUS "CARVE_BINARY_DIR not specified at cmake run! set it to current build dir")
  set(CARVE_BINARY_DIR ${IFCPP_BINARY_DIR})
ENDIF(NOT CARVE_BINARY_DIR)
message(STATUS   "------------------------------------------------------------------------")

OPTION(BUILD_VIEWER_APPLICATION "Build the viewer example application" ON)

add_subdirectory (Carve)
add_subdirectory (IfcPlusPlus)
add_subdirectory (IfcPlusPlusGeometry)
IF(BUILD_VIEWER_APPLICATION)
	add_subdirectory (SimpleViewer)
ENDIF()
