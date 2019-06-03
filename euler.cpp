// euler.cpp : Defines the entry point for the console application.
//

#include "Problems.h"
#include "String.h"
#include "Stopwatch.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <tchar.h>

using namespace std;

// Global variable to hold all problems, we will add to this in GetProblems
std::map<int, ProblemLambda> allProblems;

int ParseCommandLine(int argc, char* argv[]);

void main(int argc, char* argv[])
{
	int problemNum = ParseCommandLine(argc, argv);

	GetProblems();

	cout << "Project Euler" << endl << endl;

	if(problemNum != 0)
	{
        allProblems[problemNum].Solve();
	}
    else
    {
        for (auto problem : allProblems)
        {
            problem.second.Solve();
            cout << endl;
        }
    }

	cout << "Finished." << endl;
}


// return problem number to solve, 0 for all
int ParseCommandLine(int argc, char* argv[])
{

	int iProblemNum = 0;

	if(argc > 1)
	{
		string s(argv[1]);
		iProblemNum = ToInt(s);

	}

	return iProblemNum;
}

/*
vector<Problem*> GetProblems()
{
	
	vector<Problem*> vProblems;

	for(int i = 0; i <= 150; i++)
	{
		vProblems.push_back(NULL);
	}

	vProblems[1] = new Problem1();
	vProblems[2] = new Problem2();
	vProblems[3] = new Problem3();
	vProblems[4] = new Problem4();
	vProblems[5] = new Problem5();
	vProblems[6] = new Problem6();
	vProblems[7] = new Problem7();
	vProblems[8] = new Problem8();
	vProblems[9] = new Problem9();
	vProblems[10] = new Problem10();
	vProblems[11] = new Problem11();
	vProblems[12] = new Problem12();
	vProblems[13] = new Problem13();
	vProblems[14] = new Problem14();
	vProblems[15] = new Problem15();
	vProblems[16] = new Problem16();
	vProblems[17] = new Problem17();
	vProblems[18] = new Problem18();
    vProblems[19] = new Problem19();
	vProblems[20] = new Problem20();
    vProblems[21] = new Problem21();
    vProblems[22] = new Problem22();
    vProblems[23] = new Problem23();
	vProblems[67] = new Problem67();

	return vProblems;
}*/