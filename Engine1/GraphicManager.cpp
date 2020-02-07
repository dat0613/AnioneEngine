#include "stdafx.h"
#include "GraphicManager.h"
#include "GameManager.h"
#include "Scene.h"
#include "Animation.h"

LPDIRECT3DDEVICE9 GraphicManager::device = nullptr;
std::map<std::string, LPDIRECT3DTEXTURE9> GraphicManager::textureMap = std::map<std::string, LPDIRECT3DTEXTURE9>();
LPD3DXSPRITE GraphicManager::sprite = nullptr;


GraphicManager::GraphicManager()
{
}


GraphicManager::~GraphicManager()
{
}

void GraphicManager::Init(LPDIRECT3DDEVICE9 device)
{
	GraphicManager::device = device;

	D3DXCreateSprite(device, &sprite);

	//testTexture = CreateTexture(L"TestImage.png");
	AddTexture("TestImage", L"TestImage.png");
	AddTexture("TestAnimation", L"TestAnimation.png");
}

void GraphicManager::AddTexture(std::string textureName, LPCWSTR fileName)
{
	auto pair = textureMap.find(textureName);
	if (pair == textureMap.end())
	{
		auto tex = CreateTexture(fileName);

		textureMap.insert(std::make_pair(textureName, tex));
	}
}

LPDIRECT3DTEXTURE9 GraphicManager::GetTexture(std::string textureName)
{
	auto pair = textureMap.find(textureName);
	if (pair == textureMap.end())
	{
		return nullptr;
	}

	return pair->second;
}

LPDIRECT3DTEXTURE9 GraphicManager::CreateTexture(LPCWSTR fileName)
{
	LPDIRECT3DTEXTURE9 tex;

	D3DXCreateTextureFromFileEx(
		device,
		fileName,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		1,
		1,
		NULL,
		NULL,
		NULL,
		&tex);

	return tex;
}

void GraphicManager::Render()
{
	auto objList = GameManager::nowScene->GetObjectList();
	for (auto obj : objList)
	{
		Render(obj);
	}
}

void GraphicManager::Render(GameObject * object)
{
	auto tex = GetTexture(object->animation->textureName);

	if (tex == nullptr)
		return;

	D3DXMATRIX matrix, positionMatrix;

	D3DXMatrixTranslation(&positionMatrix, 0.0f, 0.0f, 0.0f);

	matrix = positionMatrix;

	RECT rc = object->animation->GetRect();

	sprite->SetTransform(&matrix);
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(tex, &rc, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	sprite->End();
}

D3DXVECTOR2 GraphicManager::GetTextureSize(LPDIRECT3DTEXTURE9 texture)
{
	D3DSURFACE_DESC de;

	texture->GetLevelDesc(0, &de);

	return D3DXVECTOR2(de.Width, de.Height);
}

D3DXVECTOR2 GraphicManager::GetTextureSize(std::string textrueName)
{
	auto tex = GetTexture(textrueName);
	return GetTextureSize(tex);
}
