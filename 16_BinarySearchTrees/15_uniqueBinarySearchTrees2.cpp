// https://leetcode.com/problems/unique-binary-search-trees-ii
// explanation - https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/929000/Recursive-solution-long-explanation

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> helper(int start, int end) {
    if (start > end) {
        return {NULL};
    }
    vector<TreeNode*> res;
    for (int i = start; i <= end; i++) {
        vector<TreeNode*> left = helper(start, i - 1);
        vector<TreeNode*> right = helper(i + 1, end);
        for (int j = 0; j < left.size(); j++) {
            for (int k = 0; k < right.size(); k++) {
                TreeNode* curr = new TreeNode(i);
                curr -> left = left[j];
                curr -> right = right[k];
                res.push_back(curr);
            }
        }
    }
    return res;
}
vector<TreeNode*> generateTrees(int n) {
    return helper(1, n);
}

void print(TreeNode* root) {
    if (root == NULL) return;
    cout << root -> val << ' ';
    print(root -> left);
    print(root -> right);
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> res = generateTrees(n);
    for (int i = 0; i < res.size(); i++) {
        print(res[i]);
        cout << '\n';
    }
    return 0;
}