#include "circularQueue.hpp"

int main() {
    Queue q;
    char choice;

        while(true) {
            std::cout << "\ne: enqueue, d: dequeue, s: show, q: quit\nEnter your choice: ";
            std::cin >> choice;
            if (choice == 'e') {
                q.enqueue();
            } else if (choice == 'd') {
                q.dequeue();
            } else if (choice == 's') {
                q.showQueue();
            } else if (choice == 'q') {
                std::cout << "Exited Program" << std::endl;
                return 0;
            } else {
                std::cout << "Invalid choice, try again" << std::endl;
            }
        }
}