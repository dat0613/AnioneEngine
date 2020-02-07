#include <iostream>

#include <conio.h>

#include "PerfactStatic.h"
#include "SemiStatic.h"

#include "Child.h"

void Print(int num)
{
	cout << num << endl;
}

void Print(SemiStatic * semi)
{
	if (semi != nullptr)
		cout << semi << endl;
}

void main()
{
	auto child = new Child();

	child->Update();

	delete child;

	_getch();
}