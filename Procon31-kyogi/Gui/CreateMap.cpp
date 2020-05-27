#include"CreateMap.h"
#include"CreateParts.h"
#include"../Data/Field.h"
#include <Siv3d.hpp>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

Field f;
Team t;
CreateMapParts cMP;

uint32_t x;
uint32_t y;

//Field‚Ì˜g
void CreateMap::createMapFrame() {
	cMP.mapFrame(f.width,f.height);
}

//FieldStatus‚Ì•`ŽÊ
void CreateMap::drawStatus() {
	rep(i,f.width) {
		rep(k,f.height){
			cMP.mapStatus(i,k,f.tiles[i][k].status);
		}
	}
}

//Agent‚Ì•`ŽÊ
void CreateMap::drawAgents() {
	cMP.mapAgent(1, 2, 1);
	for(int i = 0; i <t.agents.size();i++ ) {
		x = t.agents[i].x;
		y = t.agents[i].y;
		cMP.mapAgent(x,y,t.agents[i].agentID);
	}
}

//FieldPoint‚Ì•`ŽÊ
void CreateMap::drawPoints() {
	//cMP.mapPoint(1, 2, 10);
}

//ˆêŠ‡ˆ—(CreateMap)
void CreateMap::createMapManager() {
	drawStatus();
	createMapFrame();
	drawAgents();
	//drawPoints();
}
