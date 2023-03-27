#define _CRT_SECURE_NO_WARNINGS

//����һ����������������е�����k�����

//������������
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* p = pListHead;
	int count = 1;
	if (pListHead == NULL) {
		return NULL;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
			count++;
		}
		int num = count - k;
		if (num >= 0 && num <= count - 1) {
			p = pListHead;
			while (num--) {
				p = p->next;

			}
			return p;
		}
		else {
			return NULL;
		}
	}
}
//˫ָ��1
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* slow = pListHead, * fast = pListHead;
	if (pListHead == NULL) {
		return NULL;
	}
	if (k == 0) {
		return NULL;
	}
	while (--k) {
		if (fast->next == NULL) {
			return NULL;
		}
		fast = fast->next;
	}
	while (fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
//˫ָ��2
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode* slow = pListHead, * fast = pListHead;
	if (pListHead == NULL) {
		return NULL;
	}
	if (k == 0) {
		return NULL;
	}
	while (k--) {
		if (fast == NULL) {
			return NULL;
		}
		fast = fast->next;
	}
	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}