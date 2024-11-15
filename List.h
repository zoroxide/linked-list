//
// Created by Loay on 11/11/2024.
//

#ifndef LIST_H
#define LIST_H

#include <bits/stdc++.h>

class Node {
public:
    int data;
    Node *next;

    explicit Node(const int d);
};

class List {
public:
    Node *head;

    List();
    ~List();

    bool isEmpty() const;
    void insertAtBegin(int d);
    void insertAtEnd(int d);
    void display() const;
    void deleteAtEnd();
    void deleteAtBegin();
    [[nodiscard]] int count() const;
    bool search(int d) const;
    void insertBefore(int target, int d);
    void insertAfter(int target, int d) const;
    void replace(int target, int d) const;
    void swapNodes(int d1, int d2);
    void sort();
};

#endif //LIST_H
