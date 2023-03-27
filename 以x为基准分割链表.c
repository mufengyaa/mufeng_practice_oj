#define _CRT_SECURE_NO_WARNINGS

//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ

//˼·:�½���������,���ƴ����һ��
ListNode* partition(ListNode* pHead, int x) {
    if (pHead == NULL)
        return NULL;

    struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
    //���������ͷ
    lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
    greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = pHead;
    while (cur)
    {
        //С��x��β�嵽lessTail
        if (cur->val < x)
        {
            lessTail->next = cur;
            lessTail = lessTail->next;
        }
        //���ڵ���x��β�嵽greaterTail
        else
        {
            greaterTail->next = cur;
            greaterTail = greaterTail->next;
        }
        cur = cur->next;
    }
    //������������
    lessTail->next = greaterHead->next;
    greaterTail->next = NULL;
    //��ȡ��ͷ
    pHead = lessHead->next;
    free(lessHead);
    free(greaterHead);

    return pHead;
}

