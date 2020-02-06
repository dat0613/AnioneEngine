#pragma once

#include <list>
#include <d3dx9.h>
#include "GameObject.h"
#include "GameManager.h"


class Scene
{
public:
	Scene();
	~Scene();

	void AddGameObject(GameObject * obj);
	void Update();

private:
	std::list<GameObject *> objectList;
};

template <class T>
T * Instantiate(D3DXVECTOR2 position)
{
	auto obj = new T();
	auto gameObject = dynamic_cast<GameObject *>(obj);
	if (gameObject == nullptr)
	{
		delete obj;
		return nullptr;
	}

	GameManager::nowScene->AddGameObject(obj);

	gameObject->position = position;
	return gameObject;
}