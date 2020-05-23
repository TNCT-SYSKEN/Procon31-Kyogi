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
	static Tile * PubTile();
	int32_t point;
	TileStatus status;
private:
	static Tile * PriTile;
};

class Agent
{
public:
	static Agent * PubAgent();
	uint32_t agentID;
	uint32_t x;
	uint32_t y;
private:
	static Agent * PriAgent;
};

class Team
{
public:
	static Team * PubTeam();
	uint32_t teamID;
	std::vector<Agent> agents;
	int32_t tilePoint;
	int32_t areaPoint;
private:
	static Team * PriTeam;

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
	static ActionHistory* PubActionHistory();
	uint32_t agentID;
	ActionType type;
	int32_t dx;
	int32_t dy;
	uint32_t turn;
	ActionResult result;
private:
	static ActionHistory * PriActionHistory;
};

class Field
{
public:
	static Field * PubField();
	uint32_t width;
	uint32_t height;
	int32_t startedAtUnixTime;
	uint32_t turn;
	std::vector<std::vector<Tile>> tiles;
	std::vector<Team> teams;
	std::vector<ActionHistory> actions;
private:
	static Field * PriField;
};

class MatchInfo
{
public:
	static MatchInfo * PubMatchInfo();
	uint32_t matchID;
	uint32_t teamID;
	std::string matchInfo;
	uint32_t turnMillis;
	uint32_t intervalMillis;
	uint32_t maxTurn;
private:
	static MatchInfo * PriMatchInfo;
};

class Action
{
public:
	static Action * PubAction();
	uint32_t agentID;
	ActionType type;
	int32_t dx;
	int32_t dy;
private:
	static Action * PriAction;
};

class Command
{
public:
	static Command * PubCommand();
	std::vector<Action> actions;
private:
	static Command * PriCommand;
};