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

    bool isEmpty();
    void insertAtBegin(int d);
    void insertAtEnd(int d);
    void display();
    void deleteAtEnd();
    void deleteAtBegin();
    [[nodiscard]] int count();
    bool search(int d);
    void insertBefore(int target, int d);
    void insertAfter(int target, int d);
    void replace(int target, int d);
    void swapNodes(int d1, int d2);
    void reverse();
    void sort();
};

#endif //LIST_H
