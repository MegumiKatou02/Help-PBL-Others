#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool ChuThuong(const char &ch)
{
    return ch >= 'a' && ch <= 'z';
}

string TachDau(const string &s)
{
    string tach = "";
    for(const char &ch : s)
    {
        if(ch == '.' || ch == ',')
        {
            tach = tach + " " + ch + " ";
        }
        else tach += ch;
    }
    return tach;
}

vector<string> MangTachChuoi(const string &s)
{
    vector<string> mang;
    string empty;
    stringstream ss(s);
    while(ss >> empty)
    {
        mang.push_back(empty);
    }
    return mang;
}

void InHoaDauCau(vector<string> &mang)
{
    if(ChuThuong(mang[0][0]))
    {
        mang[0][0] -= 32;
    }
    bool dauCau = false;
    for(string &s : mang)
    {
        if(s == ".")
        {
            dauCau = true;
        }
        if(ChuThuong(s[0]) && dauCau)
        {
            s[0] -= 32;
            dauCau = false;
        }
    }
}

string ChuanHoaChuoi(const string &s)
{
    string mainString = "";
    string chuoiTachDau = TachDau(s);
    vector<string> mangTach = MangTachChuoi(chuoiTachDau);
    InHoaDauCau(mangTach);
    for(string &raw : mangTach)
    {
        if(raw == "." || raw == ",")
        {
            mainString += raw;
        }  
        else
        {
            mainString = mainString + " " + raw;
        }
    }
    return mainString.substr(1);
}

int main()
{
    string s;
    getline(cin, s);

    string chuoiChuanHoa = ChuanHoaChuoi(s);
    cout << "Chuoi ban dau:\n";
    cout << s << "\n";
    cout << "Chuoi sau khi duoc chuan hoa:\n";
    cout << chuoiChuanHoa << "\n";

    return 0;
}
