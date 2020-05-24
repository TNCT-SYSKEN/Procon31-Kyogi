#include "GuiManager.h"
#include <Siv3D.hpp>
#include "CreateMap.h"
#include "InputOutput.h"

	CreateMap CM;
	InputOutput IO;

//createMapManager��InputOutputManager
void GuiManager::guiManager() {
	CM.createMapManager();
	IO.inputOutputManager();
}

//��ʂ̐ݒ�Ȃ�
void GuiManager::guiConfig() {
	//Window�̐ݒ�
	Window::Resize(1920, 1080);
	const Size targetSize(1920, 1080);
	//�o�b�N�O���E���h��
	Scene::SetBackground(Palette::Gray);
	//�t���X�N���[��
	if (!Window::SetFullscreen(true, targetSize)) {
		System::Exit();
	}
}