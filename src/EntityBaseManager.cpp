
#include "EntityBaseManager.h"
#include "EntityBase.h"
#include "EntityCsvManager.h"
#include "EntityCsv.h"

EntityBaseManager::EntityBaseManager(Ogre::SceneManager* sceneMgr)
{
	mSceneManager = sceneMgr;
	mEntityCsvManager = new EntityCsvManager();

	maxIndex = 0;
}

EntityBaseManager::~EntityBaseManager()
{

}


void EntityBaseManager::loadEntity()
{
	mEntityCsvManager->loadFile();
}


EntityBase* EntityBaseManager::createEntity(int id)
{
	EntityCsv* entityCsv = mEntityCsvManager->getEntityCsvById(id);

	maxIndex++;
	std::stringstream ss("entity");
	ss<<entityCsv->id;
	std::string entityName;
	ss>>entityName;

	Ogre::Entity* newEntity = mSceneManager->createEntity(entityName, entityCsv->mesh_name);
	Ogre::SceneNode* newNode = mSceneManager->getRootSceneNode()->createChildSceneNode(entityName);

	newNode->setScale(Ogre::Vector3(entityCsv->scale_x, entityCsv->scale_y, entityCsv->scale_z));
	newNode->setPosition(Ogre::Vector3(entityCsv->pos_x, entityCsv->pos_y, entityCsv->pos_z));
	newNode->attachObject(newEntity);

	EntityBase* newEntityBase = new EntityBase(entityCsv, newEntity, newNode);

	this->addEntity(id, newEntityBase);

	return newEntityBase;
}

void EntityBaseManager::addEntity( int id, EntityBase* entity )
{
	mEntityManager[id] = entity;
}
