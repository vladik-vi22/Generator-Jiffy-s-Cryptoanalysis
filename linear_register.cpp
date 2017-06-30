/***************************************************
             Компьютерный практикум №3
        ФI-43, В. Кривцун, ФБ-42, М. Климчук
                    Вариант 4
***************************************************/

#include "linear_register.h"


linear_register::linear_register(int *polynom, int polynom_size) {
    this->polynom = new int[polynom_size];
    this->polynom = polynom;
    this->polynom_size = polynom_size;
    this->reg = new int[polynom[0]];
}

void linear_register::set_state(unsigned int state) {
    for (unsigned int i = 0; i < this->polynom[0]; i++)
        this->reg[i] = (state >> i) & 0b1;
}

int linear_register::shift() {
    int out_bit = this->reg[0];

    int new_bit = 0;
    for (int i = 1; i < polynom_size; i++)
        new_bit ^= this->reg[polynom[i]];

    for (int i = 0; i < this->polynom[0] - 1; i++)
        this->reg[i] = this->reg[i + 1];
    this->reg[this->polynom[0] - 1] = new_bit;

    return out_bit;
}


vector<int> linear_register::saved_states(int N, int C, int z[]) {
    vector<int> saved_states_lr;
    for (unsigned int j = 1; j < pow(2, this->polynom[0]); j++) {
        this->set_state(j);
        int R = 0;
        for (int i = 0; i < N; i++)
            R += this->shift() ^ z[i];
        if (R < C) {
            cout << "Found state: " << j << endl;
            saved_states_lr.insert(saved_states_lr.end(), j);
        }
    }
    return saved_states_lr;

}

void linear_register::get_state() {
    for (int i = 0; i < this->polynom[0]; i++)
        cout << this->reg[i];
    cout << endl;
}
