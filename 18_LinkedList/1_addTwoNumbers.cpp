// https://leetcode.com/problems/add-two-numbers/
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and 
each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *res = new ListNode(-1);
        ListNode *tmp = res;
        while (l1 != NULL && l2 != NULL) {
            tmp->next = new ListNode((l1 -> val + l2 -> val + carry) % 10);
            carry = (l1 -> val + l2 -> val + carry) / 10;
            tmp = tmp -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1 != NULL) {
            tmp -> next = new ListNode((l1 -> val + carry) % 10);
            carry = (l1 -> val + carry) / 10;
            tmp = tmp -> next;
            l1 = l1 ->next;
        }
        while (l2 != NULL) {
            tmp -> next = new ListNode((l2 -> val + carry) % 10);
            carry = (l2 -> val + carry) / 10;
            tmp = tmp -> next;
            l2 = l2 ->next;
        }
        if (carry != 0) {
            tmp -> next = new ListNode(carry);
        }
        tmp = res;
        res = res->next;
        delete tmp;
        return res;
    }
};