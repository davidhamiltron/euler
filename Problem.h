
#include <string>
#include <functional>
using namespace std;



class Problem
{
public:
    
    Problem(int number, const std::string &description);
    int Number();
    std::string Description();
    int Answer();
    int Report();

protected:
    // Child classes should override
    virtual int Solve() = 0;

private:
    int number = 0;
    string description;
    int answer = 0;
};

/*


class Problem2 : public Problem
{
public:
	Problem2();
	string Name() { return "Problem 2";}
	bool Solve();
};


class Problem3 : public Problem
{
public:
	Problem3();
	string Name() { return "Problem 3";}
	bool Solve();
};

class Problem4 : public Problem
{
public:
	Problem4();
	string Name() { return "Problem 4";}
	bool Solve();
};

class Problem5 : public Problem
{
public:
	Problem5();
	string Name() { return "Problem 5";}
	bool Solve();
};

class Problem6 : public Problem
{
public:
	Problem6();
	string Name() { return "Problem 6";}
	bool Solve();
};

class Problem7 : public Problem
{
public:
	Problem7();
	string Name() { return "Problem 7";}
	bool Solve();
};

class Problem8 : public Problem
{
public:
	Problem8();
	string Name() { return "Problem 8";}
	bool Solve();
};

class Problem9 : public Problem
{
public:
	Problem9();
	string Name() { return "Problem 9";}
	bool Solve();
};

class Problem10 : public Problem
{
public:
	Problem10();
	string Name() { return "Problem 10";}
	bool Solve();
};

class Problem11 : public Problem
{
public:
	Problem11();
	string Name() { return "Problem 11";}
	bool Solve();
};

class Problem12 : public Problem
{
public:
	Problem12();
	string Name() { return "Problem 12";}
	bool Solve();
};

class Problem13 : public Problem
{
public:
	Problem13();
	void Test();
	string Name() { return "Problem 13";}
	bool Solve();
};

class Problem14 : public Problem
{
public:
	Problem14();
	string Name() { return "Problem 14";}
	bool Solve();
};


class Problem15 : public Problem
{
public:
	Problem15();
	string Name() { return "Problem 15";}
	bool Solve();
};

class Problem16 : public Problem
{
public:
	Problem16();
	string Name() { return "Problem 16";}
	bool Solve();
};

class Problem17 : public Problem
{
public:
	Problem17();
	string Name() { return "Problem 17";}
	bool Solve();
};

class Problem18 : public Problem
{
public:
	Problem18();
	string Name() { return "Problem 18";}
	bool Solve();
};

class Problem19 : public Problem
{
public:
    Problem19();
    string Name() { return "Problem 19"; }
    bool Solve();
};

class Problem20 : public Problem
{
public:
	Problem20();
	string Name() { return "Problem 20";}
	bool Solve();
};

class Problem21 : public Problem
{
public:
    Problem21();
    string Name() { return "Problem 21"; }
    bool Solve();
};

class Problem22 : public Problem
{
public:
    Problem22();
    string Name() { return "Problem 22"; }
    bool Solve();
};

class Problem23 : public Problem
{
public:
    Problem23();
    string Name() { return "Problem 23"; }
    bool Solve();
};


class Problem67 : public Problem
{
public:
	Problem67();
	string Name() { return "Problem 67";}
	bool Solve();
};
*/