#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class ChuanHoaChuoi
{
public:
    bool ChuThuong(const char &ch);
    string TachDau(const string &s);
    vector<string> MangTachChuoi(const string &s);
    void InHoaDauCau(vector<string> &mang);
    string ChuanHoaChuoiCom(const string &s);
};

bool ChuanHoaChuoi::ChuThuong(const char &ch)
{
    return ch >= 'a' && ch <= 'z';
}

string ChuanHoaChuoi::TachDau(const string &s)
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

vector<string> ChuanHoaChuoi::MangTachChuoi(const string &s)
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

void ChuanHoaChuoi::InHoaDauCau(vector<string> &mang)
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

string ChuanHoaChuoi::ChuanHoaChuoiCom(const string &s)
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

class Program
{
private:
    string raw;
public:
    Program();
    void MenuStart();
    void MenuChuanHoaChuoi();
    int ChooseType();
    void InputRawString();
    string getRaw() const;
    

};

Program::Program()
{
    this->raw = "";
}

void Program::MenuStart()
{
    cout << "1. Chuan hoa chuoi\n";
    cout << "2. Cat chuoi\n";
    cout << "3. Noi chuoi\n";
    cout << "4. Thay the trong chuoi\n";
    cout << "5. Thoat chuong trinh\n";
}

void Program::MenuChuanHoaChuoi()
{
    cout << "1. Chuan hoa cau\n";
    cout << "2. Chuan hoa theo dieu kien\n";
    cout << "3. Thoat\n";
}

int Program::ChooseType()
{
    int choose; cin >> choose;
    return choose;
}

void Program::InputRawString()
{
    cout << "Nhap chuoi:\n";
    cin >> raw;
}

string Program::getRaw() const
{
    return raw;
}

int main()
{
    Program *program = new Program();

    bool loop = true;

    while(loop)
    {
        program->MenuStart();
        int choose = program->ChooseType();
        if(choose == 1)
        {
            program->MenuChuanHoaChuoi();
            int choose1 = program->ChooseType();
            if(choose1 == 1)
            {
                program->InputRawString();
                ChuanHoaChuoi *chuanHoaChuoi = new ChuanHoaChuoi();
                chuanHoaChuoi->ChuanHoaChuoiCom(program->getRaw());
            }
        }

    }

    delete program;

    return 0;
}