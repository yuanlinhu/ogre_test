/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
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

#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"


/*
TODO:

1. ���� uid
2. �ع� createEntity ���ɶ��ʵ�� ������ԾŹ���
3. ��������
4. WorldCore ��д







*/


class EntityBaseManager;
//---------------------------------------------------------------------------

class TutorialApplication : public BaseApplication
{
public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);

protected:
    virtual void createScene(void);
	virtual void createCamera(void);
	virtual void createViewports(void);
	virtual void createFrameListener(void);
	//virtual void chooseSceneManager(void);

private:
	void loadCsv();
	void createManual();
	void createPlane();
	void createLight();
	void createEntity();
	void createGrass();

	//���� �ǿ���ʵ��
	void createMonster();

private:
	Ogre::Entity*		mSinbadEntity;
	Ogre::SceneNode*		mSinbadNode;
	Ogre::FrameListener*	mFrameListener;

	EntityBaseManager*		mEntityBaseManager;

private:
	//ShrewMouseManager* mMiceManager;
};

//---------------------------------------------------------------------------

#endif // #ifndef __TutorialApplication_h_

//---------------------------------------------------------------------------
