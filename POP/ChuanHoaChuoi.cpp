#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool LaChuThuong(const char &chu)
{
    return chu >= 'a' && chu <= 'z';
}

vector<string> MangChuoiTach(const string &s)
{
    string empty;
    stringstream ss(s);
    vector<string> v;
    while(ss >> empty)
    {
        v.push_back(empty);
    }
    return v;
}

vector<string> InHoaChuaHoaChuoi(vector<string> &v)
{
    if(LaChuThuong(v[0][0]))
    {
        v[0][0] -= 32;
    }
    string ouput = "";
    vector<string> others;
    for(string chuoi : v)
    {
        for(int i = 0; i < chuoi.length(); i++)
        {
            char chu = chuoi[i];
            if(chu == '.' || chu == ',')
            {
                others.push_back(ouput);
                others.push_back(chu + "");
            }
            else
            {
                ouput += chu;
            }
            others.push_back(ouput);
            ouput = "";
        }
    }
    return others;
}

string ChuanHoaChuoi(string s)
{
    vector<string> v = MangChuoiTach(s);
    v = InHoaChuaHoaChuoi(v);
    for(const auto &x : v)
    {
        cout << x << " ";
    }
    return "";
}

int main()
{
    string s;
    getline(cin, s);

    cout << "Ban dau:\n";
    cout << s;
    cout << "\nSau khi chuan hoa\n";
    cout << ChuanHoaChuoi(s);

    return 0;
}