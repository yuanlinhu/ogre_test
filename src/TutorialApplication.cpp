/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/
-----------------------------------------------------------------------------
*/

#include "TutorialApplication.h"
#include "Example25FrameListener.h"
//#include "Example41.h"
//#include "ShrewMouceManager.h"
#include "EntityBaseManager.h"
#include "EntityBase.h"
//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
	mSinbadEntity = NULL;

	mSinbadNode = NULL;

	mFrameListener = NULL;

	mEntityBaseManager = NULL;
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
	if(NULL != mFrameListener) 
	{
		delete mFrameListener;
		mFrameListener = NULL;
	}

}

//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
	mEntityBaseManager = new EntityBaseManager(mSceneMgr);
	mEntityBaseManager->loadEntity();
	//mMiceManager = new ShrewMouseManager(mSceneMgr);
    // Create your scene here :)
	//自然光
	mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));

	//设置地面
	createPlane();

	createGrass();

	//设置光源
	createLight();


	//设置实体
	createEntity();

	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);
	return;
	
}


void TutorialApplication::loadCsv()
{
}

void TutorialApplication::createPlane()
{
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, -10);

	Ogre::MeshManager::getSingleton().createPlane("plane",
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
		1500, 1500, 200,200,true, 1,5,5,Ogre::Vector3::UNIT_Z);

	Ogre::Entity* planeEntity = mSceneMgr->createEntity("LightPlaneEntity", "plane");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(planeEntity);
	planeEntity->setMaterialName("Examples/BeachStones");
	//planeEntity->setMaterialName("Examples/egyptrockyfull");
	

	/*
	Ogre::Entity* grassEntity = mSceneMgr->createEntity("GrassPlane", "plane");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(grassEntity);
	grassEntity->setMaterialName("Examples/clouds");
	*/
}

void TutorialApplication::createLight()
{
	Ogre::Light* light = mSceneMgr->createLight("light1");
	light->setType(Ogre::Light::LT_DIRECTIONAL);
	light->setDirection(Ogre::Vector3(1,-1,0));

	//Ogre::Light* mainLight = mSceneMgr->createLight("MainLight");
	//mainLight->setPosition(20, 80, 50);

	/*
	Ogre::Light* light3 = mSceneMgr->createLight("Light3");
	light3->setType(Ogre::Light::LT_DIRECTIONAL);
	light3->setDiffuseColour(Ogre::ColourValue(1,1,1));
	light3->setDirection(Ogre::Vector3(1,-1,0));
	return;

	Ogre::Light* light1 = mSceneMgr->createLight("Light1");
	light1->setType(Ogre::Light::LT_POINT);
	light1->setPosition(20,20,0);
	light1->setDiffuseColour(0,0,1);

	Ogre::SceneNode* light1Node = mSceneMgr->getRootSceneNode()->createChildSceneNode("light1Node");
	//light1Node->attachObject(light1);

	Ogre::Light* light2 = mSceneMgr->createLight("Light2");
	light2->setType(Ogre::Light::LT_SPOTLIGHT);
	light2->setDirection(Ogre::Vector3(1, -1, 0));
	light2->setSpotlightInnerAngle(Ogre::Degree(5.0f));
	light2->setSpotlightOuterAngle(Ogre::Degree(45.0f));
	light2->setSpotlightFalloff(0);
	light2->setDiffuseColour(Ogre::ColourValue(0,1,0));

	Ogre::SceneNode* light2Node = mSceneMgr->getRootSceneNode()->createChildSceneNode("light2Node");
	//light2Node->attachObject(light2);
	*/

}

