#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <array>

struct Key {
    std::string name;
    sf::Keyboard::Key code;
    sf::Keyboard::Scan scan_code;

    Key(const std::string n);

    Key(const std::string n, sf::Keyboard::Key c);

    Key(const sf::Keyboard::Key sfml_key);

    operator int() const;
};

namespace Keyboard {
    inline const std::array<Key, 85> all_Keys = {        
        {
            // Letras
            Key("A", sf::Keyboard::Key::A),
            Key("B", sf::Keyboard::Key::B),
            Key("C", sf::Keyboard::Key::C),
            Key("D", sf::Keyboard::Key::D),
            Key("E", sf::Keyboard::Key::E),
            Key("F", sf::Keyboard::Key::F),
            Key("G", sf::Keyboard::Key::G),
            Key("H", sf::Keyboard::Key::H),
            Key("I", sf::Keyboard::Key::I),
            Key("J", sf::Keyboard::Key::J),
            Key("K", sf::Keyboard::Key::K),
            Key("L", sf::Keyboard::Key::L),
            Key("M", sf::Keyboard::Key::M),
            Key("N", sf::Keyboard::Key::N),
            Key("O", sf::Keyboard::Key::O),
            Key("P", sf::Keyboard::Key::P),
            Key("Q", sf::Keyboard::Key::Q),
            Key("R", sf::Keyboard::Key::R),
            Key("S", sf::Keyboard::Key::S),
            Key("T", sf::Keyboard::Key::T),
            Key("U", sf::Keyboard::Key::U),
            Key("V", sf::Keyboard::Key::V),
            Key("W", sf::Keyboard::Key::W),
            Key("X", sf::Keyboard::Key::X),
            Key("Y", sf::Keyboard::Key::Y),
            Key("Z", sf::Keyboard::Key::Z),

            // Números
            Key("Num0", sf::Keyboard::Key::Num0),
            Key("Num1", sf::Keyboard::Key::Num1),
            Key("Num2", sf::Keyboard::Key::Num2),
            Key("Num3", sf::Keyboard::Key::Num3),
            Key("Num4", sf::Keyboard::Key::Num4),
            Key("Num5", sf::Keyboard::Key::Num5),
            Key("Num6", sf::Keyboard::Key::Num6),
            Key("Num7", sf::Keyboard::Key::Num7),
            Key("Num8", sf::Keyboard::Key::Num8),
            Key("Num9", sf::Keyboard::Key::Num9),

            // Função
            Key("F1", sf::Keyboard::Key::F1),
            Key("F2", sf::Keyboard::Key::F2),
            Key("F3", sf::Keyboard::Key::F3),
            Key("F4", sf::Keyboard::Key::F4),
            Key("F5", sf::Keyboard::Key::F5),
            Key("F6", sf::Keyboard::Key::F6),
            Key("F7", sf::Keyboard::Key::F7),
            Key("F8", sf::Keyboard::Key::F8),
            Key("F9", sf::Keyboard::Key::F9),
            Key("F10", sf::Keyboard::Key::F10),
            Key("F11", sf::Keyboard::Key::F11),
            Key("F12", sf::Keyboard::Key::F12),

            // Modificadores
            Key("LControl", sf::Keyboard::Key::LControl),
            Key("RControl", sf::Keyboard::Key::RControl),
            Key("LShift", sf::Keyboard::Key::LShift),
            Key("RShift", sf::Keyboard::Key::RShift),
            Key("LAlt", sf::Keyboard::Key::LAlt),
            Key("RAlt", sf::Keyboard::Key::RAlt),
            Key("LSystem", sf::Keyboard::Key::LSystem),
            Key("RSystem", sf::Keyboard::Key::RSystem),

            // Especiais
            Key("Escape", sf::Keyboard::Key::Escape),
            Key("Tab", sf::Keyboard::Key::Tab),
            Key("Space", sf::Keyboard::Key::Space),
            Key("Enter", sf::Keyboard::Key::Enter),
            Key("Backspace", sf::Keyboard::Key::Backspace),
            Key("Insert", sf::Keyboard::Key::Insert),
            Key("Delete", sf::Keyboard::Key::Delete),

            // Navegação
            Key("Home", sf::Keyboard::Key::Home),
            Key("End", sf::Keyboard::Key::End),
            Key("PageUp", sf::Keyboard::Key::PageUp),
            Key("PageDown", sf::Keyboard::Key::PageDown),

            // Setas
            Key("Up", sf::Keyboard::Key::Up),
            Key("Down", sf::Keyboard::Key::Down),
            Key("Left", sf::Keyboard::Key::Left),
            Key("Right", sf::Keyboard::Key::Right),

            // Numpad
            Key("Numpad0", sf::Keyboard::Key::Numpad0),
            Key("Numpad1", sf::Keyboard::Key::Numpad1),
            Key("Numpad2", sf::Keyboard::Key::Numpad2),
            Key("Numpad3", sf::Keyboard::Key::Numpad3),
            Key("Numpad4", sf::Keyboard::Key::Numpad4),
            Key("Numpad5", sf::Keyboard::Key::Numpad5),
            Key("Numpad6", sf::Keyboard::Key::Numpad6),
            Key("Numpad7", sf::Keyboard::Key::Numpad7),
            Key("Numpad8", sf::Keyboard::Key::Numpad8),
            Key("Numpad9", sf::Keyboard::Key::Numpad9),

            // Operações do numpad
            Key("Add", sf::Keyboard::Key::Add),
            Key("Subtract", sf::Keyboard::Key::Subtract),
            Key("Multiply", sf::Keyboard::Key::Multiply),
            Key("Divide", sf::Keyboard::Key::Divide)
        }
    };
};