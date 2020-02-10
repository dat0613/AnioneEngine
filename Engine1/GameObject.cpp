#include "stdafx.h"
#include "GameObject.h"
#include "Animation.h"

GameObject::GameObject() : 
	position({ 0.0f, 0.0f }),
	scale({ 1.0f, 1.0f }),
	degree(0.0f),
	isActive(true),
	sortingLayer(0)
{
	animation = new Animation();
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

void GameObject::UpdateAnimation()
{
	animation->Update();
}
