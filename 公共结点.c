#define _CRT_SECURE_NO_WARNINGS

//�������������ҳ����ǵĵ�һ���������

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int lenA = 0, lenB = 0;
    struct ListNode* curA = headA, * curB = headB;
    //����������
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
    //�ó��������߼���
    while (gap--) {
        longList = longList->next;
    }
    //��������ͬʱ�ߣ�ֱ��������ͬ�Ľڵ�
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