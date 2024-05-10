#include <iostream>
#include "Fraction.hpp"
using namespace std;
int main()
{
	Fraction a(2, 5);
	Fraction b(8, 5);
	Fraction c(2, 1);
	Fraction d(c);
	Fraction e;
	Fraction i;
	cout << "The first Fraction (A) should be 2/5 : " << a << endl;
	cout << "The second Fraction (B) should be 8/5 : " << b << endl;
	cout << "The third Fraction (C) should be 2 : " << c << endl;
	cout << "The fourth Fraction (D) should be like (c) = 2 : " << d << endl;
	cout << "The fifth Fraction (E) should be 0 : " << e << endl;
	cout << "enter I = " << endl;
	cin >> i;
	cout << i << endl;
	cout << " Arithmetic operations " << endl;
	cout << " ===================== " << endl;
	cout << a << "+" << b << "=" << a + b << endl;
	cout << c << "-" << b << "=" << c - b << endl;
	cout << b << " -" << c << "=" << b - c << endl;
	cout << c << "*" << b << "=" << c * b << endl;
 	cout << b << " /" << a << "=" << b / a << endl;
 	cout << " Logical operations " << endl;
 	cout << " ===================== " << endl;
 	cout << a << ">" << b << " should be false : " << (a > b) << endl;
 	cout << a << "<" << b << " should be True: " << (a < b) << endl;
 	cout << a << "==" << b << " should be false : " << (a == b) << endl;
 	cout << a << "!=" << b << " should be True: " << (a != b) << endl;
 	cout << c << "==" << d << " should be True : " << (c == d) << endl;
 	cout << " == == == == == == == == == == == == == == == " << endl;
 	cout << " arithmetic operations " << endl;
 	cout << " ============================== " << endl;
 	cout << a << "+ 2 =" << a + 2 << endl;
 	cout << " 2 + " << a << "=" << 2 + a << endl;
 	cout << " ===============================" << endl;
 	cout << "Division by Zero" << endl;
 	cout << " ============================== " << endl;
 	cout << "Fraction g(3,0): ";
 	Fraction g(3, 0);
 	cout << g << endl;
 	Fraction h(0, 1);
 	cout << "Divide by zero - a/h should not give abnormal exit:" << a / h << endl;
 	cout << " ============================== " << endl;
 	cout << "Good Luck" << endl;
}
