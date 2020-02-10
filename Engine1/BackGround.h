#pragma once
#include "GameObject.h"
class BackGround :
	public GameObject
{
public:
	BackGround();
	~BackGround();

	void Awake() override;
};

