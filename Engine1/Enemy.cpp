#include "stdafx.h"
#include "Enemy.h"

#include "Animation.h"

#include "TestObject.h"

#include "Camera.h"

Enemy::Enemy() : 
	target(nullptr)
{
}


Enemy::~Enemy()
{
}

void Enemy::Awake()
{
	name = "Enemy";
	sortingLayer = 1;
	animation->SetAnimation("Enemy");
}

void Enemy::OnDestroy()
{
	Camera::AddShake(20);
	PlaySound(L"./Resource/Sound/Die.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void Enemy::Update()
{
	target = static_cast<TestObject *>(GameObject::Find("Player"));

	if (target == nullptr)
		return;

	auto diff = target->position - position;
	D3DXVECTOR2 result = { 0.0f, 0.0f };
	D3DXVec2Normalize(&result, &diff);

	position += result * 3.0f;
}