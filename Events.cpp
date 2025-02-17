#include "Events.h"
#include <iostream>
#include <string>


Events::Events()
{
   // players.emplace_back(playersInScene.begin(), playersInScene.end());
    
    AddListener(E_PLAYER_JUMP, new IEventHandler());

}

bool Events::AddListener(EventType type, IEventHandler* listener)
{
    listeners[type].push_back(listener);
    return true;
}

//Called in game
void Events::FireEvent(IEvent* event)
{
    for (IEventHandler* handler : listeners[event->type])
    {
        handler->OnEvent(event);
    }

}


IEvent::IEvent(EventType eventType)
{
    type = eventType;
}


//move on events switch to objects
//objects inherit from ieventhandler



