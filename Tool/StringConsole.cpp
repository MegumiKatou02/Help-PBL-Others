#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

bool ChuThuong(const char &ch)
{
    return ch >= 'a' && ch <= 'z';
}

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

class ChuanHoaTheoDieuKien
{
private:
    string raw;
    bool upperCase;
public:
    ChuanHoaTheoDieuKien(string raw, const int number);
    ~ChuanHoaTheoDieuKien() { raw = ""; }
    string ChuanHoaChuoi(string otherRaw);
};

ChuanHoaTheoDieuKien::ChuanHoaTheoDieuKien(string raw, const int number) {
    this->raw = raw;
    if(number == 1)
    {
        upperCase = true;

    }
    else upperCase = false;
}

string ChuanHoaTheoDieuKien::ChuanHoaChuoi(string otherRaw)
{
    int k = raw.length();
    int n = otherRaw.length();
    string temp = "";
    for(int i = 0; i < otherRaw.length() - k + 1; i++)
    {
        for(int j = i; j < k + i; j++)
        {
            temp += otherRaw[j];
        }
        if(temp == this->raw)
        {
            if(upperCase)
            {
                transform(otherRaw.begin() + i, otherRaw.begin() + i + k, otherRaw.begin() + i, [](unsigned char c)
                    {return toupper(c); }
                );
            }
            else
            {
                transform(otherRaw.begin() + i, otherRaw.begin() + i + k, otherRaw.begin() + i, [](unsigned char c)
                    {return tolower(c); }
                );
            }
        }
        temp = "";
    }
    return otherRaw;
}

class CatNoiChuoi
{
private:
    string raw;
public:
    CatNoiChuoi(string raw);
    string CatChuoi(int n, int m = -1);
};

CatNoiChuoi::CatNoiChuoi(string raw)
{
    this->raw = raw;
}

string CatNoiChuoi::CatChuoi(int n, int m)
{
    int k = raw.length();
    if(n > k || m > k) return raw;
    if(n < 0 && m < 0) return raw;
    if(n < 0)
    {
        if(m == k - 1) return "";
        return raw.substr(m + 1);
    }
    if(m < 0)
    {
        return raw.substr(0, n);
    }
}

class Program
{
private:
    string raw;
    bool upperCase;
public:
    Program();
    void MenuStart();
    void MenuChuanHoaChuoi();
    void InputRawString();
    void MenuInHoaInThuong();
    string getRaw();
    void setRaw(string raw);
    void ViTriCacChuoi(const string &raw);
};

Program::Program()
{
    this->raw = "";
    this->upperCase = false;
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

void Program::InputRawString()
{
    cout << "Nhap chuoi:\n";
    getline(cin >> ws, raw);
}

string Program::getRaw()
{
    return raw;
}

void Program::MenuInHoaInThuong()
{
    cout << "1. In hoa theo dieu kien\n";
    cout << "2. In thuong theo dieu kien\n";
    cout << "3. Thoat\n";
}

void Program::ViTriCacChuoi(const string &raw)
{
    int n = raw.length();
    for(int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++)
    {
        if(i > 10)
        {
            cout << " " << raw[i] << " ";
        }
        else cout << raw[i] << " ";
    }
}

void Program::setRaw(string raw)
{
    this->raw = raw;
}

int main()
{
    bool start = true;
    string completeString = "";
    string unCompleteString = "";

    while(true)
    {
        Program *program = new Program();
        start = true;
        program->MenuStart();
        int choose; cin >> choose;
        if(choose == 1)
        {
            program->MenuChuanHoaChuoi();
            int choose1; cin >> choose1;
            if(choose1 == 1)
            {
                program->InputRawString();
                unCompleteString = program->getRaw();
                ChuanHoaChuoi *chuanHoaChuoi = new ChuanHoaChuoi();
                completeString = chuanHoaChuoi->ChuanHoaChuoiCom(program->getRaw());

                delete chuanHoaChuoi;
            }
            else if(choose1 == 2)
            {
                system("cls");
                program->MenuInHoaInThuong();
                int choose1_2; cin >> choose1_2;
                if(choose1_2 == 1)
                {
                    cout << "Nhap nhung tu se in hoa: \n";
                    program->InputRawString(); 
                }
                else if(choose1_2 == 2)
                {
                    cout << "Nhap nhung tu se in thuong: \n";
                    program->InputRawString();
                }
                else
                {
                    start = false;
                    system("cls");
                }
                if(start)
                {
                    cout << "Nhap cau de thuc hien:\n";
                    string frame; getline(cin >> ws, frame);
                    ChuanHoaTheoDieuKien *chuanhoaDK = new ChuanHoaTheoDieuKien(program->getRaw(), choose1_2);
                    unCompleteString = frame;
                    string temp = chuanhoaDK->ChuanHoaChuoi(frame);
                    program->setRaw(temp); completeString = program->getRaw();
                    delete chuanhoaDK;
                }

            }
            else
            {
                start = false;
                system("cls");
            }
        }
        else if(choose == 2)
        {
            cout << "Nhap chuoi muon cat:\n";
            string concatString; getline(cin >> ws, concatString);
            unCompleteString = concatString;
            program->ViTriCacChuoi(concatString);
            cout << "\nNhap lan luot vi tri bat dau va ket thuc de cat chuoi:\n";
            int viTriBatDau, viTriKetThuc; cin >> viTriBatDau >> viTriKetThuc;
            CatNoiChuoi *catNoiChuoi = new CatNoiChuoi(concatString);
            string temporary = catNoiChuoi->CatChuoi(viTriBatDau, viTriKetThuc);
            completeString = temporary;

        }
        else if(choose == 5)
        {
            cout << "Thoat chuong trinh thanh cong !\n";
            break;
        }
        else{
            start = false;
        }
        if(start)
        {
            system("cls");
            cout << "Chuoi truoc khi xu li\n";
            cout << (unCompleteString.empty() ? "[Empty..]" : unCompleteString) << "\n\n";
            cout << "Chuoi sau khi da xu li:\n";
            cout << (completeString.empty() ? "[Empty..]" : completeString) << "\n\n";

        }
        delete program;
        program = nullptr;
    }

    return 0;
}