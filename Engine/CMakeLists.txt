cmake_minimum_required(VERSION 3.28)
project(Engine VERSION 1.0.0 LANGUAGES C CXX)

# Create static library target for the Engine
add_library(Engine STATIC Engine.cpp)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/input/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/event/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/*.cpp
)
if(ENGINE_SOURCES)
  target_sources(Engine PRIVATE ${ENGINE_SOURCES})
endif()

target_include_directories(Engine
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/input>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/event>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/renderer>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(Engine PUBLIC cxx_std_20)

# Link public dependencies (assumes SFML targets are available from the top-level)
target_link_libraries(Engine PUBLIC 
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
    SFML::Network
)

# Provide an imported-style alias for consumers
add_library(Engine::Engine ALIAS Engine)

# Installation / export
install(TARGETS Engine EXPORT EngineTargets
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT EngineTargets
  FILE EngineTargets.cmake
  NAMESPACE Engine::
  DESTINATION lib/cmake/Engine
)

include(CMakePackageConfigHelpers)
set(ConfigPackageLocation lib/cmake/Engine)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/EngineConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/EngineConfig.cmake"
  @ONLY
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/EngineConfigVersion.cmake"
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/EngineConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/EngineConfigVersion.cmake"
  DESTINATION ${ConfigPackageLocation}
)
