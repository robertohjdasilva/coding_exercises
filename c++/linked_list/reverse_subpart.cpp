#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};


// Add any helper functions you may need here
Node* reverseSubpart(Node * head, Node** endReversedSubpartNode, Node** afterSubpartNode) {
  Node* prev = NULL;
  *endReversedSubpartNode = head;
  while (head != NULL && (head->data % 2 == 0)) {
    Node* next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  *afterSubpartNode = head;
  return prev;
}

void printLinkedList(Node *head);

// Logic
// 1. Traverse and find beginning of subpart, keeping track of previous
// 2. Reverse subpart and return the new head of subpart as well as last element
//    = The last element can be determine during the revresal itself by checking
//    = for even elements.
// 3. Adjust links for which we need to keep track of:
//    = First element of subpart i.e. beginSubpart
//    = Previous element before subpart i.e. beforeSubpart
//    = Last element of subpart i.e. endSubpart
//
//    beforeSubpart  beginSubpart  endSubpart  afterSubpart
//          |         |                |           |
//          1         2                4           3
//
//            beginReverseSubpart  endReversedSubpartNode
//                    |                |
//          1         4                2           3
//
// Time: O(n), Space: O(1)
// root -> 1 -> 2 -> 8 -> 9 -> 12 -> 16 -> null
//              n    ?
Node* reverse(Node *head) {
  if (head == NULL) {
    return NULL;
  }
  Node* node = head;
  Node* prev = NULL;
  Node* endReversedSubpartNode = NULL;
  Node* afterSubpartNode = NULL;
  
  while (node != NULL) {
    if (node->data % 2) {
      prev = node;
      node = node->next;
      continue;
    }
    // Reverse subpart and make connection
    // beforeSubpart -> beginReverseSubpart
    if (node == head) {
      // Case 1: first subpart begins at head
      head = reverseSubpart(node, &endReversedSubpartNode, &afterSubpartNode);
    } else {
      // Case 2: first subpart begins after head node
      prev->next = reverseSubpart(node, &endReversedSubpartNode, &afterSubpartNode);
    }
    
    // Adjust links
    // endReversedSubpartNode -> afterSubpartNode
    if (endReversedSubpartNode != NULL) endReversedSubpartNode->next = afterSubpartNode;

    // Keep traversing list
    prev = endReversedSubpartNode;
    node = afterSubpartNode;
  }
  return head;
}

void printLinkedList(Node *head) {
  cout << "[";
  while (head != NULL) {
    cout << head -> data;
    head = head -> next;
    if (head != NULL)
      cout << " ";
  }
  cout << "]";
}

int test_case_number = 1;

void check(Node *expectedHead, Node *outputHead) {
  bool result = true;
  Node *tempExpectedHead = expectedHead;
  Node *tempOutputHead = outputHead;
  while (expectedHead != NULL && outputHead != NULL) {
    result &= (expectedHead -> data == outputHead -> data);
    expectedHead = expectedHead -> next;
    outputHead = outputHead -> next;
  }
  if (!(expectedHead == NULL && outputHead == NULL)) result = false;

  if (result) {
    cout << "Test #" << test_case_number << "\n";
  }
  else {
    cout << "Test #" << test_case_number << ": Expected ";
    printLinkedList(tempExpectedHead); 
    cout << " Your output: ";
    printLinkedList(tempOutputHead);
    cout << endl; 
  }
  test_case_number++;
}

Node* createLinkedList(vector<int> arr) {
  Node *head = NULL, *curr = NULL;
  for (int num : arr) {
    if (head == NULL) curr = new Node(num), head = curr;
    else {
      curr->next = new Node(num);
      curr = curr->next;
    }
  }
  return head;
}

int main() {
  Node *head_1 = createLinkedList({1, 2, 8, 9, 12, 16});
  Node *expected_1 = createLinkedList({1, 8, 2, 9, 16, 12});
  Node *output_1 = reverse(head_1);
  check(expected_1, output_1);

  Node *head_2 = createLinkedList({2, 18, 24, 3, 5, 7, 9, 6, 12});
  Node *expected_2 = createLinkedList({24, 18, 2, 3, 5, 7, 9, 12, 6});
  Node *output_2 = reverse(head_2);
  check(expected_2, output_2); 
}