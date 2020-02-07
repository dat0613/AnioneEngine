#pragma once

#include <iostream>

class Base
{
public:
	Base();
	~Base();

	virtual void Update()
	{
		std::cout << "BaseÀÇ Update" << std::endl;
	}
};

