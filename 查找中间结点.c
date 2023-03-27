#define _CRT_SECURE_NO_WARNINGS

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}