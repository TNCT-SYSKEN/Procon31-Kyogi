#include "Field.h"

Tile * Tile::PriTile = nullptr;
Tile * Tile::PubTile() {
	if (PriTile == nullptr) {
		PriTile = new Tile;
	}
	return PriTile;
}

Agent * Agent::PriAgent = nullptr;
Agent * Agent::PubAgent() {
	if (PriAgent == nullptr) {
		PriAgent = new Agent;
	}
	return PriAgent;
}

Team * Team::PriTeam = nullptr;
Team * Team::PubTeam() {
	if (PriTeam == nullptr) {
		PriTeam = new Team;
	}
	return PriTeam;
}

ActionHistory * ActionHistory::PriActionHistory = nullptr;
ActionHistory * ActionHistory::PubActionHistory() {
	if (PriActionHistory == nullptr) {
		PriActionHistory = new ActionHistory;
	}
	return PriActionHistory;
}


Field * Field::PriField = nullptr;
Field * Field::PubField() {
	if (PriField == nullptr) {
		PriField = new Field;
	}
	return PriField;
}