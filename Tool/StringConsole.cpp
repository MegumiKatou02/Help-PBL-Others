#include <iostream>
#include <string>

using namespace std;

class Program
{
private:
    string raw;
public:
    Program();
    void MenuStart();
    void MenuChuanHoaChuoi();
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
    }

int main()
{
    Program *program = new Program();

    bool loop = true;

    while(loop)
    {

    }

    delete program;

    return 0;
}