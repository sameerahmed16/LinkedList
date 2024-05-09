#include <iostream>

using namespace std;

typedef int Type;

class Node {
public:
    Type data;
    Node* next;
};

int GetLength(Node* first) {
    // Implement this
    int i = 0;
    Node * cur = first;
    while (cur != NULL){
        i++;
        cur = cur->next;
    }
    return i;
}

Type GetElement(Node* first, int position) {
    // Implement this

    Node * cur = first;
    int i = 0;

    while (cur != NULL) {
        if (i != position) {
            cur = cur->next;
        }
        else{
            return cur->data;
        }
        i++;
    }
}

void RemoveValues(Node * &first, Type valueToRemove){
    Node *cur = first;
    Node *prev = NULL;

    while (cur != NULL) {
        if (cur->data == valueToRemove) {
            Node *temp = cur;
            cur = cur->next;

            if (prev != NULL) {
                prev->next = cur;
            } else {
                first = cur;
            }
            delete temp;

        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}



void insert(Node*& first, unsigned position, Type data) {
    if (position == 0) {
        Node* temp = first;
        first = new Node;
        first->data = data;
        first->next = temp;
    }
    else {
        Node* prev = first;
        int currentIndex = 1;
        while (currentIndex < position) {
            prev = prev->next;
            currentIndex++;
        }
        Node* temp = prev->next;
        prev->next = new Node;
        prev->next->data = data;
        prev->next->next = temp;
    }
}

void display(Node* first) {
    Node* cur = first;
    while (cur != NULL) {
        cout << (cur->data) << " ";
        cur = cur->next;
    }
    cout << endl;
}

void remove(Node*& first, unsigned position) {
    if (position == 0) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
    else {
        Node* prev = first;
        int currentIndex = 1;
        while (currentIndex < position) {
            prev = prev->next;
            currentIndex++;
        }
        Node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }
}

Node* NewLinkedList(Type * arr, unsigned size) {
    Node* first = NULL;
    for (int i = size - 1; i >= 0; i--) {
        insert(first, 0, arr[i]);
    }

    return first;
}

int main() {
    {
        cout << "Given linked list: ";
        Type arr[] = { 10,4,2,6,42,50 };
        Node* first = NewLinkedList(arr, 6);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        cout << "Element at position " << 3 << " is " << GetElement(first, 3) << endl;
        cout << endl;
    }

    {
        cout << "Given linked list: ";
        Type arr[] = { 5,2,6,4,6 };
        Node* first = NewLinkedList(arr, 5);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        cout << "Element at position " << 0 << " is " << GetElement(first, 0) << endl;
        cout << endl;
    }

    {
        cout << "Given linked list: ";
        Type arr[] = { 1,3,5,7,9,11,53,70 };
        Node* first = NewLinkedList(arr, 8);
        display(first);
        cout << "The length is " << GetLength(first) << endl;
        cout << "Element at position " << 7 << " is " << GetElement(first, 7) << endl;
        cout << "After removing all 1s from the linked list, the list becomes: " << endl;
        RemoveValues(first, 1);
        display(first);
        cout << endl;
    }

    {
        cout << "Given linked list: ";
        Type arr[] = { 1,3,3,7,3,3,2,3 };
        Node* first = NewLinkedList(arr, 8);
        display(first);
        cout << "After removing all 3s from the linked list, the list becomes: " << endl;
        RemoveValues(first, 3);
        display(first);
        cout << endl;
    }
}

/*
 * Given linked list: 10 4 2 6 42 50
The length is 6
Element at position 3 is 6

Given linked list: 5 2 6 4 6
The length is 5
Element at position 0 is 5

Given linked list: 1 3 5 7 9 11 53 70
The length is 8
Element at position 7 is 70
After removing all 1s from the linked list, the list becomes:
3 5 7 9 11 53 70

Given linked list: 1 3 3 7 3 3 2 3
After removing all 3s from the linked list, the list becomes:
1 7 2

 */
