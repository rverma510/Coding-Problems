#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution 1
typedef pair<int, ListNode*> pr;
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = nullptr, *tmp = nullptr;
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push({lists[i]->val, lists[i]});
        }
        while(!pq.empty()) {
            pr t = pq.top(); pq.pop();
            if (t.second->next) {
                pq.push({(t.second)->next->val, (t.second)->next});
            }
            if (!res) {
                res = t.second;
                tmp = res;
            }
            else {
                tmp->next = t.second;
                tmp = t.second;
            }
        }
        return res;
    }
};


// Solution 2
typedef pair<int, int> pii;
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = new ListNode(INT_MIN);
        ListNode *tmp = res;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, i});
            }
        }
        while(!pq.empty()) {
            pii t = pq.top(); pq.pop();
            tmp->next = lists[t.second];
            tmp = tmp->next;
            lists[t.second] = lists[t.second]->next;
            if (lists[t.second]) {
                pq.push({lists[t.second]->val, t.second});
            }
        }
        return res->next;
    }
};

int main() {
    // code for creating lists and calling merge on them.
    return 0;
}