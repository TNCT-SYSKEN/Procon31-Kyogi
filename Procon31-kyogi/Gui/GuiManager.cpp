#include "GuiManager.h"
#include <Siv3D.hpp>
#include "CreateMap.h"
#include "InputOutput.h"

	CreateMap CM;
	InputOutput IO;

//createMapManagerとInputOutputManager
void GuiManager::guiManager() {
	CM.createMapManager();
	IO.inputOutputManager();
}

//画面の設定など
void GuiManager::guiConfig() {
	//Windowの設定
	Window::Resize(1920, 1080);
	const Size targetSize(1920, 1080);
	//バックグラウンドを白
	Scene::SetBackground(Palette::Gray);
	//フルスクリーン
	if (!Window::SetFullscreen(true, targetSize)) {
		System::Exit();
	}
}