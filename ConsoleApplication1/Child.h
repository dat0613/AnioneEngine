#pragma once
#include "Base.h"
class Child :
	public Base
{
public:
	Child();
	~Child();

	void Update() override
	{
		Base::Update();
		std::cout << "child�� Update" << std::endl;
	}
};

