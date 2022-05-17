// https://leetcode.com/problems/insertion-sort-list

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode *res = new ListNode(INT_MIN);
        res -> next = head;
        ListNode *prev = head;
        ListNode *curr = nullptr;
        while (prev -> next != nullptr) {
            curr = prev -> next;
            if (prev -> val > curr -> val) {
                ListNode *pos = res;
                while (pos -> next != curr) {
                    if (pos -> next -> val > curr -> val) break;
                    pos = pos -> next;
                }
                prev -> next = curr -> next;
                curr -> next = pos -> next;
                pos -> next = curr;
            }
            else {
                prev = curr;
            }
        }
        return res -> next;
    }
};

ListNode* input() {
    int n;
    cin >> n;
    ListNode *head = new ListNode(-1);
    ListNode *tmp = head;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        tmp -> next = new ListNode(val);
        tmp = tmp -> next;
    }
    return head -> next;
}

void print(ListNode *head) {
    while (head != nullptr) {
        cout << head -> val << ' ';
        head = head -> next;
    }
    cout << '\n';
}

int main() {
    ListNode *head = input();
    Solution sol;
    head = sol.insertionSortList(head);
    print(head);
    return 0;
}