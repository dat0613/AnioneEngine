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
	void OnDestroy() override;
	void OnRender() override;

	void OnCollisionEnter(GameObject * gameObject) override;

private:

	void PlayerMove();
	void MouseInput();
	void CameraMove();
};

