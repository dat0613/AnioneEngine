#pragma once

#include <iostream>

using namespace std;

class SemiStatic
{
public:
	SemiStatic();
	~SemiStatic();


	static void DoSomeThing()
	{
		cout << __FUNCTION__ << endl;
	}

	void DoSomeThing2()
	{
		cout << __FUNCTION__ << endl;
	}
};

