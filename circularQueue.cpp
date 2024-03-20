#include "circularQueue.hpp"

bool Queue::isEmpty() const {
    return head == nullptr;
}

bool Queue::isFull() const {
    return ((tail + 1 - queue) % MAXSIZE) == (head - queue);
}

bool Queue::validate(const char* input) {
    return strlen(input) < 6;
}

void Queue::enqueue() {
    if (isFull()) {
        std::cout << "Queue overflow" << std::endl;
        return;
    }

    std::cout << "Enter payload (less than 6 characters): ";
    char input[6];
    std::cin >> input;

    if (!validate(input)) {
        std::cout << "Payload greater than 7 characters" << std::endl;
        return;
    }

    if (isEmpty()) {
        head = tail = &queue[0];
    } else {
        tail = &queue[(tail + 1 - queue) % MAXSIZE];
    }

    strcpy(tail->payload, input);
    std::cout << "Enter destination: ";
    std::cin >> tail->dest;

    showQueue();
}

void Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue underflow" << std::endl;
        return;
    }

    std::cout << "DEQUEUED ELEMENT: " << head->payload << " to " << head->dest << std::endl;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = &queue[(head + 1 - queue) % MAXSIZE];
    }

    showQueue();
}

void Queue::showQueue() {
    std::cout << "Queue: " << std::endl;
    if (!isEmpty()) {
        int startIndex = head - queue;
        int endIndex = tail - queue;
        for (int i = 0; i < MAXSIZE; ++i) {
            int index = (startIndex + i) % MAXSIZE;
            if (startIndex <= endIndex ? (i <= endIndex - startIndex) : (index >= startIndex || index <= endIndex)) {
                std::cout << i + 1 << ": " << queue[index].payload << " to " << queue[index].dest << std::endl;
            } else {
                std::cout << i + 1 << ": blank" << std::endl;
            }
        }
    } else {
        for (int i = 0; i < MAXSIZE; ++i) {
            std::cout << i + 1 << ": blank" << std::endl;
        }
    }
    std::cout << "Head location: " << (head ? (head - queue + 1) : 0) << ", Tail location: " << (tail ? (tail - queue + 1) : 0) << std::endl;
}

