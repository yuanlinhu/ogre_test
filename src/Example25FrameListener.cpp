#include "Example25FrameListener.h"

Example25FrameListener::Example25FrameListener( Ogre::Entity* entity, Ogre::SceneNode* node, 
											   OIS::Keyboard* keyboard, Ogre::Camera* cam, OIS::Mouse*mouse)
{
	mEntity = entity;
	mNode = node;
	mKeyboard = keyboard;
	mCamera = cam;
	mMouse = mouse;

	mAnimationState = mEntity->getAnimationState("RunBase");
	mAnimationState->setEnabled(true);
	//mAnimationState->setLoop(true);

	mAnimationStateTop = mEntity->getAnimationState("RunTop");
	mAnimationStateTop->setEnabled(true);
	//mAnimationStateTop->setLoop(true);
}

Example25FrameListener::~Example25FrameListener()
{
	
}

bool Example25FrameListener::frameStarted( const Ogre::FrameEvent& evt )
{
	const int speed = 50;
	float rotation = 0;
	mMouse->capture();

	const OIS::MouseState& mouseState = mMouse->getMouseState();

	Ogre::Vector3 sinbadTranslate(0, 0, 0);
	//mNode->translate(Ogre::Vector3(10, 0, 0) * evt.timeSinceLastFrame);
	mKeyboard->capture();
	if (mKeyboard->isKeyDown(OIS::KC_I))
	{
		rotation = 3.14f;
		mNode->resetOrientation();
		mNode->yaw(Ogre::Radian(rotation));
		sinbadTranslate += Ogre::Vector3(0, 0, -speed);
	}
	if (mKeyboard->isKeyDown(OIS::KC_K))
	{
		rotation = 0;
		mNode->resetOrientation();
		mNode->yaw(Ogre::Radian(rotation));
		sinbadTranslate += Ogre::Vector3(0, 0, speed);
	}
	if (mKeyboard->isKeyDown(OIS::KC_J))
	{
		rotation = -1.57f;
		mNode->resetOrientation();
		mNode->yaw(Ogre::Radian(rotation));

		sinbadTranslate += Ogre::Vector3(-speed, 0, 0);
	}
	if (mKeyboard->isKeyDown(OIS::KC_L))
	{
		rotation = 1.57f;
		mNode->resetOrientation();
		mNode->yaw(Ogre::Radian(rotation));
		sinbadTranslate += Ogre::Vector3(speed, 0, 0);
	}

	if(sinbadTranslate != Ogre::Vector3(0, 0, 0))
	{
		mAnimationState->setLoop(true);
		mAnimationStateTop->setLoop(true);
	}
	else
	{
		mAnimationState->setLoop(false);
		mAnimationStateTop->setLoop(false);
	}

	if(mouseState.buttonDown(OIS::MB_Left)) 
	{
		mNode->translate(sinbadTranslate * evt.timeSinceLastFrame);
	}

	if(mKeyboard->isKeyDown(OIS::KC_C))
	{
		/*
		static int ani_size = ani_vec.size();
		static int index = 0;
		index++;
		
		int ii = 0;


		std::string ani_name;
		Ogre::AnimationStateSet* as_set = mEntity->getAllAnimationStates();
		Ogre::AnimationStateIterator  iter = as_set->getAnimationStateIterator();
		while (iter.hasMoreElements())
		{
			ani_vec.push_back(iter.getNext()->getAnimationName());
			if(ii++ == index) 
			{
				ani_name = iter.getNext()->getAnimationName();
				break;
			}
			//std::cout<<"has more "<<iter.getNext()->getAnimationName()<<std::endl;
		}

		mAnimationState = mEntity->getAnimationState(ani_name);
		mAnimationState->setEnabled(true);
		mAnimationState->setLoop(true);
		*/
	}
	mAnimationState->addTime(evt.timeSinceLastFrame * 1.0);
	mAnimationStateTop->addTime(evt.timeSinceLastFrame * 1.0);
	return true;
}

