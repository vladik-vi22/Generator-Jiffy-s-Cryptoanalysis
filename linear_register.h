/***************************************************
             Компьютерный практикум №3
        ФI-43, В. Кривцун, ФБ-42, М. Климчук
                    Вариант 4
***************************************************/

#ifndef LAB3_LINEAR_REGISTER_H
#define LAB3_LINEAR_REGISTER_H

#include <iostream>
#include <bitset>
#include <cmath>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

class linear_register {
private:
    int *reg;
    int *polynom;
    int polynom_size;
public:
    linear_register(int *polynom, int polynom_size);
    void set_state(unsigned int state);
    int shift();
    vector<int> saved_states(int N, int C, int z[]);
    void get_state();

};




#endif //LAB3_LINEAR_REGISTER_H
