#////////////////////////////////////////////////////////////////////
#---------- Módulo do CMake Global ----------
#///////////////////////////////////////////////////////////////////


cmake_minimum_required(VERSION 3.28)
project(Game VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- SFML ---

set(SFML_DIR "C:/Users/Heito/source/repos/Projeto_minha_engine/Third_party/SFML-3.1.0/lib/cmake/SFML")
find_package(SFML 3.1 COMPONENTS Graphics Window System Network Audio REQUIRED)

# --- Subdiretórios ---
add_subdirectory(Engine)

# --- Seu executável para Release ---
add_executable(Game
    Game/src/main.cpp
    Game/src/action.cpp
    Game/src/player.cpp
    Engine/Engine.cpp
)

target_include_directories(Game PRIVATE Game/include)

target_link_libraries(Game PRIVATE Engine)
target_link_libraries(Game PUBLIC 
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
    SFML::Network
)

# Instalação / configurações adicionais
install(TARGETS Game RUNTIME DESTINATION bin)

add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_RUNTIME_DLLS:Game>
    $<TARGET_FILE_DIR:Game>
    COMMAND_EXPAND_LISTS
)