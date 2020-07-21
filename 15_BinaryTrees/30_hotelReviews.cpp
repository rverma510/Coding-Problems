class Tree {
  public:
    int index;
    int k;
    Tree *left;
    Tree *right;
    
    Tree(int i, int k): index(i), k(k), left(NULL), right(NULL) {}
};

Tree* insert(Tree *root, int i, int k) {
    if (root == NULL) {
        root = new Tree(i, k);
    }
    else if(root->k < k) {
        root->left = insert(root->left, i, k);
    }
    else {
        root->right = insert(root->right, i, k);
    }
    return root;
}

void inOrder(Tree *root, vector<int> &res) {
    if (root == NULL)
        return;
    inOrder(root->left, res);
    res.push_back(root->index);
    inOrder(root->right, res);
}

vector<int> Solution::solve(string A, vector<string> &B) {
    unordered_set<string> s;
    string str = "";
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != '_') {
            str = str + A[i];
        }
        else {
            s.insert(str);
            str = "";
        }
    }
    s.insert(str);
    Tree *root = NULL;
    for(int i = 0; i < B.size(); i++) {
        int  k = 0;
        str = "";
        for (int j = 0; j < B[i].size(); j++) {
            if (B[i][j] != '_') {
                str += B[i][j];
            }
            else {
                if (s.find(str) != s.end())
                    k++;
                str = "";
            }
        }
        if (s.find(str) != s.end())
            k++;
        root = insert(root, i, k);
    }
    vector<int> res;
    inOrder(root, res);
    return res;
}
