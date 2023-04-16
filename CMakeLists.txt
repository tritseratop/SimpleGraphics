cmake_minimum_required (VERSION 3.8)

project ("SimpleGraphics")

add_subdirectory(api)
add_subdirectory(winapi_graph)

add_executable (SimpleGraphics WIN32 "SimpleGraphics.cpp")

set(targets SimpleGraphics SimpleGraphicsWinapi SimpleGraphicsApi)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${targets} PROPERTY CXX_STANDARD 17)
endif()

target_link_libraries(SimpleGraphics PRIVATE SimpleGraphicsWinapi)
