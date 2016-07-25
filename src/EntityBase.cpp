#include "EntityBase.h"

EntityBase::EntityBase( EntityCsv* entityCsv, Ogre::Entity* entity, Ogre::SceneNode* scene )
{
	mEntityCsv		= entityCsv;
	mSinbadEntity	= entity;
	mSinbadNode		= scene;
}

EntityBase::~EntityBase()
{
	mEntityCsv		= NULL;
	mSinbadEntity	= NULL;
	mSinbadNode		= NULL;
}

