#include <SDL.h>
#include <glm.hpp>
#include <gtx\transform.hpp>
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

