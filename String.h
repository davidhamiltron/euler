

#include <string>
#include <iostream>
#include <vector>

std::string ToString(int i);
//std::string ToString(int64_t i);

int ToInt(std::string s);

static std::ostream& operator<< (std::ostream& os, const std::vector<int>& v)
{
    for (auto i : v)
        os << i << " ";
    return os;
}


// Splits a string based on a separator string (not the characters inside the separator string)
// separators at the start or end of the string are ignored
static void Split(std::vector<std::string> &tokens, const std::string &s, const std::string &separator)
{
    if (s.size() == 0) throw std::runtime_error("no string passed in");
    if (separator.size() == 0) throw std::runtime_error("no separator passed in");
    tokens.clear();

    size_t prev = 0;
    size_t pos = s.find(separator);
    while (pos != std::string::npos)
    {
        if (pos != 0) // if we found a separator at the beginning, ignore it
            tokens.push_back(s.substr(prev, pos - prev));
        prev = pos + separator.size();
        pos = s.find(separator, prev);
    }
    std::string last = s.substr(prev);
    if (last.size())
        tokens.push_back(last);
}