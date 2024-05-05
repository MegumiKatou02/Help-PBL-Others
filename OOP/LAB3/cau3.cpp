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

Diem::Diem() {}

Diem::Diem(float hoanhDo, float tungDo) : hoanhDo(hoanhDo), tungDo(tungDo) {}

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

float Diem::khoangCachHaiDiem(const Diem &diem) {
    return sqrt(pow(this->hoanhDo - diem.hoanhDo, 2) + pow(this->tungDo - diem.tungDo, 2));
}

class DaGiac {
private:
    Diem *diem;
    int n;
public:
    DaGiac();
    ~DaGiac();
    void Nhap();
    void Xuat();
    void TinhTienHoanhDo(float donVi);
    void TinhTienTungDo(float donVi);
    float DienTich() const;
    Diem TrongTam();
    void PhongTo(float donVi);
    void ThuNho(float donVi);
    void QuayTamGiac(float goc);
};

DaGiac::DaGiac() {
    this->n = 0;
    this->diem = nullptr;
}

DaGiac::~DaGiac() {
    if(diem != nullptr) {
        delete[] diem;
    }
}

void DaGiac::Nhap() {
    do {
        cout << "Nhap so luong diem cua da giac: ";
        cin >> n;
    }
    while(n < 3);

    if(diem != nullptr) {
        delete[] diem;
        diem = nullptr;
    }
    diem = new Diem[n];

    for(int i = 0; i < n; i++) {
        cout << "\nDa giac thu: " << i + 1 << "\n";
        diem[i].Nhap();
    }
}

void DaGiac::Xuat() {
    cout << "Cac toa do cua da giac\n";
    for(int i = 0; i < n; i++) {
        diem[i].Xuat();
        cout << "\n";
    }
}

void DaGiac::TinhTienHoanhDo(float donVi) {
    for(int i = 0; i < n; i++) {
        diem[i].TinhTienHoanhDo(donVi);
    }
}

void DaGiac::TinhTienTungDo(float donVi) {
    for(int i = 0; i < n; i++) {
        diem[i].TinhTienTungDo(donVi);
    }
}

float DaGiac::DienTich() const {
    float sum = 0.0f;
    for(int i = 0; i < n - 1 ; i++) {
        sum = sum + (diem[i].getHoanhDo() * diem[i + 1].getTungDo()) - (diem[i].getTungDo() * diem[i + 1].getHoanhDo());
        sum = fabs(sum);
    }
    sum = sum + (diem[n - 1].getHoanhDo() * diem[0].getTungDo()) - (diem[0].getHoanhDo() * diem[n - 1].getTungDo());
    sum = fabs(sum); 
    return sum * 0.5;
}

Diem DaGiac::TrongTam() {
    float x = 0.0f, y = 0.0f;
    for(int i = 0; i < n - 1; i++) {
        x = x + (diem[i].getHoanhDo() + diem[i + 1].getHoanhDo()) * (diem[i].getHoanhDo() * diem[i + 1].getTungDo() - diem[i + 1].getHoanhDo() * diem[i].getTungDo());
        x = x + (diem[n - 1].getHoanhDo() + diem[0].getHoanhDo()) * (diem[n - 1].getHoanhDo() * diem[0].getTungDo() - diem[0].getHoanhDo() * diem[n - 1].getTungDo());

        y = y + (diem[i].getTungDo() + diem[i + 1].getTungDo()) * (diem[i].getHoanhDo() * diem[i + 1].getTungDo() - diem[i + 1].getHoanhDo() * diem[i].getTungDo());
        y = y + (diem[n - 1].getTungDo() + diem[0].getTungDo()) * (diem[n - 1].getHoanhDo() * diem[0].getTungDo() - diem[0].getHoanhDo() * diem[n - 1].getTungDo());
    }
    x = x * 1.0 / (6 * DienTich());
    y = y * 1.0 / (6 * DienTich());
    return Diem(x, y);
}   

int main() {
    DaGiac daGiac;
    daGiac.Nhap();
    daGiac.TrongTam().Xuat();
}