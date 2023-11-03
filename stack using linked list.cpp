#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {

public:
    Node* top;
    Stack() { top = NULL; }
    void push(char ch);
    char pop();
};

void Stack::push(char ch) {
    Node* newNode = new Node;
    if (!newNode) {
        cout << "Stack overflow";
        exit(1);
    }
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

char Stack::pop() {
    if (top == NULL) {
        cout << "Stack underflow";
        exit(1);
    }
    char ch = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return ch;
}

int main() {
    Stack s1, s2;
    s1.push('a');
    s1.push('b');
    s1.push('c');

    // Copying stack s1 to s2
    for (Node* temp = s1.top; temp != NULL; temp = temp->next) {
        s2.push(temp->data);
    }

    for (int i=0; i<3; i++)
        cout << "Pop s1: " << s1.pop() << "\n";

    for (int i=0; i<3; i++)
        cout << "Pop s2: " << s2.pop() << "\n";

    return 0;
}

