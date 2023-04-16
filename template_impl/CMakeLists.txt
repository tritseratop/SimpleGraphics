cmake_minimum_required (VERSION 3.8)

project ("TemplateImpl")

set(SOURCE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}
)

aux_source_directory(${SOURCE_DIR} GRAPH_SOURCES)

add_library(TemplateImpl ${GRAPH_SOURCES})

target_link_libraries(TemplateImpl PRIVATE SimpleGraphApi)
target_include_directories(TemplateImpl PRIVATE ${CMAKE_SOURCE_DIR})