#pragma once
#include <cstdint>
#include <vector>
#include <string>

enum TileStatus
{
	None,
	FriendCastle,
	FriendZone,
	EnemyCastle,
	EnemyZone
};

class Tile
{
public:
	int32_t point;
	TileStatus status;
};

class Agent
{
public:
	uint32_t agentID;
	uint32_t x;
	uint32_t y;
};

class Team
{
public:
	uint32_t teamID;
	std::vector<Agent> agents;
	int32_t tilePoint;
	int32_t areaPoint;
};

enum ActionType
{
	Move,
	Remove,
	Stay,
	Deploy
};

enum ActionResult
{
	Invalid,
	Conflict,
	Valid
};

class ActionHistory
{
public:
	uint32_t agentID;
	ActionType type;
	int32_t dx;
	int32_t dy;
	uint32_t turn;
	ActionResult result;
};

class Field
{
public:
	uint32_t width;
	uint32_t height;
	int32_t startedAtUnixTime;
	uint32_t turn;
	std::vector<std::vector<Tile>> tiles;
	std::vector<Team> teams;
	std::vector<ActionHistory> actions;
};

class MatchInfo
{
public:
	uint32_t matchID;
	uint32_t teamID;
	std::string matchInfo;
	uint32_t turnMillis;
	uint32_t intervalMillis;
	uint32_t maxTurn;
};

class Action
{
public:
	uint32_t agentID;
	ActionType type;
	int32_t dx;
	int32_t dy;
};

class Command
{
public:
	std::vector<Action> actions;
};