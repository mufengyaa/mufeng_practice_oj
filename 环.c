#define _CRT_SECURE_NO_WARNINGS

//����һ�������ж��������Ƿ��л�

//�������¼��ַ
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
//����ָ��
bool hasCycle(struct ListNode* head) {
    if (head == NULL) {
        return false;
    }
    if (head->next == NULL) {
        return false;
    }
    struct ListNode* slow = head, * fast = head->next;   //���ͬʱ��ֵhead,���޷�����ѭ��
    while (slow != fast) {    //���Ϊslow>fast,�������ڵ�ɻ�ʱ,��ԶҲ�޷�ʵ��
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