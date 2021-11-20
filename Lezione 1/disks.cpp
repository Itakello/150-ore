// https://training.olinfo.it/#/task/ois_disks/statement

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    long long int A, B, T, days, tot;
    cin >> A >> B >> T;

    days = T / 24;
    tot = (days * (B - A));

    T %= 24;
    int free_hours = (24 - B) + A;
    T -= free_hours;

    if (T > 0)
        tot += T;
    cout << tot << endl;
    return 0;
    }
