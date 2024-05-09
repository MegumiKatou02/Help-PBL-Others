#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string TachDau(const string &s)
{
    string tach = "";
    for(const char &ch : s)
    {
        if(ch == '.' || ch == ',')
        {
            tach += " ";
        }
        tach += ch;
    }
    return tach;
}

string ChuanHoaChuoi(const string &s)
{
    cout << TachDau(s);
}

int main()
{
    string s;
    getline(cin, s);

    ChuanHoaChuoi(s);

    return 0;
}