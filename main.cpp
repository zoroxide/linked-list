#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List myList;

    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);
    myList.insertAtBegin(5);

    cout << "list: ";
    myList.display();

    myList.deleteAtBegin();
    cout << "After deleting the first node: ";
    myList.display();

    myList.insertBefore(20, 15);
    cout << "After inserting 15 before 20: ";
    myList.display();

    myList.insertAfter(15, 17);
    cout << "After inserting 17 after 15: ";
    myList.display();

    myList.sort();
    cout << "After sorting: ";
    myList.display();

    myList.replace(17, 100);
    cout << "After replacing 17 with 100: ";
    myList.display();

    myList.swapNodes(100, 15);
    cout << "After swapping 100 and 15: ";
    myList.display();

    myList.deleteAtEnd();
    cout << "After deleting the last node: ";
    myList.display();

    myList.reverse();
    cout << "After Reversing the entire List: ";
    myList.display();

    return 0;
}
