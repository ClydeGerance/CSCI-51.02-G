#include <iostream>
#include <memory>  
#include <optional>

using namespace std;

struct IntNode {
    // node consists of key (data) and pointer to the next node
    // set initial values for key (0) and pointer (null)
    int data = 0;
    IntNode* next = NULL;
    IntNode() {};
    // assign initial data
    IntNode(int data) : data(data) {};
    
    // assign initial data and the pointer to the next node
    IntNode(int data, IntNode* next) : data(data), next(next) {};
};

struct IntStack {
    IntNode* top = NULL;
    IntStack() {};
    IntStack(IntNode* top) : top(top) {};

    // pop all nodes before deleting the IntStack
    ~IntStack() {
        while (!is_empty()) {
            pop();
        }
    }

    // add new nodes at the "top" of the stack
    void push(int data) {
        top = new IntNode(data, top);
        
    }

    // check top of the stack
    int peek() { 
        if (!is_empty()) {
            return top->data;
        }
        throw runtime_error("Error: Attempting to peek a stack with no elements.");
    }

    // remove "top" of the stack
    int pop() {
        if (!is_empty()) {
            IntNode* prevTop = top;
            int data = top->data;
            top = top->next;
            delete prevTop;
            return data;
        }
        throw runtime_error("Error: Attempting to pop a stack with no elements.");
    }

    bool is_empty() {  
        return top == NULL;  
    }
};

int main() {

    cout << "### LINKED LIST DEMO ###" << endl;
    // Creation
    IntNode* head = new IntNode(1);
    IntNode* tail = head;
    cout << "This is a linked list with the first input as " << head->data << endl;
    for(int i = 2; i < 5; i++) {
        IntNode* newTail = new IntNode(i);
        tail->next = newTail;
        tail = newTail;
        cout << "A new input is added to the linked list: " << tail->data << endl;
    }

    // Traversal
    IntNode* currentNode = head;
    cout << "Traversing through the linked list gives us: ";
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

    cout << endl << "### STACK DEMO ###" << endl;
    IntStack s;
    cout << "Pushed 1 into the stack" << endl;
    s.push(1);
    cout << "Top of the stack is " << s.peek() << endl;
    cout << "Pushed 2 into the stack" << endl;
    s.push(2); 
    cout << "Top of the stack is " << s.peek() << endl;
    cout << "Popped " << s.pop() << " out of the stack" << endl;

    // Extra Tests
    cout << "Popped " << s.pop() << " out of the stack" << endl;
    if (s.is_empty()) {
        cout << "Stack is empty" << endl;
    }
    
    try {
        s.pop();
    } catch (runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}