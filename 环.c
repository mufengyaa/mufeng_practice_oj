#define _CRT_SECURE_NO_WARNINGS

//给定一个链表，判断链表中是否有环

//开数组记录地址
bool hasCycle(struct ListNode* head) {
    if (head == NULL) {
        return false;
    }
    if (head->next == NULL) {
        return false;
    }
    struct ListNode* phead = head;
    struct ListNode* book[10000] = { 0 };
    int i = 0;
    while (phead != NULL) {
        book[i++] = phead;
        phead = phead->next;
        for (int j = 0; j < i; j++) {
            if (book[j] == phead) {
                return true;
            }
        }
    }
    return false;
}
//快慢指针
bool hasCycle(struct ListNode* head) {
    if (head == NULL) {
        return false;
    }
    if (head->next == NULL) {
        return false;
    }
    struct ListNode* slow = head, * fast = head->next;   //如果同时赋值head,则无法进入循环
    while (slow != fast) {    //如果为slow>fast,当两个节点成环时,永远也无法实现
        if (fast == NULL) {
            return false;
        }
        if (fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}