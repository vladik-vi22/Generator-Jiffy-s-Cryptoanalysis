/***************************************************
             Компьютерный практикум №3
        ФI-43, В. Кривцун, ФБ-42, М. Климчук
                    Вариант 4
***************************************************/

#include "linear_register.h"

using namespace std;


void read_file(string file, int *z) {
    ifstream fin(file);
    string s;
    fin >> s;
    for (int i = 0; i < 2048; i++)
        z[i] = s[i] - '0';
    fin.close();
}

int main() {
    int z[2048];
    read_file("z.out", z);

    int lr1_polynom[3] = {25, 3, 0};
    linear_register lr1(lr1_polynom, 3);
    int lr2_polynom[5] = {26, 6, 2, 1, 0};
    linear_register lr2(lr2_polynom, 5);
    int lr3_polynom[5] = {27, 5, 2, 1, 0};
    linear_register lr3(lr3_polynom, 5);

    int N1 = 222;
    int C1 = 58;
    int N2 = 228;
    int C2 = 66;

    unsigned int f_saved_states_lr1[1] = {17660824};//+883608
    unsigned int f_saved_states_lr2[1] = {46338496};//+54746833
    unsigned int saved_states[3];

    vector<int> saved_states_lr1 = lr1.saved_states(N1, C1, z);
    cout << "Saved states for LR1:" << endl;
    for (int i = 0; i< saved_states_lr1.size(); i++)
        cout << saved_states_lr1[i] << endl;

    vector<int> saved_states_lr2 = lr2.saved_states(N2, C2, z);
    cout << "Saved states for LR2:" << endl;
    for (int i = 0; i< saved_states_lr2.size(); i++)
        cout << saved_states_lr2[i] << endl;

    for (int j = 0; j < sizeof(f_saved_states_lr1) / 4; j++) {
        lr1.set_state(f_saved_states_lr1[j]);
        for (int k = 0; k < sizeof(f_saved_states_lr2) / 4; k++) {
            lr2.set_state(f_saved_states_lr2[k]);
            for (unsigned int l = 1; l < pow(2, lr3_polynom[0]); l++) {
                lr3.set_state(l);
                int i = 0;
                int temp;
                do {
                    int s = lr3.shift();
                    temp = ((s & lr1.shift()) ^ ((1 ^ s) & lr2.shift()));
                } while ((temp == z[i++]) and (i < 122));
                if (i == 122) {
                    cout << "Found state!" << endl;
                    saved_states[0] = f_saved_states_lr1[j];
                    saved_states[1] = f_saved_states_lr2[k];
                    saved_states[2] = l;
                    goto done;
                }
            }
        }
    }
    done:
    for (int i = 0; i < sizeof(saved_states) / 4; i++)
        cout << saved_states[i] << endl;


    return 0;
}
