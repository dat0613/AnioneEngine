#include "stdafx.h"
#include "Bullet.h"
#include "Animation.h"

Bullet::Bullet() :
	direction({ 0.0f, 0.0f }),
	speed(0.0f),
	spawnTime(clock()),
	aliveTime(3000)
{
}

Bullet::~Bullet()
{
}

void Bullet::Awake()
{
	animation->SetAnimation("Bullet");
}

void Bullet::Update()
{
	position += direction * speed;

	if (clock() - spawnTime > aliveTime)
	{
		isActive = false;
	}
}

void Bullet::SetOption(D3DXVECTOR2 direction, float speed)
{
	degree = D3DXToDegree(atan2(direction.y, direction.x));
	this->direction = direction;
	this->speed = speed;
}
