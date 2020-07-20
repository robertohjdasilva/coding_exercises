#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complexity: Time = O(n), Space = O(1)
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    // Exceptions:
    // 1. If position goes past the end of the list, just add at the end
    // 2. If the lst is empty, add node at head
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    // head -----> NULL
    //   |
    //   --->  newNode
    if (head == NULL) { head = newNode; return head; }

    // head      ->     0 -> 1 -> 2 -> 3
    //   |              ^
    //   |              |
    //   ---> newNode ---
    //if (position == 0) {
    //    newNode->next = head->next;
    //    head = newNode;
    //    return head;
    //}

    // Note: position is 0-based. 
    // The goal is to find the previous node.
    // Example: position = 2
    //                   |
    // head -> 0 -> 1 -> 2 -> 3
    //              |
    //             prev
    SinglyLinkedListNode* prevNode = head;
    int prevPosition = 0;
    //                                0       <    1
    while (prevNode != NULL && prevPosition < position - 1) {
        // Find the element at position - 1, so we can insert the newNode at position
        prevPosition++;
        prevNode = prevNode->next;
    }

    // Adjust pointers
    //            prev
    //             |
    // head-> 0 -> 1    -> 2 ->   3
    //             |       |
    //             ---> newNode
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return head;
}