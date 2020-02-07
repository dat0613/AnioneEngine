#include "stdafx.h"
#include "TestObject.h"

#include "Animation.h"

TestObject::TestObject()
{
}


TestObject::~TestObject()
{
}

void TestObject::Awake()
{
	animation->SetAnimation("TestAnimation");
}

void TestObject::Update()
{

}
