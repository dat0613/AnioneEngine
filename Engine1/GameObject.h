#pragma once

#include <map>
#include <list>
#include <string>

#include <d3dx9.h>

//#include <typeinfo.h>
//
//class Component;
using namespace std;

class Animation;

class GameObject
{
public:

	GameObject();
	~GameObject();

	Animation * animation;

	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	float degree;

	int sortingLayer;

	bool isActive;

	virtual void Awake();
	virtual void Update();
	virtual void LateUpdate();
	virtual void OnDestroy();

	void UpdateAnimation();

	//template<class T>
	//T * AddComponent();

	//template<class T>
	//T * GetComponent();

private:

	//std::map<std::string, Component *> componentMap;
	//std::list<Component *> componentList;
};

//template<class T>
//inline T * GameObject::AddComponent()
//{
//	auto comp = new T();
//
//	auto component = dynamic_cast<Component *>(comp);
//
//	if (component == nullptr)
//	{
//		return nullptr;
//	}
//
//	auto componentName = typeid(comp).name();
//
//	componentMap.insert(std::make_pair(componentName, comp));
//	componentList.insert(comp);
//
//	return comp;
//}
//
//template<class T>
//inline T * GameObject::GetComponent()
//{
//	auto componentName = typeid(T*).name();
//
//	auto pair = componentMap.find(componentName);
//
//	if (pair == componentMap.end())
//		return nullptr;
//
//	return pair->second;
//}