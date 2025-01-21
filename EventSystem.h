#include <SDL.h>
#include "DynamicGameObject.h"

enum EVENTS
{
	PLAYER_MOVED,
	NUM_OF_EVENTS
};


class EventSystem
{
	void CallEvent(EVENTS eventToCall);
	void CheckEvents();



};

