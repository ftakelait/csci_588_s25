#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

// Linked List Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Helper function to create a linked list from a vector
Node* createLinkedList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* current = head;
    for (size_t i = 1; i < vals.size(); i++) {
        current->next = new Node(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(Node* head) {
    Node* current = head;
    cout << "[";
    while (current) {
        cout << current->data;
        current = current->next;
        if (current) cout << " -> ";
    }
    cout << "]" << endl;
}

// Exercise 1: Insert at k-th position
// Return 1 (success) or -1 (failure if list is not long enough)
int insertAtKthPosition(Node*& head, int k, int value) {
    // If k < 1, consider it invalid for 1-based insertion
    if (k < 1) return -1;

    // Special case: Insert at head (k = 1)
    if (k == 1) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return 1;
    }

    Node* current = head;
    int count = 1;
    // Move to the (k-1)-th node
    while (current && count < (k - 1)) {
        current = current->next;
        count++;
    }

    // If current is null, it means list is too short
    if (!current) {
        return -1;
    }

    // Insert new node after current
    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
    return 1;
}

void exercise1() {
    cout << "Exercise 1: Insert at K-th Position" << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = createLinkedList(arr);

    cout << "Input list: ";
    printLinkedList(head);

    int k = 3;
    int valueToInsert = 99;
    cout << "Inserting value " << valueToInsert << " at position k=" << k << " ..." << endl;

    int result = insertAtKthPosition(head, k, valueToInsert);
    if (result == -1) {
        cout << "List was not long enough to insert at position " << k << endl;
    } else {
        cout << "Insertion successful!" << endl;
    }

    cout << "Updated list: ";
    printLinkedList(head);
    cout << endl;
}

// Exercise 2: Check if one list is the reverse of another
bool isReverseOfEachOther(Node* head1, Node* head2) {
    // Method 1: Reverse one list and compare with the other
    // 1. Reverse head2 into a new list
    Node* prev = nullptr;
    Node* current = head2;
    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    // Now 'prev' is the head of reversed head2

    // 2. Compare head1 and the reversed list
    Node* rev2 = prev;
    Node* c1 = head1;
    while (c1 && rev2) {
        if (c1->data != rev2->data) {
            return false;
        }
        c1 = c1->next;
        rev2 = rev2->next;
    }

    // If both lists ended at the same time, they match
    // Also, if one list is longer, it won't match
    if (c1 == nullptr && rev2 == nullptr) {
        return true;
    }
    return false;
}

void exercise2() {
    cout << "Exercise 2: Check if one list is the reverse of another" << endl;
    // Example: list1 = [1,2,3,4], list2 = [4,3,2,1]
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {4, 3, 2, 1};

    Node* head1 = createLinkedList(arr1);
    Node* head2 = createLinkedList(arr2);

    cout << "List1: ";
    printLinkedList(head1);
    cout << "List2: ";
    printLinkedList(head2);

    bool result = isReverseOfEachOther(head1, head2);
    cout << "Is List2 the reverse of List1? " << (result ? "Yes" : "No") << endl;
    cout << endl;
}

// Exercise 3: Find the middle element in a singly linked list
// Time Complexity: O(n)
int findMiddleElement(Node* head) {
    // Using slow and fast pointers
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;       // Move slow by 1
        fast = fast->next->next; // Move fast by 2
    }
    // When fast reaches the end, slow is at the middle
    return (slow) ? slow->data : -1; // or handle empty list
}

void exercise3() {
    cout << "Exercise 3: Find the middle element" << endl;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* head = createLinkedList(arr);

    cout << "Input list: ";
    printLinkedList(head);

    int middle = findMiddleElement(head);
    cout << "Middle element: " << middle << endl;
    cout << "Time Complexity: O(n)\nBecause I used a slow pointer (moves by 1) and a fast pointer (moves by 2) "
         << "in a single pass, the list is traversed only once, resulting in linear time complexity." << endl;
    cout << endl;
}


// Exercise 4: Print the list in reverse order
void printListReverse(Node* head) {
    if (!head) return;
    printListReverse(head->next);
    cout << head->data << " ";
}

void exercise4() {
    cout << "Exercise 4: Print the list in reverse order" << endl;
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = createLinkedList(arr);

    cout << "Input list: ";
    printLinkedList(head);

    cout << "Reversed list: [ ";
    printListReverse(head);
    cout << "]" << endl << endl;
}

int main() {
    cout << "\n Fouzi Takelait\n CSCI 588\n Homework #4\n" << endl;

    exercise1();
    cout << "--------------------------------------------------------------------------------" << endl;

    exercise2();
    cout << "--------------------------------------------------------------------------------" << endl;

    exercise3();
    cout << "--------------------------------------------------------------------------------" << endl;

    exercise4();
    cout << "--------------------------------------------------------------------------------" << endl;

    return 0;
}
