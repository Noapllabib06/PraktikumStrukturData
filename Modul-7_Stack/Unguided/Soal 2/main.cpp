#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    
    cout << "Hello world!" << endl;
    createStack(S);
    
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    
    cout << "Setelah push ascending:" << endl;
    printInfo(S);
    
    cout << "Balik stack" << endl;
    balikStack(S);
    printInfo(S);
    
    return 0;
}