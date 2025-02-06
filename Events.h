#pragma once
#include "tinyevents.hpp"
#include "Player.h"

struct jump{
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
	//typedef std::map<EventType, std::vector<IEventHandler*>> eventMap;

private:
	tinyevents::Dispatcher dispatcher;
	void SetListeners();

};



