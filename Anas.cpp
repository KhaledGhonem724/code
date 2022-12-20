#include <string>
#include <iostream>
using namespace std;
class Array {
    int size;
    int length;
    int* arr;
public:
    Array(int a) {
        if (a <= 0) {
            exit(1);
        }
        else {
            size = a;
            length = 0;
            arr = new int[size];
        }
    }
    bool isempty() {
        return length == 0;
    }
    bool isfull() {
        return length >= size;
    }
    string getlength() {
        return to_string(length);
    }
    string getsize() {
        return to_string(size);
    }
    string Enlarge(int added_size) {
        int* temp = new int[size + added_size];
        for (int i = 0; i < length; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
        size = size + added_size;
        return "enlarged ! ";
    }
    string Sort() {
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
        return "sorted ! ";
    }
    string Display() {
        string s = "[ ";
        for (int i = 0; i < length; i++) {
            s = s + to_string(arr[i]) + " ";
        }
        s = s + "]";
        return s;
    }
    string insert(int newitem) {
        if (isfull())
        {
            return "Array is Full\n";
        }
        else {
            arr[length] = newitem;
            length++;
            return "inserted \n";
        }
    }
    string DeletionByIndex(int index) {
        if (isempty()) {
            return "already empty \n";
        }
        if (index >= 0) {
            for (int i = index; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
            return "deleted \n";
        }
        else {
            return "out of range\n";
        }
    }
    string DeletionByValue(int val) {
        if (isempty()) {
            return "already empty \n";
        }
        for (int i = 0; i < length; i++) {
            if (arr[i] == val)
            {
                for (int j = i; j < length - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                length--;
                return "deleted \n";
            }
        }
        return "not found\n";

    }
};
class Stack {
private:
    node* top;
public:
    Stack() {
        top = NULL;
    }
    string Push(int val) {
        node* temp = new node();
        temp->data = val;
        top == NULL ? temp->next = NULL : temp->next = top;
        top = temp;
        return "pushed " + to_string(val) + " done ! \n";
    }
    string Pop() {
        if (IsEmpyt()) {
            return "Stack empty before Pop\n";
        }
        node* temp = top;
        top = top->next;
        free(temp);
        return "Pop done !\n";

    }
    string Peek() {
        if (IsEmpyt()) {
            return "Stack empty before Peek\n";
            exit(1);
        }
        return "top= " + to_string(top->data) + "\n";
    }
    bool IsEmpyt() {
        return top == NULL;
    }
    string Display() {
        if (IsEmpyt())
        {
            return "[ ]\n";
        }
        string s = "[ ";
        node* i = top;
        while (i->next != NULL) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + to_string(i->data) + " ]\n";
        return s;
    }
};
int main()
{
	
}
