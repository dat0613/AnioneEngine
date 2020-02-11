#pragma once
#include "GameObject.h"

class TestObject;

class Enemy :
	public GameObject
{
public:
	Enemy();
	~Enemy();

	void Awake() override;
	void OnDestroy() override;
	void Update() override;

private:

	TestObject * target;
	
};

