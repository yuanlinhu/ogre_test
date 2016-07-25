
#ifndef __ENTITY_BASE_H__
#define __ENTITY_BASE_H__


#include "BaseApplication.h"

#include "csvReader.h"


class EntityCsv;

class EntityBase
{
public:
	EntityBase(EntityCsv* entityCsv, Ogre::Entity* entity, Ogre::SceneNode* scene);
	~EntityBase();


private:
	EntityCsv*				mEntityCsv;

	Ogre::Entity*			mSinbadEntity;
	Ogre::SceneNode*		mSinbadNode;


private:
	EntityBase();
};


#endif	//__ENTITY_BASE_H__