void TutorialApplication::createEntity()
{
	EntityBase* newEntity = mEntityBaseManager->createEntity(1);
	mSinbadEntity = newEntity->getEntity();
	mSinbadNode = newEntity->getSceneNode();
	/*
	Ogre::SceneNode* node1 = mSceneMgr->createSceneNode("node1");

	Ogre::SceneNode* nodeRoot = mSceneMgr->getRootSceneNode();
	nodeRoot->addChild(node1);

	Ogre::Entity* Sword1 = mSceneMgr->createEntity("Sword1", "Sword.mesh");
	Ogre::Entity* Sword2 = mSceneMgr->createEntity("Sword2", "Sword.mesh");
	Ogre::Entity* sinbadEntity = mSceneMgr->createEntity("sinbadEntity", "Sinbad.mesh");
	mSinbadNode = node1->createChildSceneNode("mSinbadNode");
	mSinbadNode->setScale(3,3,3);
	mSinbadNode->setPosition(Ogre::Vector3(0,4,0));
	sinbadEntity->attachObjectToBone("Handle.L", Sword1);
	sinbadEntity->attachObjectToBone("Handle.R", Sword2);

	mSinbadNode->attachObject(sinbadEntity);

	mSinbadEntity = sinbadEntity;

	ani_vec.clear();
	*/

	/*
	Ogre::AnimationStateSet* as_set = sinbadEntity->getAllAnimationStates();
	Ogre::AnimationStateIterator  iter = as_set->getAnimationStateIterator();
	while (iter.hasMoreElements())
	{
		ani_vec.push_back(iter.getNext()->getAnimationName());
		//std::cout<<"has more "<<iter.getNext()->getAnimationName()<<std::endl;
	}
	int ii = 0;
	*/




	/*
	Ogre::Entity* ent = mSceneMgr->createEntity("head", "ogrehead.mesh");
	ent->setMaterialName("droplet");

	Ogre::SceneNode* ogreHeadNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	ogreHeadNode->setPosition(Ogre::Vector3(100,4,0));
	ogreHeadNode->attachObject(ent);
	*/

	/*
	Ogre::Entity* entity1 = mSceneMgr->createEntity("entity1", "Sinbad.mesh");
	Ogre::Entity* entity2 = mSceneMgr->createEntity("entity2", "ninja.mesh");
	Ogre::Entity* entity3 = mSceneMgr->createEntity("entity3", "sphere.mesh");

	Ogre::SceneNode* nodeRoot = mSceneMgr->getRootSceneNode();
	Ogre::SceneNode* node1 = mSceneMgr->createSceneNode("node1");
	Ogre::SceneNode* node2 = mSceneMgr->createSceneNode("node2");
	Ogre::SceneNode* node3 = mSceneMgr->createSceneNode("node3");


	node1->setScale(3,3,3);
	node1->setPosition(Ogre::Vector3(0, 4, 0));

	node2->setScale(0.02f, 0.02f, 0.02f);
	node2->setPosition(0, 10, 0);

	node3->setScale(0.02f, 0.02f, 0.02f);
	node3->setPosition(0, 30, 0);

	nodeRoot->addChild(node1);
	node1->addChild(node2);
	nodeRoot->addChild(node3);


	node1->attachObject(entity1);
	//node2->attachObject(entity2);
	//node3->attachObject(entity3);


	//node2->pitch(Ogre::Radian(Ogre::Math::HALF_PI));
	//node2->translate(20, 0, 0);
	*/
}

void TutorialApplication::createCamera( void )
{
	mCamera = mSceneMgr->createCamera("MyCamera1");

	mCamera->setPosition(0, 100, 200);
	mCamera->lookAt(0,0,0);
	mCamera->setNearClipDistance(15);

	mCameraMan = new OgreBites::SdkCameraMan(mCamera);   // Create a default camera controller
}

void TutorialApplication::createViewports( void )
{
	Ogre::Viewport* vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
	mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth())/ Ogre::Real(vp->getActualHeight()));
}

void TutorialApplication::createFrameListener( void )
{
	BaseApplication::createFrameListener();

	mFrameListener = new Example25FrameListener(mSinbadEntity, mSinbadNode, mKeyboard, mCamera, mMouse);
	mRoot->addFrameListener(mFrameListener);
}

void TutorialApplication::createGrass()
{
	
	Ogre::ManualObject* manual = mSceneMgr->createManualObject("grass");
	manual->begin("Examples/GrassBlades", Ogre::RenderOperation::OT_TRIANGLE_LIST);


	
	manual->position(5.0, 0, 0);
	manual->textureCoord(1,1);
	
	manual->position(-5.0, 10, 0);
	manual->textureCoord(0,0);
	
	manual->position(-5.0, 0, 0);
	manual->textureCoord(0,1);

	manual->position(5.0, 0, 0);
	manual->textureCoord(1,1);

	manual->position(5.0, 10, 0);
	manual->textureCoord(1,0);

	manual->position(-5.0, 10, 0);
	manual->textureCoord(0,0);
	
	
	manual->end();

	Ogre::SceneNode* grassNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("grassNode2");
	grassNode->attachObject(manual);

	
}


//---------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;
		//Example41 app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBoxA(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
