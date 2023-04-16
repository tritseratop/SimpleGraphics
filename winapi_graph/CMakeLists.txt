cmake_minimum_required (VERSION 3.8)

project ("WinapiGraph")

set(SOURCE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}
)

aux_source_directory(${SOURCE_DIR} GRAPH_SOURCES)

add_library(WinapiGraph ${GRAPH_SOURCES})

target_link_libraries(WinapiGraph PRIVATE SimpleGraphApi)
target_include_directories(WinapiGraph PRIVATE ${CMAKE_SOURCE_DIR})