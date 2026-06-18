#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Linkedlist {
private:
    Node* head;

public:
    Linkedlist() { head = NULL; }

    
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

   
    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }


    void insertAtPosition(int pos, int val) {
        if (pos == 1) {
            insertAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) return;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    
    void deleteHead() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteTail() {
        if (head == NULL) return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

 
    void deleteByValue(int val) {
        if (head == NULL) return;

        if (head->data == val) {
            deleteHead();
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val)
            temp = temp->next;

        if (temp->next == NULL) return;

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

  
    bool search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

 
    int length() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

 
    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

   
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL"<<endl;;
    }
};

int main() {
    Linkedlist list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(30);
    list.insertAtPosition(2, 25);

    cout << "List: ";
    list.printList();

    list.deleteHead();
    list.deleteTail();
    list.deleteByValue(25);

    cout << "After deletions: ";
    list.printList();

    cout << "Search 10: " << list.search(10) << endl;
    cout << "Length: " << list.length() << endl;

    list.reverseList();
    cout << "Reversed: ";
    list.printList();

    return 0;
}
