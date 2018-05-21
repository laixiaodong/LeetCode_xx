
#include "stdafx.h"
#include<vector>
using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * result = NULL;
		ListNode * head = NULL;
		int carry = 0;
		while (l1 != NULL || l2 != NULL) {
			if (l1 == NULL) {
				l1 = new ListNode(0);
			}
			if (l2 == NULL) {
				l2 = new ListNode(0);
			}
			int num = l1->val + l2->val + carry;
			ListNode * temp = new ListNode(0);
			if (num >= 10) {
				temp->val = num % 10;
				temp->next = NULL;
				if (result == NULL) {
					result = temp;
					head = result;
				}
				else {
					result->next = temp;
					result = result->next;
				}
				carry = 1;
			}
			else {
				temp->val = num;
				temp->next = NULL;
				if (result == NULL) {
					result = temp;
					head = result;
				}
				else {
					result->next = temp;
					result = result->next;
				}
				carry = 0;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		if (carry) {
			ListNode * temp = new ListNode(1);
			result->next = temp;
		}
		return head;
	}
};