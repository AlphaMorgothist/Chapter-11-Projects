// Chapter11Projects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Chapter11Master.h"


int main()
{
	int select;
	do {
		chapOptions();
		select = getInput();
		runSwitch(select);
	} while (select != 0);
}

