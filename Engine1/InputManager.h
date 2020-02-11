#pragma once

#include <vector>
#include <d3dx9.h>
class KeyState
{
public:

	int vkCode;
	bool isOn;		// 키가 계속 눌리고 있을 떄
	bool isDown;	// 키가 한번 눌렸는가
	bool isUp;		// 키가 떼여 젔는가

	KeyState(int vkCode) : 
		vkCode(vkCode),
		isOn(false), 
		isDown(false), 
		isUp(false)
	{

	}
};

static class InputManager
{
public:
	InputManager();
	~InputManager();

	static void Init(HWND hWnd);
	static void Update();

	static D3DXVECTOR2 mousePosition;

	static std::vector<KeyState *> keyStateVector;

	static HWND hWnd;

	enum class KeyCode { W, A, S, D, Space, mouse0, mouse1, O, P, MAX };

	static void AddKey(KeyCode keyCode, int vkCode);
 
	static bool GetKey(KeyCode keyCode);
	static bool GetKeyDown(KeyCode keyCode);
	static bool GetKeyUp(KeyCode keyCode);


};

