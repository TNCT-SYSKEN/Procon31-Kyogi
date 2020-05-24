#include "InputOutput.h"
#include <Siv3d.hpp>
void InputOutput::inputOutputManager() {
    Rect(0, 0, 1920, 100).draw(Palette::Black);
    if (SimpleGUI::Button(U"Start", Vec2(50, 50)))
    {   
    }
}