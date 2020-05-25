#include <Siv3D.hpp>
#include "Client.h"

Field readFromJson(const std::string filepath);
void writeToJson(const std::string filepath, const Command& command);

Client::Client(ClientSettings& _settings): settings(_settings)
{

}

bool Client::ping()
{
    // TODO サーバーにpingを打つ

	return true;
}

MatchInfo Client::fetchMatchInfo()
{
    // TODO サーバーからファイルを取ってくる

	MatchInfo info;
	return info;
}

Field Client::fetchField()
{
    // TODO サーバーからファイルを取ってくる

	Field field = readFromJson("JsonData/field_0.json");
	return field;
}

void Client::sendCommand(Command& command)
{
    writeToJson("JsonData/command_0.json", command);

    // TODO サーバーにファイルを送る
}

std::vector<std::vector<int32_t>> read2dArray(const JSONValue& v) {
    std::vector<std::vector<int32_t>> result;
    for (const auto& rows : v.arrayView()) {
        std::vector<int32_t> row;
        for (const auto& point : rows.arrayView()) {
            row.push_back(point.get<int32_t>());
        }
        result.push_back(row);
    }
    return result;
}

TileStatus toTileStatus(int32_t i) {
    // TODO Procon31の仕様が公表されるまで実装不可
    return TileStatus::None;
}

ActionType toActionType(std::string s) {
    if (s == "move") return ActionType::Move;
    else if (s == "remove") return ActionType::Remove;
    else if (s == "deploy") return ActionType::Deploy;
    else if (s == "stay") return ActionType::Stay;
}

ActionResult toActionResult(int32_t i) {
    switch (i) {
    case -1:
        return ActionResult::Invalid;
    case 0:
        return ActionResult::Conflict;
    case 1:
        return ActionResult::Valid;
    }
}

std::string toString(ActionType type) {
    switch (type) {
    case Move:
        return "move";
    case Remove:
        return "remove";
    case Deploy:
        return "deploy";
    case Stay:
        return "stay";
    }
}

Field readFromJson(const std::string filepath) {
    JSONReader j(Unicode::Widen(filepath));

    Field f;
    f.width = j[U"width"].get<int32_t>();
    f.height = j[U"height"].get<int32_t>();
    f.startedAtUnixTime = j[U"startedAtUnixTime"].get<int32_t>();
    f.turn = j[U"turn"].get<int32_t>();

    std::vector<std::vector<int32_t>> points = read2dArray(j[U"points"]);
    std::vector<std::vector<int32_t>> status = read2dArray(j[U"tiled"]);
    for (int y = 0; y < points.size(); y++) {
        std::vector<Tile> row;
        for (int x = 0; x < points[y].size(); x++) {
            Tile t;
            t.point = points[y][x];
            t.status = toTileStatus(status[y][x]);
            row.push_back(t);
        }
        f.tiles.push_back(row);
    }

    for (const auto& team : j[U"teams"].arrayView()) {
        Team t;
        t.teamID = team[U"teamID"].get<int32_t>();
        t.tilePoint = team[U"tilePoint"].get<int32_t>();
        t.areaPoint = team[U"areaPoint"].get<int32_t>();
        for (const auto& agents : team[U"agents"].arrayView()) {
            Agent a{};
            a.agentID = agents[U"agentID"].get<int32_t>();
            a.x = agents[U"x"].get<int32_t>();
            a.y = agents[U"y"].get<int32_t>();
            t.agents.push_back(a);
        }
        f.teams.push_back(t);
    }

    for (const auto &actions : j[U"actions"].arrayView()) {
        ActionHistory ah;
        ah.agentID = actions[U"agentID"].get<int32_t>();
        ah.type = toActionType(actions[U"type"].getString().narrow());
        ah.dx = actions[U"dx"].get<int32_t>();
        ah.dy = actions[U"dy"].get<int32_t>();
        ah.turn = actions[U"turn"].get<int32_t>();
        ah.result = toActionResult(actions[U"apply"].get<int32_t>());
        f.actions.push_back(ah);
    }

    return f;
}

void writeToJson(const std::string filepath, const Command& command) {
    JSONWriter j;

    j.startObject();
    j.key(U"actions").startArray();
    for (const auto& a : command.actions) {
        j.startObject();
        j.key(U"agentID").write(a.agentID);
        j.key(U"type").write(Unicode::Widen(toString(a.type)));
        j.key(U"dx").write(a.dx);
        j.key(U"dy").write(a.dy);
        j.endObject();
    }
    j.endArray();
    j.endObject();

    j.save(Unicode::Widen(filepath));
}
