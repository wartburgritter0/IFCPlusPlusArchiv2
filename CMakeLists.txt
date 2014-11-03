cmake_minimum_required (VERSION 2.6)

project (IFCPP)


# If carve directories are not set, internal carve is used.
# Is done here because all other cMakes need the source dir too.
IF(NOT CARVE_SOURCE_DIR)
  message(STATUS "CARVE_SOURCE_DIR not set. Set it to carve of IfcPlusPlus.")
  set(CARVE_SOURCE_DIR ${IFCPP_SOURCE_DIR}/Carve )
ENDIF(NOT CARVE_SOURCE_DIR)
IF(NOT CARVE_BINARY_DIR)
  message(STATUS "CARVE_BINARY_DIR not set. Set it to binary dir of IfcPlusPlus.")
  set(CARVE_BINARY_DIR ${IFCPP_BINARY_DIR})
ENDIF(NOT CARVE_BINARY_DIR)

OPTION(BUILD_VIEWER_APPLICATION "Build the viewer example application" ON)

add_subdirectory (Carve)
add_subdirectory (IfcPlusPlus)
add_subdirectory (IfcPlusPlusGeometry)
IF(BUILD_VIEWER_APPLICATION)
	add_subdirectory (SimpleViewer)
ENDIF()

