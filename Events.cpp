#include "Events.h"
#include <iostream>

using namespace tinyevents;




Events::Events()
{
	for (int i = 0; i < EVENTTYPE_COUNT; i++) {
		eventTypes.push_back(static_cast<EventType>(i));
	}


	SetListeners();
}

void Events::CheckEvents()
{
	


}

void Events::FireEvent(EventType e)
{
	for (auto thisEvent : eventTypes)
	{
		if (e == thisEvent)
		{

			//dispatcher.queue(e);
			dispatcher.dispatch(e);

		}


	}


}

void Events::SetListeners()
{
	//Set jump listener
	auto handle = dispatcher.listen<jump>([](const auto& event)
		{
			event.player->Jump();
		});





}

