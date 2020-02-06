#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject() : 
	position({ 0.0f, 0.0f }), 
	scale({ 0.0f, 0.0f }),
	degree(0.0f), 
	isActive(true)
{
}

GameObject::~GameObject()
{
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
