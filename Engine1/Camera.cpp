#include "stdafx.h"
#include "Camera.h"

int Camera::screenWidth = 1280;
int Camera::screenHeight = 720;

D3DXVECTOR2 Camera::position = { 0.0f, 0.0f };
D3DXVECTOR2 Camera::scale = { 1.0f, 1.0f };

float Camera::degree = 0.0f;


D3DXMATRIX Camera::matrix = D3DXMATRIX();

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
	D3DXMATRIX centerMatrix, positionMatrix, scaleMatrix, rotateMatrix;

	D3DXMatrixTranslation(&positionMatrix, -position.x, -position.y, 0.0f);
	D3DXMatrixTranslation(&centerMatrix, screenWidth * 0.5f, screenHeight * 0.5f, 0.0f);
	D3DXMatrixScaling(&scaleMatrix, scale.x, scale.y, 0.0f);
	D3DXMatrixRotationZ(&rotateMatrix, D3DXToRadian(degree));

	matrix = scaleMatrix * rotateMatrix * positionMatrix * centerMatrix;
}