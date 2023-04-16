cmake_minimum_required (VERSION 3.8)

project ("SimpleGraphicsWinapi")

set(SOURCE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}
)

aux_source_directory(${SOURCE_DIR} GRAPH_SOURCES)

add_library(SimpleGraphicsWinapi ${GRAPH_SOURCES})

target_link_libraries(SimpleGraphicsWinapi PRIVATE SimpleGraphicsApi)