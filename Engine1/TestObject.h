#pragma once
#include "GameObject.h"
class TestObject :
	public GameObject
{
public:
	TestObject();
	~TestObject();

	void Awake() override;
	void Update() override;
	void LateUpdate() override;

private:

	void PlayerMove();
	void MouseInput();
	void CameraMove();
};

