cmake_minimum_required (VERSION 3.8)

project ("SimpleGraphics")

add_subdirectory(simple_graph_api)
add_subdirectory(winapi_graph)
add_subdirectory(template_impl)

add_executable (SimpleGraphics WIN32 "test.cpp")

set(targets SimpleGraphics WinapiGraph SimpleGraphApi TemplateImpl)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${targets} PROPERTY CXX_STANDARD 17)
endif()

target_link_libraries(SimpleGraphics PRIVATE WinapiGraph)
