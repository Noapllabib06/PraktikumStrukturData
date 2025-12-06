#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX_SIZE - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.info[++S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.info[S.top--];
    }
    return '\0';
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S)) {
        push(temp, pop(S));
    }

    S = temp;
}

void getInputStream(Stack &S) {
    cout << "Masukkan input (ENTER untuk selesai): ";

    char c;
    while (true) {
        c = cin.get();

        if (c == '\n')
            break;

        if (!isFull(S))
            push(S, c);
    }
}