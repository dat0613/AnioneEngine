#include "stdafx.h"
#include "InputManager.h"
#include <Windows.h>
#include "Camera.h"

std::vector<KeyState *> InputManager::keyStateVector = std::vector<KeyState *>();
D3DXVECTOR2 InputManager::mousePosition = { 0.0f, 0.0f };
HWND InputManager::hWnd = HWND();

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Init(HWND hWnd)
{
	InputManager::hWnd = hWnd;

	keyStateVector.resize(static_cast<int>(KeyCode::MAX));
	AddKey(KeyCode::W, 'W');
	AddKey(KeyCode::A, 'A');
	AddKey(KeyCode::S, 'S');
	AddKey(KeyCode::D, 'D');
	AddKey(KeyCode::O, 'O');
	AddKey(KeyCode::P, 'P');

	AddKey(KeyCode::Space, VK_SPACE);

	AddKey(KeyCode::mouse0, VK_LBUTTON);
	AddKey(KeyCode::mouse1, VK_RBUTTON);
}

void InputManager::Update()
{
	for (auto key : keyStateVector)
	{
		key->isUp = key->isDown = false;
		if (GetAsyncKeyState(key->vkCode) & 0x8000)
		{
			if (!key->isOn)
				key->isDown = true;
			key->isOn = true;
		}
		else
		{
			if (key->isOn)
				key->isUp = true;
			key->isOn = false;
		}
	}

	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(hWnd, &pos);
	mousePosition = 
	{
		static_cast<float>(pos.x) - Camera::screenWidth  * 0.5f,
		static_cast<float>(pos.y) - Camera::screenHeight * 0.5f
	};

	mousePosition += Camera::position;
}

void InputManager::AddKey(KeyCode keyCode, int vkCode)
{
	keyStateVector[static_cast<int>(keyCode)] = new KeyState(vkCode);
}

bool InputManager::GetKey(KeyCode keyCode)
{
	return keyStateVector[static_cast<int>(keyCode)]->isOn;
}

bool InputManager::GetKeyDown(KeyCode keyCode)
{
	return keyStateVector[static_cast<int>(keyCode)]->isDown;
}

bool InputManager::GetKeyUp(KeyCode keyCode)
{
	return keyStateVector[static_cast<int>(keyCode)]->isUp;
}