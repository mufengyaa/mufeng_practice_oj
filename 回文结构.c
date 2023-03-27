#define _CRT_SECURE_NO_WARNINGS

//判断链表是否具有回文结构

struct ListNode* findmid(struct ListNode* head) {   //找到中间结点,并且区分判断奇数偶数个结点的中间结点条件
    struct ListNode* slow = head, * fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == nullptr) {   //如果为偶数个,则fast指向空时,slow为第二个中间结点
        return slow;
    }
    slow = slow->next;    //如果为奇数个,则fast->next指向空时,slow为中间结点,但逆置需要从下一个结点开始(中间结点不参与其中)
    return slow;
}
struct ListNode* reverse(struct ListNode* p) {   //逆置
    struct ListNode* prev = p, * next = p->next, * newhead = p;
    newhead->next = nullptr;  //一定一定一定记得要置空,因为完成逆置后,原头结点为最后一个结点,需要指向空
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
    while (remid) {   //当逆置的链表走向空时,比较过程就结束
        if (A->val != remid->val) {
            return false;
        }
        A = A->next;
        remid = remid->next;
    }
    return true;
}