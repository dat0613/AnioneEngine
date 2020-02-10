#include "stdafx.h"
#include "BoxCollider.h"


BoxCollider::BoxCollider() :
	size({ 100.0f, 100.0f }),
	isTrigger(false),
	isUI(false)
{
}

BoxCollider::~BoxCollider()
{
}