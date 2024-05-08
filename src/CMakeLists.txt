add_library(gnssxx-shared SHARED)
add_library(gnssxx-static STATIC)

file(GLOB_RECURSE GNSSXX_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src *.cc)

set_target_properties(gnssxx-shared PROPERTIES OUTPUT_NAME gnssxx)
set_target_properties(gnssxx-static PROPERTIES OUTPUT_NAME gnssxx)

target_sources(gnssxx-shared PUBLIC ${GNSSXX_SOURCES})
target_include_directories(gnssxx-shared PUBLIC ../include)
target_sources(gnssxx-static PUBLIC ${GNSSXX_SOURCES})
target_include_directories(gnssxx-static PUBLIC ../include)
