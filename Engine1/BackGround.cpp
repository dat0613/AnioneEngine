#include "stdafx.h"
#include "BackGround.h"

#include "Animation.h"

BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

void BackGround::Awake()
{
	animation->SetAnimation("BackGround");
}