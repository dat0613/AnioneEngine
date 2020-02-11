#include "stdafx.h"
#include "BoxCollider.h"
#include "GameObject.h"

BoxCollider::BoxCollider() :
	size({ 100.0f, 100.0f }),
	isTrigger(false),
	isUI(false)
{
}

BoxCollider::~BoxCollider()
{
}

RECT BoxCollider::GetRect()
{
	RECT rect;

	rect.left	= parent->position.x - size.x * 0.5f;
	rect.right	= parent->position.x + size.x * 0.5f;

	rect.top	= parent->position.y - size.y * 0.5f;
	rect.bottom = parent->position.y + size.y * 0.5f;

	return rect;
}
