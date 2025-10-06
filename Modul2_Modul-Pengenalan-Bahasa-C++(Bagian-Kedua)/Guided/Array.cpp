#include <iostream>
using namespace std;

int main() {
    int nilai[5] = {1,2,3,4,5};
    
    for (int i = 0; i < 5; ++i) {
        cout << "Element ke-"<< i << " = " << nilai[i] << endl;
    }

    return 0;
}