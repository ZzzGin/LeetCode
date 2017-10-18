class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// deal with 0
		if (l1->val == 0 && l1->next == NULL) return l2;
		if (l2->val == 0 && l2->next == NULL) return l1;

		ListNode* resultWithHead = new ListNode(0);
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* pr = resultWithHead;
		int sum = 0;
		int plusOne = 0;

		while (p1 != NULL && p2 != NULL) {
			sum = p1->val + p2->val + plusOne;
			ListNode* nextOne = new ListNode(sum % 10);
			plusOne = sum / 10;
			pr->next = nextOne;
			p1 = p1->next;
			p2 = p2->next;
			pr = pr->next;
		}
		if (p1 == NULL) {
			while (p2 != NULL) {
				ListNode* nextOne = new ListNode((p2->val + plusOne) % 10);
				plusOne = (p2->val + plusOne) / 10;
				pr->next = nextOne;
				pr = pr->next;
				p2 = p2->next;
			}
		}
		else if (p2 == NULL) {
			while (p1 != NULL) {
				ListNode* nextOne = new ListNode((p1->val + plusOne) % 10);
				plusOne = (p1->val + plusOne) / 10;
				pr->next = nextOne;
				pr = pr->next;
				p1 = p1->next;
			}
		}
		if (plusOne >= 1) {
			ListNode* nextOne = new ListNode(plusOne);
			pr->next = nextOne;
		}
		return resultWithHead->next;
	}
};