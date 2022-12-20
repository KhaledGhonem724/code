#include <string>
#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
struct dnode {
    int data;
    dnode* next;
    dnode* pre;
};
class Queue {
private:
    node* front;
    node* rear;
public:
    Queue() {
        front = NULL;// like head
        rear = NULL;// like tail
    }
    string enqueue(int val) {
        node* temp = new node();
        temp->data = val;
        temp->next = NULL;
        if (IsEmpty()) {
            front = rear = temp;
            return "enqueued " + to_string(val) + " done !\n";
        }
        rear->next = temp;
        rear = temp;
        return "enqueued " + to_string(val) + " done !\n";

    }
    string dequeue() {
        if (IsEmpty())
        {
            return "Queue empty before dequeue\n";
        }
        if (front->next == NULL)
        {
            front = rear = NULL;
            return "dequeue done !\n";
        }
        node* temp = front;
        front = front->next;
        free(temp);
        return "dequeue done !\n";
    }
    string getfront() {
        if (IsEmpty()) {
            return "Queue empty before getfront\n";
        }
        return "front = " + to_string(front->data) + " \n";
    }
    bool IsEmpty() {
        return front == NULL;
    }
    string display() {
        if (IsEmpty())
        {
            return "[ ]\n";
        }
        string s = "[ ";
        node* i = front;
        while (i->next != NULL) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + to_string(i->data) + " ]\n ";
        return s;
    }
};
class DoubleQueue {
private:
    dnode* front;
    dnode* rear;
public:
    DoubleQueue() {
        front = NULL;// like head
        rear = NULL;// like tail
    }
    string enqueue_back(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (isEmpty())
        {
            front = rear = temp;
            return "enqueued " + to_string(val) + " done !\n";
        }
        temp->pre = rear;
        rear->next = temp;
        rear = temp;
        return "enqueued " + to_string(val) + " done !\n";

    }
    string enqueue_front(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (isEmpty())
        {
            front = rear = temp;
            return "enqueued " + to_string(val) + " done !\n";
        }
        temp->next = front;
        front->pre = temp;
        front = temp;
        return "enqueued " + to_string(val) + " done !\n";

    }
    string dequeue_front() {
        if (isEmpty())
        {
            return "doubleQueue empty before dequeue\n";
        }
        if (front->next == NULL)
        {
            front = rear = NULL;
            return "dequeue done !\n";
        }
        dnode* temp = front;
        front = front->next;
        front->pre = NULL;
        free(temp);
        return "dequeue done !\n";
    }
    string dequeue_back() {
        if (isEmpty())
        {
            return "doubleQueue empty before dequeue\n";
        }
        if (front->next == NULL)
        {
            front = rear = NULL;
            return "dequeue done !\n";
        }
        dnode* temp = rear;
        rear = rear->pre;
        rear->next = NULL;
        free(temp);
        return "dequeue done !\n";

    }
    string getFront() {
        if (isEmpty()) {
            return "doubleQueue empty before getfront\n";
        }
        return "front = " + to_string(front->data) + " \n";
    }
    string getRear() {
        if (isEmpty()) {
            return "doubleQueue empty before getRear\n";
        }
        return "rear = " + to_string(rear->data) + " \n";
    }
    bool isEmpty() {
        return front == NULL;
    }
    string display() {
        if (isEmpty()) {
            return "[ ]\n";
        }
        dnode* i = front;
        string s = "[ ";
        while (i->next != NULL) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + to_string(i->data) + " ]\n ";
        return s;
    }
};
class CircularQueue {
private:
    node* front;
    node* rear;
public:
    CircularQueue() {
        front = NULL;// like head
        rear = NULL;// like tail
    }
    string enqueue(int val) {
        node* temp = new node();
        temp->data = val;
        temp->next = front;
        if (IsEmpty()) {
            front = rear = temp;
            return "enqueued " + to_string(val) + " done !\n";
        }
        rear->next = temp;
        rear = temp;
        return "enqueued " + to_string(val) + " done !\n";

    }
    string dequeue() {
        if (IsEmpty())
        {
            return "circularQueue empty before dequeue\n";
        }
        if (front->next == front)
        {
            front = rear = NULL;
            return "dequeue done !\n";
        }
        node* temp = front;
        rear->next = front->next;
        front = front->next;
        free(temp);
        return "dequeue done !\n";

    }
    string getfront() {
        if (IsEmpty()) {
            return "circularQueue empty before getfront\n";
        }
        return "front = " + to_string(front->data) + " \n";
    }
    bool IsEmpty() {
        return front == NULL;
    }
    string display() {
        if (IsEmpty())
        {
            return "[ ]\n";
        }
        string s = "[ ";
        node* i = front;
        while (i->next != front) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + to_string(i->data) + " ]\n";
        return s;
    }
    string circural_display(int elements) {
        if (IsEmpty())
        {
            return "[ ]\n";
        }
        string s = "[ ";
        node* i = front;
        while (elements--) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + " ]\n";
        return s;
    }
};
int main()
{
}
