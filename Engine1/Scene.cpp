#include "stdafx.h"
#include "Scene.h"
#include <vector>
#include "BoxCollider.h"

#include "TestObject.h"
#include "BackGround.h"
#include "Enemy.h"

Scene::Scene() : nextSceneName("")
{
}


Scene::~Scene()
{
}

std::list<GameObject*> & Scene::GetObjectList()
{
	return objectList;
}

void Scene::AddGameObject(GameObject * obj)
{
	objectList.push_back(obj);
	obj->Awake();
}

void Scene::CheckNextScene()
{
	if (nextSceneName != "")
	{
		ChangeScene(nextSceneName);
		nextSceneName = "";
	}
}

void Scene::Update()
{
	auto iter = objectList.begin();
	while (iter != objectList.end())
	{
		auto obj = *iter;
		if (obj->isActive)
		{
			obj->Update();
			obj->UpdateAnimation();
			iter++;
		}
		else
		{
			obj->OnDestroy();
			delete obj;
			iter = objectList.erase(iter);
		}
	}
}

void Scene::LateUpdate()
{
	for (auto obj : objectList)
	{
		obj->LateUpdate();
	}
}

void Scene::CollisionCheck()
{
	auto size = objectList.size();
	if (size < 1)
		return;

	vector<GameObject *> vec(size);
	int idx = 0;
	for (auto obj : objectList)
	{
		vec[idx++] = obj;
	}


	for (int i = 0; i < size - 1; i++)
	{
		auto obj1 = vec[i];

		if (!obj1->isActive)
			continue;

		for (int j = i; j < size; j++)
		{
			auto obj2 = vec[j];

			if (!obj2->isActive)
				continue;

			if (obj1 == obj2)
				continue;

			// 충돌 체크

			// AABB			이거 쓸꺼임
			// OBB
			// 원충돌

			if (AABB(obj1, obj2))
			{// 충돌 됨
				obj1->OnCollisionEnter(obj2);
				obj2->OnCollisionEnter(obj1);
			}
		}
	}
}

void Scene::ChangeScene(std::string sceneName)
{
	for (auto obj : objectList)
	{
		obj->isActive = false;
	}

	Update();

	if (sceneName == "Main")
	{
		// 배경음 재생
		mciSendString(L"close BGM", 0, 0, 0);
		mciSendString(L"open ./Resource/Sound/BGM.wav type mpegvideo alias BGM", 0, 0, 0);
		mciSendString(L"play BGM repeat", 0, 0, 0);

		// 배경음 볼륨 관리
		mciSendString(L"setaudio BGM volume to 100", 0, 0, 0);

		// 효과음 출력
		PlaySound(L"./Resource/Sound/FileName.wav", NULL, SND_FILENAME | SND_ASYNC);

		Instantiate<TestObject>({ 0.0f, 0.0f });

		Instantiate<Enemy>({ 500, 500 });
		Instantiate<Enemy>({ -500, 500 });
		Instantiate<Enemy>({ 500, -500 });
		Instantiate<Enemy>({ -500, -500 });

		Instantiate<BackGround>({ 0.0f, 0.0f });
	}
}

bool Scene::AABB(GameObject * obj1, GameObject * obj2)
{
	RECT result;
	
	auto rect1 = obj1->collider->GetRect();
	auto rect2 = obj2->collider->GetRect();

	return IntersectRect(&result, &rect1, &rect2);
}