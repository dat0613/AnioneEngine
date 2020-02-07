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
		std::cout << "childÀÇ Update" << std::endl;
	}
};

