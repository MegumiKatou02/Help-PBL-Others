#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

enum TypeDate   
{
    VARCHAR,
    INTEGER,
    DOUBLEF
};

int DemCau(const string &s)
{
    string empty;
    vector<string> v;
    stringstream ss(s);
    while(ss >> empty)
    {
        v.push_back(empty);
    }
    return v.size();
}

void ViTriCacChuoi(const string &raw)
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
        else if(i > 100)
        {
            cout << "  " << raw[i] << "  ";
        }
        else cout << raw[i] << " ";
    }
}

vector<string> tachDong(const string &s)
{
    stringstream ss(s);
    string empty;
    vector<string> v;
    while(ss >> empty)
    {
        v.push_back(empty);
    }
    return v;
}

string trim(const string &s)
{
    string out2 = "";
    vector<string> v = tachDong(s);
    for(const string &x : v)
    {
        out2 = out2 + x + " ";
    }
    return out2;
}

string StringSQL(string current, int j, int end, int dataType)
{
    if(j == 0 && j == end)
    {
        return ((dataType == VARCHAR) ?  "(\'" + current + "\')" : "(" + current + ")"); 
    }
    else if(j == 0)
    {
        return ((dataType == VARCHAR) ?  "(\'" + current + "\'" : "(" + current); 
    }
    else if(j == end)
    {
        return ((dataType == VARCHAR) ?  "\'" + current + "\')" : current + ")"); 
    }
    else 
    {
        return ((dataType == VARCHAR) ?   "\'" + current + "\'" : current);
    }
}

vector<string> tachChuoi(vector<string> dongSQL[], vector<int> dataType, int batDauCau, int ketThucCau, int soDong, int soCot)
{
    vector<string> completed;
    string theoDong = "", temp = "";
    batDauCau--; ketThucCau--;
    // duyt theo hang doc
    for(int i = 1; i <= soDong; i++)
    {
        // duyet theo hang ngang
        for(int j = 0; j < dongSQL[i].size(); j++)
        {
            string current = dongSQL[i][j];
            if(j >= batDauCau && j <= ketThucCau && dongSQL[i].size() > soCot)
            {
                temp = "";
                for(int k = batDauCau; k <= ketThucCau; k++)
                {
                    temp = temp + dongSQL[i][k];
                    if(k != ketThucCau)
                    {
                        temp = temp + " ";
                    }
                }
                int pround = -1;
                if(batDauCau == 0) pround = batDauCau;
                if(ketThucCau == dongSQL[i].size() - 1) pround = ketThucCau; 

                theoDong = theoDong + StringSQL(temp, pround, dongSQL[i].size() - 1, dataType[batDauCau]);
                if(ketThucCau != dongSQL[i].size() - 1)
                {
                    theoDong = theoDong + ", ";
                }
                dongSQL[i][batDauCau] = temp;
            
                for(int m = batDauCau + 1; m + ketThucCau - batDauCau < dongSQL[i].size(); m++)
                {
                    dongSQL[i][m] = dongSQL[i][m + ketThucCau - batDauCau];
                }
                dongSQL[i].resize(soCot);
            }
            else
            {
                theoDong = theoDong + StringSQL(current, j, dongSQL[i].size() - 1, dataType[j]);
                if(j != dongSQL[i].size() - 1)
                {
                    theoDong = theoDong + ", ";
                }
            }
        }
        completed.push_back(theoDong);
        theoDong = "";
    }
    return completed;
}

int main()
{
    vector<int> dataType;
    cout << "Nhap so dong: ";
    int soDong; cin >> soDong;
    cout << "Nhap so cot: ";
    int soCot; cin >> soCot;
    cout << "Nhap kieu du lieu cua tung cot:\n";
    for(int i = 0; i < soCot; i++)
    {
        cout << "0. VARCHAR, 1. INTEGER, 2.DOUBLE/FLOAT: ";
        int type; cin >> type;
        if(type == INTEGER) dataType.push_back(INTEGER);
        if(type == VARCHAR) dataType.push_back(VARCHAR);
        if(type == DOUBLEF) dataType.push_back(DOUBLEF);
    }
    int testCase = soDong;
    vector<string> dongSQL[soDong + 1];
    int batDauCau = -1, ketThucCau = -1;
    bool chinhCau = false;
    cin.ignore();
    while(testCase > 0)
    {
        string inputSQL;
        getline(cin, inputSQL);

        inputSQL = trim(inputSQL);
        if(DemCau(inputSQL) > soCot && !chinhCau)
        {
            cout << "So tu trong cau lon hon so cot\n";
            ViTriCacChuoi(inputSQL.substr(0, inputSQL.length() - 1));
            cout << "\nNhap vi tri bat dau va ket thuc de gop thanh mot kieu du lieu:\n";
            int start, end; cin >> start >> end; cin.ignore();
            
            int count = 0;
            for(int i = 0; i < inputSQL.length(); i++)
            { 
                char ch = inputSQL[i];
                if(start == i || end == i)
                {
                    int step = count + 1;
                    (start == i) ? batDauCau = step : ketThucCau = step;
                }
                if(ch == ' ')
                    count++;
            }
            chinhCau = true;
        }
        string temp = "";
        for(int i = 0; i < inputSQL.length(); i++)
        {
            char ch = inputSQL[i];
            if(ch == ' ')
            {
                dongSQL[soDong - testCase + 1].push_back(temp);
                temp = "";
            }
            else 
                temp += ch;
        }

        testCase--;
    }
    vector<string> containsSQL = tachChuoi(dongSQL, dataType, batDauCau, ketThucCau, soDong, soCot);

    cout << "Xoa man hinh? (1. Co, 2. Khong): ";
    int clear; cin >> clear;
    (clear == 1) ? system("cls") : true;

    int count = 1;
    for(const string &s : containsSQL)
    {
        cout << s;
        if(count != containsSQL.size())
        {
            cout << ",";
        }
        cout << "\n";
        count++;
    }

    return 0;
}