#pragma once

#include <d3dx9.h>
#include <ctime>
#include <string>

class GameObject;

class Animation
{
public:

	std::string textureName;

	GameObject * parent;

	D3DXVECTOR2 imageSize;// �ִϸ��̼� �̹����� ��üũ��
	D3DXVECTOR2 frameSize;// �� �������� ������
	D3DXVECTOR2 nowFrame;// ���� �������� ��ġ

	clock_t lastChangeTime;// ���� �ֱ� ������ ���� �ð�
	clock_t timePerFrame;// �� �����Ӵ� �ð�

	void Update();
	void SetAnimation(std::string textureName);
	RECT GetRect();


	Animation();
	~Animation();
};

