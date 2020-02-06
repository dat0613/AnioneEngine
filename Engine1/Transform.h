#pragma once
#include "Component.h"

#include <d3dx9.h>

class Transform :
	public Component
{
public:
	Transform();
	~Transform();

	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	float degree;

};

