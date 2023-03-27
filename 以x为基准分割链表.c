#define _CRT_SECURE_NO_WARNINGS

//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前

//思路:新建两个链表,最后拼接在一块
ListNode* partition(ListNode* pHead, int x) {
    if (pHead == NULL)
        return NULL;

    struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
    //创建链表表头
    lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
    greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = pHead;
    while (cur)
    {
        //小于x的尾插到lessTail
        if (cur->val < x)
        {
            lessTail->next = cur;
            lessTail = lessTail->next;
        }
        //大于等于x的尾插到greaterTail
        else
        {
            greaterTail->next = cur;
            greaterTail = greaterTail->next;
        }
        cur = cur->next;
    }
    //链接两个链表
    lessTail->next = greaterHead->next;
    greaterTail->next = NULL;
    //获取表头
    pHead = lessHead->next;
    free(lessHead);
    free(greaterHead);

    return pHead;
}

