#include "stdafx.h"
#include "TestObject.h"

#include "Animation.h"
#include "InputManager.h"
#include "Camera.h"
#include "Scene.h"
#include "Bullet.h"

#include "GraphicManager.h"

TestObject::TestObject()
{
}


TestObject::~TestObject()
{
}

void TestObject::Awake()
{
	name = "Player";
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

void TestObject::OnDestroy()
{
	GameManager::nowScene->nextSceneName = "Main";
}

void TestObject::OnRender()
{
	GraphicManager::RenderText("안녕하세요 테스트 입니다", position);
}

void TestObject::OnCollisionEnter(GameObject * gameObject)
{
	if (gameObject->name == "Enemy")
	{
		isActive = false;
		gameObject->isActive = false;
	}
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

	diff.x /= Camera::scale.x;
	diff.y /= Camera::scale.y;

	Camera::position += (diff * 0.05f);

	if (InputManager::GetKey(InputManager::KeyCode::O))
	{
		float scale = Camera::scale.x;

		scale += scale * 0.01f;

		Camera::scale.x = Camera::scale.y = scale;
	}

	if (InputManager::GetKey(InputManager::KeyCode::P))
	{
		float scale = Camera::scale.x;

		scale -= scale * 0.01f;

		Camera::scale.x = Camera::scale.y = scale;
	}
}
