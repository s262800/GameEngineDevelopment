#pragma once
#include <map>
#include "Logger.h"

using namespace std;


struct Variant
{
    enum Type
    {
        TYPE_INTEGER,
        TYPE_FLOAT,
        TYPE_BOOL,
        TYPE_STRING_ID,
        TYPE_COUNT
    };

    Type type;

    union
    {
        int asInteger;
        float asFloat;
        bool asBool;
        unsigned long asStringId;
    };
};



enum EventType
{
	E_PLAYER_JUMP,
	E_PLAYER_MOVE,
	E_EVENTTYPE_COUNT
};

	
class IEvent
{
public:
    IEvent(EventType eventType);

    EventType type;
};



class IEventHandler
{
public:

    virtual void OnEvent(IEvent* event);
private:

};


typedef std::map<EventType, std::vector<IEventHandler*>> eventMap;


class Events
{
public:

    Events();
    bool AddListener(EventType type, IEventHandler* listener);

    void FireEvent(IEvent* event);



private:
	eventMap listeners;
};



