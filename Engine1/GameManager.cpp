#include "GameManager.h"

#include "GraphicManager.h"
#include "Camera.h"
#include "Scene.h"
#include "TestObject.h"
#include "BackGround.h"
#include "Enemy.h"

#include "InputManager.h"

LPDIRECT3D9 GameManager::g_pD3D = LPDIRECT3D9();
LPDIRECT3DDEVICE9 GameManager::g_pd3dDevice = LPDIRECT3DDEVICE9();
Scene * GameManager::nowScene = nullptr;


void GameManager::Init(HWND hWnd)
{
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferWidth = Camera::screenWidth;
	d3dpp.BackBufferHeight = Camera::screenHeight;

	g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice);

	GraphicManager::Init(g_pd3dDevice);
	InputManager::Init(hWnd);

	nowScene = new Scene();

	Instantiate<Enemy>({ 500, 500 });
	Instantiate<Enemy>({ -500, 500 });
	Instantiate<Enemy>({ 500, -500 });
	Instantiate<Enemy>({ -500, -500 });

	Instantiate<TestObject>({ 0.0f, 0.0f });
	Instantiate<BackGround>({ 0.0f, 0.0f });
}

void GameManager::Update()
{
	InputManager::Update();
	nowScene->Update();
	Camera::Update();
}

void GameManager::Render()
{
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(70, 70, 70), 1.0f, 0);
	//g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(rand() % 360, rand() % 360, rand() % 360), 1.0f, 0);


	g_pd3dDevice->BeginScene();

	// 오브젝트 렌더링

	GraphicManager::Render();


	g_pd3dDevice->EndScene();


	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}
