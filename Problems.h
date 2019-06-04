#pragma once

#include "ProblemLambda.h"
#include <string>
#include <map>
#include <functional>

std::map<int, ProblemLambda> Problems1_25();
std::map<int, ProblemLambda> Problems26_50();
std::map<int, ProblemLambda> Problems51_75();

extern std::map<int, ProblemLambda> allProblems;

static std::map<int, ProblemLambda> Problems()
{
    std::map<int, ProblemLambda> problems = Problems1_25();
    std::map<int, ProblemLambda> nextProblems = Problems26_50();
    problems.insert(nextProblems.begin(), nextProblems.end());
    //nextProblems = Problems51_75();
    //problems.insert(nextProblems.begin(), nextProblems.end());
    return problems;
}



static std::map<int, ProblemLambda> GetProblems()
{
    allProblems = Problems();
    void P1(); P1();
    void P29(); P29();
    void P54(); P54();
    //void P67(); P67();
    return allProblems;
}

static void AddProblem(ProblemLambda p)
{
    allProblems.insert(make_pair(p.Number(), p));
}

#define ProblemStart(number, description) \
    {number, ProblemLambda(number, description, \
    []() -> std::string { \
    int64_t answer = 0;

#define ProblemEnd \
    return to_string(answer); \
}) \
},

#define ProblemEndLast \
    return to_string(answer); \
}) \
}