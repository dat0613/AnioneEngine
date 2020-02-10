#include "stdafx.h"
#include "TestObject.h"

#include "Animation.h"
#include "InputManager.h"
#include "Camera.h"
#include "Scene.h"
#include "Bullet.h"

TestObject::TestObject()
{
}


TestObject::~TestObject()
{
}

void TestObject::Awake()
{
	animation->SetAnimation("TestAnimation");
	position = { 0.0f, 0.0f };
	sortingLayer = 1;
}

void TestObject::Update()
{
	PlayerMove();
	MouseInput();
}

void TestObject::LateUpdate()
{
	CameraMove();
}

void TestObject::PlayerMove()
{
	if (InputManager::GetKey(InputManager::KeyCode::W))
	{
		position.y -= 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::S))
	{
		position.y += 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::A))
	{
		position.x -= 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::D))
	{
		position.x += 5.0f;
	}
}

void TestObject::MouseInput()
{
	auto mousePosition = InputManager::mousePosition;
	
	auto diff = mousePosition - position;

	auto radian = atan2(diff.y, diff.x);

	degree = D3DXToDegree(radian);
	
	D3DXVECTOR2 normal;

	D3DXVec2Normalize(&normal, &diff);

	if (InputManager::GetKeyDown(InputManager::KeyCode::mouse0))
	{
		auto bullet = Instantiate<Bullet>(position);
		if (bullet != nullptr)
		{
			bullet->SetOption(normal, 10.0f);
		}
	}
}

void TestObject::CameraMove()
{
	auto diff = position - Camera::position;

	Camera::position += (diff * 0.05f);
}
