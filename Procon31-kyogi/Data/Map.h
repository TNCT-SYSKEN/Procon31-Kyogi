#pragma once
#include <Siv3D.hpp>
class Map{
public:
	static Map* PubMap();
	//��
	int32 width;
	//�c
	int32 height;

private:
	static Map* PriMap;
};
