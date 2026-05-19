#include <iostream>
using namespace std;

class seseorang {
public:
    virtual void pesan() {
        cout << "Pesan dari seseorang." << endl;
    }
};

class joko : public seseorang {
public:
    void pesan() override {
        cout << "Pesan dari Joko." << endl;
    }
};