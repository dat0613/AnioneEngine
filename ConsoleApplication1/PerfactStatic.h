#pragma once
#include <iostream>

using namespace std;

static class PerfactStatic
{
public:
	PerfactStatic();
	~PerfactStatic();

	void DoSomeThing2()
	{
		cout << __FUNCTION__ << endl;
	}

	static void DoSomeThing()
	{
		cout << __FUNCTION__ << endl;
	}

};