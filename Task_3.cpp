#include <iostream>
using namespace std;

class Queue {
private:
    int* queueArray;
    int front;
    int rear;
    int capacity;
    int count; // To track the number of elements in the queue

public:
    // Constructor
    Queue(int size = 10) {
        capacity = size;
        queueArray = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor
    ~Queue() {
        delete[] queueArray;
    }

    // Enqueue an element
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue overflow! Resizing the queue...\n";
            resize();
        }
        rear = (rear + 1) % capacity;
        queueArray[rear] = item;
        count++;
    }

    // Dequeue an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! No elements to dequeue.\n";
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    // Peek at the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek.\n";
            return -1; // Return invalid value for empty queue
        }
        return queueArray[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return count == capacity;
    }

    // Count the number of elements in the queue
    int size() {
        return count;
    }

    // Clear the queue
    void clear() {
        front = 0;
        rear = -1;
        count = 0;
        cout << "Queue cleared.\n";
    }

private:
    // Resize the queue to handle overflow
    void resize() {
        int newCapacity = capacity * 2;
        int* newQueueArray = new int[newCapacity];
        for (int i = 0; i < count; i++) {
            newQueueArray[i] = queueArray[(front + i) % capacity];
        }
        delete[] queueArray;
        queueArray = newQueueArray;
        front = 0;
        rear = count - 1;
        capacity = newCapacity;
    }
};

int main() {
    Queue myQueue(3); // Small initial size to test overflow handling

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40); // Causes resize

    cout << "Front element: " << myQueue.peek() << endl;
    cout << "Queue size: " << myQueue.size() << endl;

    myQueue.dequeue();
    cout << "Front element after dequeue: " << myQueue.peek() << endl;

    myQueue.clear();
    cout << "Queue size after clear: " << myQueue.size() << endl;

    return 0;
}
