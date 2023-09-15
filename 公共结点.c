#define _CRT_SECURE_NO_WARNINGS

//输入两个链表，找出它们的第一个公共结点

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int lenA = 0, lenB = 0;
    struct ListNode* curA = headA, * curB = headB;
    //计算链表长度
    while (curA) {
        ++lenA;
        curA = curA->next;
    }

    while (curB) {
        ++lenB;
        curB = curB->next;
    }

    int gap = abs(lenA - lenB);
    struct ListNode* longList = headA, * shortList = headB;
    if (lenA < lenB) {
        longList = headB;
        shortList = headA;
    }
    //让长链表先走几步
    while (gap--) {
        longList = longList->next;
    }
    //两个链表同时走，直到遇到相同的节点
    while (longList && shortList)
    {
        if (longList == shortList) {
            return longList;
        }
        else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }

    return NULL;
}
