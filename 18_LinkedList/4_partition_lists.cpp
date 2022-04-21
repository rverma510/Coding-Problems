// https://leetcode.com/problems/partition-list

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode *par1 = new ListNode(INT_MIN);
    ListNode *tmp1 = par1;
    ListNode *par2 = new ListNode(INT_MIN);
    ListNode *tmp2 = par2;
    
    while (head != NULL) {
        if (head -> val < x) {
            tmp1 -> next = head;
            tmp1 = tmp1 -> next;
        }
        else {
            tmp2 -> next = head;
            tmp2 = tmp2 -> next;
        }
        head = head -> next;
    }
    tmp2 -> next = NULL;
    tmp1 -> next = par2 -> next;
    return par1 -> next;
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
    int x;
    cin >> x;
    head = head -> next;
    ListNode *newHead = partition(head, x);
    while (newHead != NULL) {
        cout << newHead -> val << ' ';
        newHead = newHead -> next;
    }
    cout << '\n';
    return 0;
}