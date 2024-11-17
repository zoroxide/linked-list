//
// Created by Loay on 11/11/2024
//

#include "List.h"

using namespace std;

// Node Class Constructor
Node::Node(const int d) {
    data = d;
    next = nullptr;
}

// List Class Constructor
List::List() {
    head = nullptr;
}

List::~List() {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

bool List::isEmpty() {
    return head == nullptr;
}

void List::insertAtBegin(const int d) {
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

void List::insertAtEnd(const int d) {
    Node *newNode = new Node(d);
    if (isEmpty()) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void List::display() {
    if (isEmpty()) {
        cout << "The list is empty." << endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void List::deleteAtEnd() {
    if (isEmpty()) {
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void List::deleteAtBegin() {
    if (isEmpty()) {
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

int List::count() {
    int count = 0;
    Node *temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool List::search(const int d) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == d) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void List::insertBefore(const int target, const int d) {
    if (isEmpty()) {
        return;
    }
    if (head->data == target) {
        insertAtBegin(d);
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cerr << "Target not found." << endl;
        return;
    }
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

void List::insertAfter(const int target, const int d) {
    if (isEmpty()) {
        return;
    }
    Node *temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cerr << "Target not found." << endl;
        return;
    }
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

/**
     *
     * this is my implementation of replaceValue function that me and beshoy implemented in the lecture (Lecture 7)
     *
 */
void List::replace(const int target, const int d) {
    if (isEmpty()) {
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == target) {
            temp->data = d;
            return;
        }
        temp = temp->next;
    }
    cerr << "Target not found." << endl;
}

/**
     *
     * this is my implementation of swapNodes function that me and beshoy implemented in the lecture (Lecture 7)
     *
 */
void List::swapNodes(const int d1, const int d2) {
    if (d1 == d2) return;  // No need to swap if the values are the same

    Node *prev1 = nullptr, *curr1 = head;
    // Search for the first node (d1)
    while (curr1 != nullptr && curr1->data != d1) {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    Node *prev2 = nullptr, *curr2 = head;
    // Search for the second node (d2)
    while (curr2 != nullptr && curr2->data != d2) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    // If either of the nodes is not found, exit
    if (curr1 == nullptr || curr2 == nullptr) {
        cerr << "One or both elements not found." << endl;
        return;
    }

    // If the nodes are adjacent
    if (curr1->next == curr2) {
        // Swap the pointers
        curr1->next = curr2->next;
        curr2->next = curr1;
        // Update the previous node's next pointer
        if (prev1 != nullptr) prev1->next = curr2;
        else head = curr2; // If curr1 was the head, update head

        return;
    }

    // If the nodes are not adjacent
    if (prev1 != nullptr) prev1->next = curr2;
    else head = curr2; // If curr1 was the head, update head

    if (prev2 != nullptr) prev2->next = curr1;
    else head = curr1; // If curr2 was the head, update head

    // Swap the next pointers of the nodes
    Node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}


void List::sort() {
    if (isEmpty() || head->next == nullptr) {
        return; // No need to sort if the list is empty or has only one node
    }

    Node *left = head;

    while (left != nullptr) {
        Node *right = left->next;

        while (right != nullptr) {
            if (left->data > right->data) {
                swapNodes(left->data, right->data);
            }
            right = right->next;
        }
        left = left->next;
    }
}



void List::reverse() {
    if (!(isEmpty() || head->next == nullptr)) {
        const Node *left = head;
        const Node *right = head;

        // Move the right pointer to the last node
        while (right->next != nullptr) {
            right = right->next;
        }

        // Swap the values until the left pointer meets the right pointer or crosses it
        while (left != right && left->next != right) {
            swapNodes(left->data, right->data);

            // Move the left pointer forward and the right pointer backward
            left = left->next;

            // To move the right pointer backward, we need a helper pointer
            Node *prev = head;
            while (prev->next != right) {
                prev = prev->next;
            }
            right = prev;
        }
    }
}

