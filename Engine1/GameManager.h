#pragma once

#include <d3d9.h>

class Scene;

static class GameManager
{
public:
	
	static void Init(HWND hWnd);
	static void Update();
	static void Render();

	static Scene * nowScene;

	GameManager();
	~GameManager();

private:

	static LPDIRECT3D9 g_pD3D;
	static LPDIRECT3DDEVICE9 g_pd3dDevice;
};