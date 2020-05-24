#include"CreateMap.h"
#include"CreateParts.h"
#include"../Data/Field.h"

Field field;
CreateParts createParts;

void CreateMap::createMapFrame() {
	field.height = 10;
	field.width = 10;
	createParts.mapFrame(field.height,field.width);
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