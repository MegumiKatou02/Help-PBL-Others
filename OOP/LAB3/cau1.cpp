#include <iostream>

using namespace std;

class Diem {
private:
    float hoanhDo, tungDo;
public:
    Diem();
    Diem(float hoanhDo, float tungDo);
    void setHoanhDo(float hoanhDo);
    void setTungDo(float tungDo);
    float getHoanhDo() const;
    float getTungDo() const;
    void TinhTienHoanhDo(float donVi);
    void TinhTienTungDo(float donVi);
    void Nhap();
    void Xuat() const;
};

Diem::Diem() {}

Diem::Diem(float hoanhDo, float tungDo) {
    this->hoanhDo = hoanhDo;
    this->tungDo = tungDo;
}

void Diem::setHoanhDo(float hoanhDo) {
    this->hoanhDo = hoanhDo;
}

void Diem::setTungDo(float tungDo) {
    this->tungDo = tungDo;
}

float Diem::getHoanhDo() const {
    return hoanhDo;
}

float Diem::getTungDo() const {
    return tungDo;
}

void Diem::TinhTienHoanhDo(float donVi) {
    this->hoanhDo += donVi;
}

void Diem::TinhTienTungDo(float donVi) {
    this->tungDo += donVi;
}

void Diem::Nhap() {
    cout << "Hoanh do: "; cin >> hoanhDo;
    cout << "Tung do: "; cin >> tungDo;
}

void Diem::Xuat() const {
    cout << "(" << hoanhDo << ", " << tungDo << ")";
}