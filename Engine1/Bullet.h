#pragma once
#include "GameObject.h"

#include <ctime>

class Bullet :
	public GameObject
{
public:
	Bullet();
	~Bullet();

	D3DXVECTOR2 direction;// ����
	float speed;// �����̴� �ӵ�

	clock_t spawnTime;
	clock_t aliveTime;

	void Awake() override;
	void Update() override;
	void OnCollisionEnter(GameObject * gameObject) override;

	void SetOption(D3DXVECTOR2 direction, float speed);
};

