#include "DynamicGameObject.h"



DynamicGameObject::DynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency) 
	:Bitmap(renderer, fileName, xpos, ypos, useTransparency)
{
	
	//Set transform
	//obj_transform = new Transform(xpos, ypos);
	


	Draw();

}

DynamicGameObject::~DynamicGameObject()
{

}

 void DynamicGameObject::Update()
{
	
}

 void DynamicGameObject::SetGrounded(bool grounded)
 {
	 isGrounded = grounded;
 }

 void DynamicGameObject::OnEvent(IEvent* event)
 {
     //{
     //    switch (event->type)
     //    {
     //    case:
     //        // 
     //        break;

     //          case E_PLAYER_JUMP:
     //                for (Player* p : event->playersToAffect)
     //                 {
     //                     p->Jump();
     //                 }

     //        break;

     //    default:
     //        break;
     //    }


     //}
 }

 //Collider* DynamicGameObject::GetCollider()
 //{
	// if (collider == nullptr) return nullptr;
	// 
	// return collider;
 //}








