#include "stdafx.h"
#include "GraphicManager.h"
#include "GameManager.h"
#include "Scene.h"
#include "Animation.h"
#include "Camera.h"

LPDIRECT3DDEVICE9 GraphicManager::device = nullptr;
std::map<std::string, LPDIRECT3DTEXTURE9> GraphicManager::textureMap = std::map<std::string, LPDIRECT3DTEXTURE9>();
LPD3DXSPRITE GraphicManager::sprite = nullptr;
ID3DXFont * GraphicManager::font = nullptr;

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
	D3DXCreateFont
	(
		device,
		30,
		0,
		FW_EXTRABOLD,
		1,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		L"±¼¸²Ã¼",
		&font
	);

	AddTexture("TestImage", L"./Resource/Image/TestImage.png");
	AddTexture("TestAnimation", L"./Resource/Image/TestAnimation.png");
	AddTexture("BackGround", L"./Resource/Image/BackGround.png");
	AddTexture("Bullet", L"./Resource/Image/Bullet.png");
	AddTexture("Enemy", L"./Resource/Image/Enemy.png");

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

	//objList.sort(compare);

	objList.sort([](GameObject * o1, GameObject * o2)
	{
		if (o1->sortingLayer < o2->sortingLayer)
			return true;
		return false;
	});

	for (auto obj : objList)
	{
		Render(obj);
	}
}

void GraphicManager::Render(GameObject * object)
{
	auto tex = GetTexture(object->animation->textureName);
	auto frameSize = object->animation->frameSize;

	if (tex == nullptr)
		return;

	D3DXMATRIX matrix, positionMatrix, centerMatrix, rotateMatrix, scaleMatrix;

	D3DXMatrixTranslation(&positionMatrix, object->position.x, object->position.y, 0.0f);
	D3DXMatrixTranslation(&centerMatrix, -frameSize.x * 0.5f, -frameSize.y * 0.5f, 0.0f);

	D3DXMatrixRotationZ(&rotateMatrix, D3DXToRadian(object->degree));

	D3DXMatrixScaling(&scaleMatrix, object->scale.x, object->scale.y, 0.0f);

	matrix = centerMatrix * scaleMatrix * rotateMatrix * positionMatrix;
	//matrix = centerMatrix * positionMatrix;

	matrix *= Camera::matrix;

	RECT rc = object->animation->GetRect();

	sprite->SetTransform(&matrix);
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(tex, &rc, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	sprite->End();

	object->OnRender();
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

bool GraphicManager::compare(GameObject * o1, GameObject * o2)
{
	if (o1->sortingLayer < o2->sortingLayer)
		return true;
	return false;
}

void GraphicManager::RenderText(std::string str, D3DXVECTOR2 position)
{
	RECT rc;
	rc.left = position.x + Camera::screenWidth * 0.5f - Camera::position.x;
	rc.top = position.y + Camera::screenHeight * 0.5f - Camera::position.y;
	rc.right = Camera::screenWidth;
	rc.bottom = Camera::screenHeight;

	font->DrawTextA(NULL, str.c_str(), -1, &rc, DT_NOCLIP, D3DCOLOR_XRGB(0, 0, 0));
}