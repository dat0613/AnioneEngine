#pragma once

#include <iostream>

class Base
{
public:
	Base();
	~Base();

	virtual void Update()
	{
		std::cout << "Base�� Update" << std::endl;
	}
};

