#include <iostream>

using namespace std;

class Match {
private:
    int line;
    int column;
    
public:
    Match(int l,int c) : line(l), column(c){}

    friend ostream & operator<<(ostream & os, const Match & match)
    {
    os << "true "<<match.line << " " << match.column<<endl;
    return os;
    }

    int getLine() { return line; }
    int getColumn() { return column; }
};