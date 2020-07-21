/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* createTreefromTraversal(vector<int> &a, vector<int> &b,int s,int e,int &i){
    if(s>e)
        return NULL;
    TreeNode* root = new TreeNode(a[i]);
    int index=-1;
    for(int j=s;s<=e;j++){
        if(b[j]==a[i]){
            index=j;
            break;
        }
    }
    i++;
    root->left = createTreefromTraversal(a,b,s,index-1,i);
    root->right = createTreefromTraversal(a,b,index+1,e,i);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int s=0;
    int e=A.size()-1;
    int i=0;
    TreeNode * root = createTreefromTraversal(A,B,s,e,i);
    return root;
}
