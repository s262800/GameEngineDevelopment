#include "Events.h"
#include <iostream>
#include <string>


Events::Events()
{
    AddListener(E_PLAYER_JUMP, new IEventHandler());
}

bool Events::AddListener(EventType type, IEventHandler* listener)
{
    listeners[type].push_back(listener);
    return true;
}

void Events::FireEvent(EventType type, IEvent* event)
{
    for (IEventHandler* handler : listeners[type])
    {
        handler->OnEvent(event, nullptr);
    }
}

void Events::FireEvent(EventType type, IEvent* event, Player* player)
{
    Logger::Info("FiredEvent with player");
    player = player;
    for (IEventHandler* handler : listeners[type])
    {
        handler->OnEvent(event, player);
    }
}

IEvent::IEvent(EventType eventType)
{
    type = eventType;
}

void IEventHandler::OnEvent(IEvent* event, Player* player)
{
    switch (event->type)
    {
    case E_PLAYER_MOVE:
        //
        break;

    case E_PLAYER_JUMP:
        player->Jump();
        break;

        // ...

    default:
        break;
    }

}


