#include "stdafx.h"
#include "Animation.h"
#include "GraphicManager.h"


void Animation::Update()
{
	if (timePerFrame < 0)
		return;

	auto curTime = clock();

	if (lastChangeTime + timePerFrame < curTime)
	{
		lastChangeTime = curTime;

		if (nowFrame.x + frameSize.x + 1.0f >= imageSize.x)
		{
			nowFrame.x = 0;
		}
		else
		{
			nowFrame.x += frameSize.x;
		}
	}
}

void Animation::SetAnimation(std::string textureName)
{
	this->textureName = textureName;
	imageSize = GraphicManager::GetTextureSize(textureName);

	lastChangeTime = clock();

	if (textureName == "TestAnimation")
	{
		// clock_t단위는 1초에 1000 ms
		timePerFrame = 100;
		frameSize = { 100, 100 };
	}
}

RECT Animation::GetRect()
{
	int left = nowFrame.x;
	int top = 0;
	int right = left + frameSize.x;
	int bottom = top + frameSize.y;

	return RECT { left, top, right, bottom };
}

Animation::Animation() : 
	textureName(""), 
	imageSize({ 0.0f, 0.0f }),
	frameSize({ 0.0f, 0.0f }),
	nowFrame({ 0.0f, 0.0f }),
	lastChangeTime(0),
	timePerFrame(-1)
{
}

Animation::~Animation()
{
}