cmake_minimum_required (VERSION 3.8)

project ("SimpleGraphicsApi")

set(SOURCE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}
)

aux_source_directory(${SOURCE_DIR} GRAPH_SOURCES)

add_library(SimpleGraphApi ${GRAPH_SOURCES})