#pragma once

#include <string>

class SimpleClass
{
public:

	SimpleClass();
	~SimpleClass();

	void SetName(std::string name);
	void SetAge(int age);
	void DoSomething();

private:

	std::string name;
	int age;

};