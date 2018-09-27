#pragma once

#include "Problem.h"
#include <string>
#include <map>
#include <functional>

std::map<int, Problem> Problems1_25();
std::map<int, Problem> Problems26_50();
std::map<int, Problem> Problems51_75();



static std::map<int, Problem> Problems()
{
    std::map<int, Problem> problems = Problems1_25();
    std::map<int, Problem> nextProblems = Problems26_50();
    problems.insert(nextProblems.begin(), nextProblems.end());
    nextProblems = Problems51_75();
    problems.insert(nextProblems.begin(), nextProblems.end());
    return problems;
}



#define ProblemStart(number, description) \
    {number, Problem(number, string(description), \
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