#include <iostream>
#include <iomanip>
using namespace std;

class RekeningBank {
protected:
    double saldo;

public:
    RekeningBank(double s) {
        saldo = s;
    }

    virtual void potongAdmin() = 0;

    void tampilkanSaldo() {
        cout << fixed << setprecision(0);
        cout << "Saldo akhir: Rp " << saldo << endl;
    }
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Rekening Konvensional dipotong Rp 15.000." << endl;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Rekening Premium bebas biaya admin." << endl;
        }
        else {
            saldo -= 50000;
            cout << "Rekening Premium dipotong Rp 50.000." << endl;
        }
    }
};

int main() {
    RekeningBank* rekening[3];

    rekening[0] = new RekeningSyariah(5000000);
    rekening[1] = new RekeningKonvensional(5000000);
    rekening[2] = new RekeningPremium(10000000);

    cout << "=== Bank Gibran Jaya ===" << endl;

    for (int i = 0; i < 3; i++) {
        rekening[i]->potongAdmin();
        rekening[i]->tampilkanSaldo();
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete rekening[i];
    }

    return 0;
}