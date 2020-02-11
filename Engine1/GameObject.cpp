#include "stdafx.h"
#include "GameObject.h"
#include "Animation.h"
#include "BoxCollider.h"

#include "GameManager.h"
#include "Scene.h"

GameObject::GameObject() : 
	position({ 0.0f, 0.0f }),
	scale({ 1.0f, 1.0f }),
	degree(0.0f),
	isActive(true),
	sortingLayer(0),
	name("None")
{
	animation = new Animation();
	collider = new BoxCollider();
	animation->parent = collider->parent = this;
}

GameObject::~GameObject()
{
	delete animation;
}

void GameObject::Awake()
{
}

void GameObject::Update()
{
}

void GameObject::LateUpdate()
{
}

void GameObject::OnDestroy()
{
}

void GameObject::OnRender()
{
}

void GameObject::OnCollisionEnter(GameObject * gameObject)
{
}

void GameObject::UpdateAnimation()
{
	animation->Update();
}

GameObject * GameObject::Find(std::string name)
{
	GameObject * result = nullptr;

	// 리스트 순회, 검색
	auto objectList = GameManager::nowScene->GetObjectList();

	for (auto gameObject : objectList)
	{
		if (gameObject->name == name)
		{
			result = gameObject;
			break;
		}
	}

	return result;
}
