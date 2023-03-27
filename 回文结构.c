#define _CRT_SECURE_NO_WARNINGS

//�ж������Ƿ���л��Ľṹ

struct ListNode* findmid(struct ListNode* head) {   //�ҵ��м���,���������ж�����ż���������м�������
    struct ListNode* slow = head, * fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == nullptr) {   //���Ϊż����,��fastָ���ʱ,slowΪ�ڶ����м���
        return slow;
    }
    slow = slow->next;    //���Ϊ������,��fast->nextָ���ʱ,slowΪ�м���,��������Ҫ����һ����㿪ʼ(�м��㲻��������)
    return slow;
}
struct ListNode* reverse(struct ListNode* p) {   //����
    struct ListNode* prev = p, * next = p->next, * newhead = p;
    newhead->next = nullptr;  //һ��һ��һ���ǵ�Ҫ�ÿ�,��Ϊ������ú�,ԭͷ���Ϊ���һ�����,��Ҫָ���
    while (next != nullptr) {
        newhead = next;
        next = next->next;
        newhead->next = prev;
        prev = newhead;
    }
    return newhead;
}
bool chkPalindrome(ListNode* A) {
    struct ListNode* mid = findmid(A);
    struct ListNode* remid = reverse(mid);
    while (remid) {   //�����õ����������ʱ,�ȽϹ��̾ͽ���
        if (A->val != remid->val) {
            return false;
        }
        A = A->next;
        remid = remid->next;
    }
    return true;
}