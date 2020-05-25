#pragma once
#include <string>
#include "Data/Field.h"

class ClientSettings
{
public:
	std::string token;
	std::string serverURL;
	int32_t serverPort;
};

class Client
{
private:
	ClientSettings& settings;
public:
	Client(ClientSettings&);

	bool ping();

	MatchInfo fetchMatchInfo();

	Field fetchField();

	void sendCommand(Command&);
};

