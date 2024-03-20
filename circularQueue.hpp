#ifndef INCLUDED_CIRCULARQUEUE_HPP
#define INCLUDED_CIRCULARQUEUE_HPP

#include <iostream>

const int MAXSIZE = 6;

class Queue {
private:
    struct QueueElement {
        char payload[6];
        int dest;
    };
    QueueElement queue[MAXSIZE];
    QueueElement *head, *tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}
    bool validate(const char* input);
    void enqueue();
    void dequeue();
    void showQueue();
    bool isEmpty() const;
    bool isFull() const;
};

#endif