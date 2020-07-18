bool has_cycle(SinglyLinkedListNode* head) {
    if (head == NULL) {
        return false;
    }
    SinglyLinkedListNode *slowPtr = head;
    SinglyLinkedListNode *fastPtr = head;

    while (slowPtr != NULL && fastPtr != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
        if (fastPtr != NULL) fastPtr = fastPtr->next;
        if (slowPtr == fastPtr) return true;
    }
    return false;
}