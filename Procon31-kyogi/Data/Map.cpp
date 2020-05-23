#include "Map.h"

Map* Map::PriMap = nullptr;
Map* Map::PubMap() {
	if (PriMap == nullptr) {
		PriMap = new Map;
	}
	return PriMap;
}