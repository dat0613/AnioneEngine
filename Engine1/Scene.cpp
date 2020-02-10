#include "stdafx.h"
#include "Scene.h"
#include <vector>


Scene::Scene()
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

void Scene::Update()
{
	for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
	{
		auto obj = *iter;

		if (!obj->isActive)
		{
			obj->OnDestroy();
			objectList.erase(iter--);
			delete obj;
		}
		else
		{
			obj->Update();
			obj->UpdateAnimation();
		}
	}

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

		for (int j = i; j < size; j++)
		{
			auto obj2 = vec[j];

			if (obj1 == obj2)
				continue;

			if()
		}
	}
}
