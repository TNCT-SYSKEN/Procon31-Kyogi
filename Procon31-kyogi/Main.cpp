# include <Siv3D.hpp> // OpenSiv3D v0.4.3
# include "SystemManager.h"
#include "../Procon31-kyogi/Gui/GuiManager.h"
#include"Data/Field.h"

void Main()
{

	GuiManager gui;
	gui.guiConfig();
	while (System::Update())
	{
		gui.guiManager();
	}
}