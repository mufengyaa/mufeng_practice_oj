#define _CRT_SECURE_NO_WARNINGS

//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}