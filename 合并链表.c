#define _CRT_SECURE_NO_WARNINGS

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL, * t = NULL;
    if (list1 == NULL) {
        return list2;
    }
    else if (list2 == NULL) {
        return list1;
    }
    else {
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }
        t = head;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                t->next = list1;
                t = list1;
                list1 = list1->next;
            }
            else {
                t->next = list2;
                t = list2;
                list2 = list2->next;
            }
        }
        while (list1) {
            t->next = list1;
            t = list1;
            list1 = list1->next;
        }
        while (list2) {
            t->next = list2;
            t = list2;
            list2 = list2->next;
        }
        t->next = NULL;
        return head;
    }
}
