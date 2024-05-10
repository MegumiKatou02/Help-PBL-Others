#include <iostream>
#include <string>

using namespace std;

string chuyenSangNhiPhan(int n)
{
    if(n == 0)
    {
        return "0";
    }
    string s = "";
    while(n > 0)
    {
        int du = n % 2;
        s += to_string(du);
        n /= 2; 
    }
    return s;
}

int main()
{
    int n;
    do
    {
        cin  >> n;
    } while (n < 0);
    
    cout << chuyenSangNhiPhan(n);
    return 0;
}