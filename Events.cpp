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


IEvent::IEvent(EventType eventType, std::vector<DynamicGameObject*> objsToAffect, std::vector<Player*> psToAffect)
{
    type = eventType;
    objectsToAffect = objsToAffect;
    playersToAffect = psToAffect;
} 

IEvent::IEvent(EventType eventType, std::vector<DynamicGameObject*> objsToAffect)
{
    type = eventType;
    objectsToAffect = objsToAffect;
}

IEvent::IEvent(EventType eventType, std::vector<Player*> psToAffect)
{
    type = eventType;
    playersToAffect = psToAffect;
}

void IEventHandler::OnEvent(IEvent* event)
{
        switch (event->type)
        {
        case E_PLAYER_MOVE:
            //
            break;

        case E_PLAYER_JUMP:
            for (Player* p : event->playersToAffect)
            {
                p->Jump();
            }

            break;

        default:
            break;
        }

    
}

//move on events switch to objects
//objects inherit from ieventhandler



