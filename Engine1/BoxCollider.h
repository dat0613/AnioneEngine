#pragma once

#include <d3dx9.h>

class GameObject;

class BoxCollider
{
public:
	BoxCollider();
	~BoxCollider();

	RECT GetRect();

	GameObject * parent;

	D3DXVECTOR2 size;
	bool isTrigger;
	bool isUI;
};

