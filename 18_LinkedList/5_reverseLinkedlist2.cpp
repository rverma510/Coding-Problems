// https://leetcode.com/problems/reverse-linked-list-ii

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *leftleftptr, *leftptr, *curr, *prev, *next;
    leftleftptr = leftptr = curr = prev = next = NULL;
    ListNode *res = new ListNode(INT_MIN);
    ListNode *tmp = res;
    res -> next = head;
    int i = 1;
    while (i < left) {
        tmp = tmp -> next;
        i++;
    }
    leftleftptr = tmp;
    leftptr = tmp -> next;
    curr = leftptr;
    while (i <= right) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    leftleftptr -> next = prev;
    leftptr -> next = curr;
    return res -> next;
}

int main() {
    int n;
    cin >> n;
    ListNode *head = new ListNode(-1);
    ListNode *tmp = head;
    for (int v, i = 0; i < n; i++) {
        cin >> v;
        tmp -> next = new ListNode(v);
        tmp = tmp -> next;
    }
    int left, right;
    cin >> left >> right;
    head = head -> next;
    ListNode *newHead = reverseBetween(head, left, right);
    while (newHead != NULL) {
        cout << newHead -> val << ' ';
        newHead = newHead -> next;
    }
    cout << '\n';
    return 0;
}

/*
5
1 2 3 4 5
2 4
*/