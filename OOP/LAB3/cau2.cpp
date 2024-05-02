#include <iostream>
#include <cmath>

using namespace std;

class Diem {
private:
    float hoanhDo, tungDo;
public:
    Diem();
    Diem(float hoanhDo, float tungDo);
    void Nhap();
    void Xuat();
    float getHoanhDo() const;
    float getTungDo() const;
    void TinhTienHoanhDo(float donVi);
    void TinhTienTungDo(float donVi);
    float khoangCachHaiDiem(const Diem &diem);
    Diem QuayDiem(float goc) const;
};

void Diem::Nhap() {
    cout << "Hoanh do: "; cin >> hoanhDo;
    cout << "Tung do: "; cin >> tungDo;
}

void Diem::TinhTienHoanhDo(float donVi) {
    this->hoanhDo += donVi;
}

void Diem::TinhTienTungDo(float donVi) {
    this->tungDo += donVi;
}

void Diem::Xuat() {
    cout << "(" << hoanhDo << ", " << tungDo << ")";
}

float Diem::getHoanhDo() const {
    return hoanhDo;
}

float Diem::getTungDo() const {
    return tungDo;
}

Diem Diem::QuayDiem(float goc) const {
    float rad = goc * M_PI / 180.0;
    float x = this->hoanhDo * cos(rad) - this->tungDo * sin(rad);
    float y = this->hoanhDo * sin(rad) + this->tungDo * cos(rad);
    return Diem(x, y);
}

Diem::Diem() {}

Diem::Diem(float hoanhDo, float tungDo) : hoanhDo(hoanhDo), tungDo(tungDo) {}

float Diem::khoangCachHaiDiem(const Diem &diem) {
    return sqrt(pow(this->hoanhDo - diem.hoanhDo, 2) + pow(this->tungDo - diem.tungDo, 2));
}

class TamGiac {
private:
    Diem a, b, c;
public:
    TamGiac();
    TamGiac(Diem a, Diem b, Diem c);
    void Nhap();
    void Xuat();
    void TinhTienHoanhDo(float donVi);
    void TinhTienTungDo(float donVi);
    Diem TrongTam();
    void PhongTo(float donVi);
    void ThuNho(float donVi);
    void QuayTamGiac(float goc);
};

TamGiac::TamGiac() {}

TamGiac::TamGiac(Diem a, Diem b, Diem c) : a(a), b(b), c(c) {}

void TamGiac::Nhap() {
    cout << "\nToa do diem a\n";
    a.Nhap();
    cout << "\nToa do diem b\n";
    b.Nhap();
    cout << "\nToa do diem c\n";
    c.Nhap();
}

void TamGiac::Xuat() {
    cout << "Toa do lan luot cua 3 diem a, b, c\n";
    a.Xuat(); cout << "\t";
    b.Xuat(); cout << "\t";
    c.Xuat(); cout << "\n";
}

void TamGiac::TinhTienHoanhDo(float donVi) {
    a.TinhTienHoanhDo(donVi);
    b.TinhTienHoanhDo(donVi);
    c.TinhTienHoanhDo(donVi);
}

void TamGiac::TinhTienTungDo(float donVi) {
    a.TinhTienTungDo(donVi);
    b.TinhTienTungDo(donVi);
    c.TinhTienTungDo(donVi);
}

Diem TamGiac::TrongTam() {
    float x = (a.getHoanhDo() + b.getHoanhDo() + c.getHoanhDo()) / 3.0;
    float y = (a.getTungDo() + b.getTungDo() + c.getTungDo()) / 3.0;
    return Diem(x, y);
}

void TamGiac::PhongTo(float donVi) {
    donVi = fabs(donVi);
    Diem trongTam = TrongTam();
    
    float khoangCachA = a.khoangCachHaiDiem(trongTam);
    float khoangCachB = b.khoangCachHaiDiem(trongTam);
    float khoangCachC = c.khoangCachHaiDiem(trongTam);
    
    a.TinhTienHoanhDo((a.getHoanhDo() - trongTam.getHoanhDo()) / khoangCachA * donVi);
    a.TinhTienTungDo((a.getTungDo() - trongTam.getTungDo()) / khoangCachA * donVi);
    
    b.TinhTienHoanhDo((b.getHoanhDo() - trongTam.getHoanhDo()) / khoangCachB * donVi);
    b.TinhTienTungDo((b.getTungDo() - trongTam.getTungDo()) / khoangCachB * donVi);
    
    c.TinhTienHoanhDo((c.getHoanhDo() - trongTam.getHoanhDo()) / khoangCachC * donVi);
    c.TinhTienTungDo((c.getTungDo() - trongTam.getTungDo()) / khoangCachC * donVi);
}

void TamGiac::ThuNho(float donVi) {
    donVi = fabs(donVi);
    Diem trongTam = TrongTam();

    float khoangCachA = a.khoangCachHaiDiem(trongTam);
    float khoangCachB = b.khoangCachHaiDiem(trongTam);
    float khoangCachC = c.khoangCachHaiDiem(trongTam);

    a.TinhTienHoanhDo(-((a.getHoanhDo() - trongTam.getHoanhDo()) / khoangCachA * donVi));
    a.TinhTienTungDo(-((a.getTungDo() - trongTam.getTungDo()) / khoangCachA * donVi));

    b.TinhTienHoanhDo(-((b.getHoanhDo() - trongTam.getHoanhDo()) / khoangCachB * donVi));
    b.TinhTienTungDo(-((b.getTungDo() - trongTam.getTungDo()) / khoangCachB * donVi));

    c.TinhTienHoanhDo(-((c.getHoanhDo() - trongTam.getHoanhDo()) / khoangCachC * donVi));
    c.TinhTienTungDo(-((c.getTungDo() - trongTam.getTungDo()) / khoangCachC * donVi));
}  

void TamGiac::QuayTamGiac(float goc) {
    a = a.QuayDiem(goc);
    b = b.QuayDiem(goc);
    c = c.QuayDiem(goc);
}
