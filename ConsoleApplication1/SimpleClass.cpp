#include "SimpleClass.h"

SimpleClass::SimpleClass()
{
}

SimpleClass::~SimpleClass()
{
}

void SimpleClass::SetName(std::string name)
{
	this->name = name;

	this->DoSomething();
	DoSomething();
}

void SimpleClass::SetAge(int age)
{
	this->age = age;
}

void SimpleClass::DoSomething()
{
	DoSomething();
}