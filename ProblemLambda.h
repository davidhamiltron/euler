#ifndef PROBLEM_LAMBDA_H
#define PROBLEM_LAMBDA_H

#include <string>
#include <functional>
using namespace std;

class ProblemLambda
{
public:
    ProblemLambda() {}
    ProblemLambda(int number, const char* description, std::function<std::string()> solver);

    int Number() { return number; };
    void Solve();
    string Description() { return description; };
    string Answer() { return answer; };
    void Report();

private:
    int number = 0;
    int64_t durationMs = 0;
    string description;
    string answer;
    std::function<std::string()> solver = nullptr;
};

#endif