#pragma once
#include "tinyevents.hpp"
#include "Player.h"

struct jump{
	EventType type = PLAYER_JUMP;
	Player* player;
};


	enum EventType
	{
		PLAYER_JUMP,
		PLAYER_MOVE,
		EVENTTYPE_COUNT
	};

class Events
{
public:

	Events();
	void CheckEvents();
	void FireEvent(EventType e);
	std::vector<EventType> eventTypes;
	typedef std::map<EventType, std::vector<IEventHandler*>> eventMap;

private:
	tinyevents::Dispatcher dispatcher;
	void SetListeners();

};



