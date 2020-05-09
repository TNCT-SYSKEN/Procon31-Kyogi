#pragma once
#include <Siv3D.hpp>
class Map{
public:
	static Map* PubMap();
	//â°
	int32 width;
	//èc
	int32 height;

private:
	static Map* PriMap;
};
