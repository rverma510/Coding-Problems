

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    ListNode *res = new ListNode(-1);
    ListNode *tmp = res;
    ListNode *prev = head;
    ListNode *curr = head -> next;
        
    while (curr != NULL) {
        if (prev -> val != curr -> val) {
            if (prev -> next == curr) {
                tmp -> next = prev;
                tmp = tmp -> next;
            }
            prev = curr;
        }
        curr = curr -> next;
    }
    if (prev -> next == NULL) {
        tmp -> next = prev;
        tmp = tmp -> next;
    }
    tmp -> next = NULL;
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
    head = head -> next;
    ListNode *newHead = deleteDuplicates(head);
    while (newHead != NULL) {
        cout << newHead -> val << ' ';
        newHead = newHead -> next;
    }
    cout << '\n';
    return 0;
}