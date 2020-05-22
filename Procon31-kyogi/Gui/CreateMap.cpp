#include"CreateMap.h"
#include"../Data/Field.h"

void CreateMap::createMapFrame() {
	Field field;
	for (int i = 0; i < field.height; i++) {
		for (int k = 0; k < field.width; k++) {

		}
	}
}

void CreateMap::drawStatus() {

}

void CreateMap::drawAgents() {

}

void CreateMap::createMapManager() {
	createMapFrame();
	drawStatus();
	drawAgents();
}