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
class LinkedList {
private:
    node* head, * tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    string insert_first(int value)
    {
        node* temp = new node;
        temp->data = value;
        if (IsEmpty())
        {
            temp->next = NULL;
            head = tail = temp;
            return "insert done !\n";
        }
        temp->next = head;
        head = temp;
        return "insert done !\n";

    }
    string insert_last(int value) {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (IsEmpty())
        {
            head = temp;
            tail = temp;
            return "insert done !\n";
        }
        tail->next = temp;
        tail = temp;
        return "insert done !\n";
    }
    string delete_first() {
        if (IsEmpty())
        {
            return "already empty !\n";
        }
        node* temp = new node;
        temp = head;
        head = head->next;
        delete temp;
        return "deletion done !\n";

    }
    string delete_last() {
        if (IsEmpty())
        {
            return "already empty !";
        }
        node* current = new node;
        node* prev = new node;
        current = head;
        while (current != tail)
        {
            prev = current;
            current = current->next;
        }
        tail = prev;
        prev->next = NULL;
        free(current);
        return "deletion done !\n";

    }
    string deleteByValue(int value) {
        if (IsEmpty())
        {
            return "already empty !\n";
        }
        node* temp = new node;
        node* i = new node;
        i = head;
        if (i->next == NULL && i->data == value)
        {
            temp = head;
            tail = head = NULL;
            free(temp);
            return "deletion done !\n";
        }
        if (i->data == value)
        {
            temp = i;
            i = i->next;
            head = i;
            free(temp);
            return "deletion done !\n";
        }
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                i->next = temp->next;
                free(temp);
                return "deletion done !\n";
            }
            i = i->next;
        }
        if (i->next->data == value)
        {
            temp = i->next;
            i->next = NULL;
            free(temp);
            tail = i;
            return "deletion done !\n";
        }
        return "value not found ! \n";
    }
    string display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        node* temp = new node;
        temp = head;
        while (temp != tail) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
    bool IsEmpty() {
        return head == NULL;
    }
};
class CircularLinkedList {
private:
    node* head, * tail;
public:
    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }
    string insert_last(int value) {
        node* temp = new node;
        temp->data = value;
        if (IsEmpty()) {
            temp->next = temp;
            tail = head = temp;
            return "insert done !\n";

        }
        else {
            temp->next = head;
            tail->next = temp;
            tail = temp;
            return "insert done !\n";
        }
    }
    string insert_first(int value) {
        node* temp = new node;
        temp->data = value;
        if (IsEmpty()) {
            temp->next = temp;
            tail = head = temp;
            return "insert done !\n";

        }
        else {
            temp->next = head;
            tail->next = temp;
            head = temp;
            return "insert done !\n";

        }
    }
    bool IsEmpty() {
        return head == NULL;
    }
    string deleteByValue(int value) {
        if (IsEmpty())
        {
            return "already empty !\n";
        }
        node* temp = new node;
        node* i = new node;
        i = head;
        if (head->next == head && head->data == value)
        {
            temp = head;
            free(temp);
            head = tail = NULL;
            return "deletion done !\n";
        }
        if (i->data == value)
        {
            temp = i;
            i = i->next;
            tail->next = i;
            head = i;
            free(temp);
            return "deletion done !\n";
        }
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                i->next = temp->next;
                free(temp);
                return "deletion done !\n";
            }
            i = i->next;
        }
        if (i->next->data == value)
        {
            temp = i->next;
            i->next = NULL;
            free(temp);
            tail = i;
            return "deletion done !\n";
        }
        return "value not found ! \n";
    }
    string display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        node* temp = new node;
        temp = head;
        while (temp != tail) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
    string circular_display(int elements) {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        node* temp = new node;
        temp = head;
        while (elements--) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + "\n";
        return s;
    }
};
class DoubleLinkedList {
private:
    dnode* head;
    dnode* tail;
public:
    DoubleLinkedList() {
        head = NULL;// like head
        tail = NULL;// like tail
    }
    string insert_last(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            head = tail = temp;
            return "insert done !\n";
        }
        temp->pre = tail;
        tail->next = temp;
        tail = temp;
        return "insert done !\n";
    }
    string insert_first(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            head = tail = temp;
            return "insert done !\n";
        }
        temp->next = head;
        head->pre = temp;
        head = temp;
        return "insert done !\n";
    }
    string deleteByValue(int value) {
        if (IsEmpty())
        {
            return "already empty !\n";
        }
        dnode* temp = new dnode;
        if (head->next == NULL && head->data == value)
        {
            temp = head;
            head = tail = NULL;
            free(temp);
            return "deletion done !\n";
        }
        if (tail->data == value)
        {
            temp = tail;
            tail = tail->pre;
            tail->next = NULL;
            free(temp);
            return "deletion done !\n";
        }
        dnode* i = new dnode;
        i = head;
        if (i->data == value)
        {
            temp = i;
            i = i->next;
            i->pre = NULL;
            head = i;
            free(temp);
            return "deletion done !\n";
        }
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                temp->next->pre = i;
                i->next = temp->next;
                free(temp);
                return "deletion done !\n";
            }
            i = i->next;
        }
        return "value not found ! \n";
    }
    bool IsEmpty() {
        return head == NULL;
    }
    string display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        dnode* temp = new dnode;
        temp = head;
        while (temp != tail) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
    string reverse_display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        dnode* temp = new dnode;
        temp = tail;
        while (temp != head) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->pre;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
};
int main()
{
}