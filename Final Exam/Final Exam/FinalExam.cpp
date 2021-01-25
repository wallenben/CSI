#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;
int main() {
    Tables t(5);
    cout << t;
}

class Tables {
private:
    int* numPeopleAtTables;
    int arraySize;
public:
    Tables(int z);
    Tables(Tables& k);
    ~Tables();
    int getTableCount();
    int getTable(int pos);
    void seatGroup(int seat, int numPeople);
    int countDirtyTables();
    friend ostream& operator<<(ostream& out, const Tables& t);
};

Tables::Tables(int z) {
    if (z < 0) {
        z = 10;
    }
    numPeopleAtTables = new int[z];
    arraySize = z;
    for (int i = 0; i < arraySize; i++) {
        numPeopleAtTables[i] = 0;
    }
}
Tables::~Tables() {
    delete[] numPeopleAtTables;
}
int Tables::getTableCount() {
    return arraySize;
}
int Tables::getTable(int pos) {
    //we have to assume the position isn't counting from zero.
    if (pos - 1 < arraySize) {
        return numPeopleAtTables[pos - 1];
    }
    else {
        return -1;
    }

}
void Tables::seatGroup(int seat, int numPeople) {
    int x = getTable(seat);
    if (x != -1 && numPeople >= 1) {
        numPeopleAtTables[seat] = numPeople;
    }
}
int Tables::countDirtyTables() {
    int count = 0;
    for (int i = 0; i < arraySize; i++) {
        if (numPeopleAtTables[i] == -1) {
            count++;
        }
    }
    return count;
}
ostream& operator<<(ostream& out, const Tables& t) {
    for (int i = 0; i < t.arraySize; i++) {
        if (t.numPeopleAtTables[i] == -1) {
            out << i + 1 << "." << " " << "Needs Cleaning." << '\n';
        }
        else {
            out << i + 1 << "." << " " << t.numPeopleAtTables[i] << " customers." << '\n';
        }

    }
    //assuming it wants the stream returned?
    return out;
}