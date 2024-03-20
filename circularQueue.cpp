#include "circularQueue.hpp"
#include <iomanip>

bool Queue::isEmpty() const {
    return head == nullptr;
}

bool Queue::isFull() const {
    return ((tail + 1 - queue) % MAXSIZE) == (head - queue);
}

bool Queue::validate(const char* input) {
    return strlen(input) < 7;
}

void Queue::enqueue() {
    if (isFull()) {
        std::cout << "OVERFLOW" << std::endl;
        return;
    }

    std::cout << "Enter payload (less than 6 characters): ";
    char input[6];
    std::cin >> input;

    if (!validate(input)) {
        std::cout << "Payload greater than 6 characters" << std::endl;
        return;
    }

    if (isEmpty()) {
        head = tail = &queue[0];
    } else {
        tail = &queue[(tail + 1 - queue) % MAXSIZE];
    }

    strcpy(tail->payload, input);

    showQueue();
}

void Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "UNDERFLOW" << std::endl;
        return;
    }

    std::cout << "DEQUEUED ELEMENT: " << head->payload << std::endl;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = &queue[(head + 1 - queue) % MAXSIZE];
    }

    showQueue();
}

void Queue::showQueue() {
    if (!isEmpty()) {
        int startIndex = head - queue;
        int endIndex = tail - queue;

        std::string printOrder[MAXSIZE][2]; // For storing index and payload

        // Initialize printOrder with indexes and empty strings
        for (int i = 0; i < MAXSIZE; ++i) {
            printOrder[i][0] = std::to_string(i + 1); // Convert index to 1-based for display
            printOrder[i][1] = " "; // Initialize payloads with empty strings
        }

        // Populate printOrder with actual payloads
        int currentIndex = startIndex;
        do {
            // Convert index to 1-based for display and store the payload
            printOrder[currentIndex][1] = queue[currentIndex].payload;

            // Move to next index, wrapping around if necessary
            currentIndex = (currentIndex + 1) % MAXSIZE;
        } while (currentIndex != (endIndex + 1) % MAXSIZE); // Continue until we've covered all active elements

        // Print the table in reverse order
        std::cout << " ---------------------------\n";
        std::cout << " | " << std::setw(10) << "Index" << " | " << std::setw(10) << "Payload" << " |\n";
        std::cout << " ---------------------------\n";
        for (int i = MAXSIZE - 1; i >= 0; --i) {
            std::cout << " | " << std::setw(10) << printOrder[i][0] << " | " << std::setw(10) << printOrder[i][1] << " |\n";
        }
        std::cout << " ---------------------------\n";
    } else {
        // If the queue is empty, print an empty table
        std::cout << " ---------------------------\n";
        std::cout << " | " << std::setw(10) << "Index" << " | " << std::setw(10) << "Payload" << " |\n";
        std::cout << " ---------------------------\n";
        for (int i = MAXSIZE; i > 0; --i) {
            std::cout << " | " << std::setw(10) << i << " | " << std::setw(10) << " " << " |\n";
        }
        std::cout << " ---------------------------\n";
    }

    std::cout << "\nHead location: " << (head ? (head - queue + 1) : 0) << std::endl
              << "Tail location: " << (tail ? (tail - queue + 1) : 0) << std::endl;
}





