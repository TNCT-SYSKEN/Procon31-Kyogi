#pragma once
#include "..//Data/Field.h"
class CreateMapParts
{
public:
	void mapFrame(const int x,const int y);
	void mapStatus(const int x,const int y,TileStatus status);
	void mapAgent(uint32_t x,uint32_t y,uint32_t teamID);
	//void mapPoint(const int x,const int y,const int p);
};

