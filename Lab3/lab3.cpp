#include <iostream>
#include <memory>  

using namespace std;

struct IntNode {
    int data = 0;
    IntNode* next = NULL;
    IntNode() {};
    IntNode(int data) : data(data) {};
    IntNode(int data, IntNode* next) : data(data), next(next) {};
};

struct IntStack {
    IntNode* top = NULL;

    IntStack() {};
    IntStack(IntNode* top) : top(top) {};

    ~IntStack() {
        while (top != NULL) {
            pop();
        }
    }

    void push(int data) {
        top = new IntNode(data, top);
    }

    int peek() { 
        if (top != NULL)
            return top->data;
        cerr << "Error: Attempting to peek a stack with no elements." << endl;
        return -1;
    }

    int pop() {
        if (top != NULL) {
            IntNode* prevTop = top;
            int data = top->data;
            top = top->next;
            delete prevTop;
            return data;
        }
        cerr << "Error: Attempting to pop a stack with no elements." << endl;
        return -1;
    }

    bool isEmpty() {  
        return top == NULL;  
    }
};

int main() {

    // ### LINKED LIST DEMO ###
    // Creation
    IntNode* head = new IntNode(1);
    head = new IntNode(2, head);
    head = new IntNode(3, head);
    head = new IntNode(4, head);

    // Traversal
    IntNode* currentNode = head;
    while(currentNode != NULL) {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;

    // Deletion
    currentNode = head;
    while(currentNode != NULL) {
        IntNode* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }

    // ### STACK DEMO ###
    IntStack s;
    s.push(1);
    cout << s.peek() << endl;
    s.push(2);
    cout << s.pop() << endl;

    // Extra Tests
    cout << s.pop() << endl;
    if (s.isEmpty()) {
        cout << "empty" << endl;
    }

    return 0;
}