#include <iostream>
using namespace std;

class Stack {
private:
    int* stackArray;
    int capacity;
    int top;

public:
    // Constructor
    Stack(int ignored = 0) {
        capacity = 10; // Default stack size
        stackArray = new int[capacity];
        top = -1; // Indicates empty stack
    }

    // Destructor
    ~Stack() {
        delete[] stackArray;
    }

    // Push an element to the stack
    void push(const int dataItem) {
        if (top == capacity - 1) { // Resize if full
            resize();
        }
        stackArray[++top] = dataItem;
    }

    // Pop the top element from the stack
    void pop() {
        if (!isEmpty()) {
            --top;
        } else {
            cout << "Stack is empty! Cannot pop.\n";
        }
    }

    // Peek the top element without removing it
    int peek() {
        if (!isEmpty()) {
            return stackArray[top];
        } else {
            cout << "Stack is empty! Nothing to peek.\n";
            return -1; // Return an invalid value for empty stack
        }
    }

    // Clear the stack
    void clear() {
        top = -1;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

private:
    // Resize the stack when capacity is reached
    void resize() {
        capacity *= 2; // Double the capacity
        int* newArray = new int[capacity];
        for (int i = 0; i <= top; i++) {
            newArray[i] = stackArray[i];
        }
        delete[] stackArray;
        stackArray = newArray;
    }
};

int main() {
    Stack myStack;

    myStack.push(5);
    myStack.push(2);
    myStack.push(3);

    cout << "Top element: " << myStack.peek() << endl;

    myStack.pop();
    cout << "Top element after pop: " << myStack.peek() << endl;

    myStack.clear();
    cout << "Is stack empty after clear? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
