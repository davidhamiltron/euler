#include "Problem.h"
#include "Stopwatch.h"

#include <iostream>

using namespace std;

// Solve and print out result

Problem::Problem(int number, const string &description) :
    number(number), description(description)
{

}

int Problem::Number()
{
    return number;
}

string Problem::Description()
{
    return description;
}

int Problem::Answer()
{
    return answer;
}

int Problem::Report()
{
    Stopwatch s;
    s.Start();
    answer = Solve();
    s.Stop();
    auto durationMs = s.ElapsedMilliseconds();

    cout << to_string(number) << ". " << description << endl;
    cout << "Answer: " << answer << " in " << durationMs << "ms" << endl;
    //cout << "Answer: ******** in " << durationMs << "ms" << endl;
    return answer;
}