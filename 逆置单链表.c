#define _CRT_SECURE_NO_WARNINGS

//��תһ��������

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    else {
        struct ListNode* newhead = head, * prev = head, * p = head->next, * next = p;
        prev->next = NULL;
        while (next != NULL) {
            newhead = next;
            next = next->next;
            newhead->next = prev;
            prev = newhead;
        }
        return newhead;
    }
}