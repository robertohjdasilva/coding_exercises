SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    // Empty list
    if (head == NULL) {
        return newNode;
    }
    // Insert at position 0 == head
    // head -> 1
    //    new
    if (position == 0) {
        newNode->next = head->next;
        return newNode;
    }
    // Valid head and position > 0 - get previous node before insertion point
    //              |
    // head -> 0 -> 1 -> 2
    //            new
    SinglyLinkedListNode *currNode = head;
    int count = 0;
    while (currNode->next != NULL && count < position - 1) {
        count++;
        currNode = currNode->next;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
    return head;
}