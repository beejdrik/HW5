#include <fstream>
#include <sstream>
#include "listtoolshb.h"
using namespace std;

struct Profile
{
    string fullname;
    string state;
    bool operator==( Profile rhs)
    {if (fullname==rhs.fullname) return true; return false; }
    bool operator!=(Profile rhs)
    {if (fullname!=rhs.fullname) return true; return false; }
};

ostream& operator<< (ostream &out, Profile &user)
{
    out << user.fullname<<"--" <<user.state;
    return out;
}

int main() {
    MyList<Profile> pMyList;
    string line;
    Profile temp;
    ifstream file("presidentsWstates.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMyList.insertHead( temp);
        }
    }
    return 0;
}
