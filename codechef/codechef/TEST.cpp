#include <iostream>
using namespace std;
int main() {
    int a[100];
    for (int i = 0; i < 100; i++)
    {
        cin >> a[i];
        if (a[i] == 42)
            return 0;
        else
            cout << a[i] << endl;
    }
}





int altnerativeSolution() {
    int a[99];
    int i = 0;
    while (a[i] != 42) {
        ++i;
        cin >> a[i];

    }
    cout << endl;
    for (int x = 1; x < i; x++) {
        cout << a[x] << '\n';
    }
}