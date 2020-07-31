// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
	
	Node(char x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void preorder(Node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Node *convertExpression(string str,int i);
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		Node *root=convertExpression(str,0);
		preorder(root);
		cout<<endl;
	}
}// } Driver Code Ends


/*Complete the function below
Node is as follows
struct Node{
	char data;
	Node *left,*right;
};
*/
int idx;
Node *convertExpression(string str,int i)
{
    if (i == 0) {
        idx = 0;
        i++;
    }
    Node *root = new Node(str[idx]);
    if (idx == str.size() - 1)
        return root;
    if (str[idx+1] == '?') {
        idx += 2;
        root->left = convertExpression(str, i);
        root->right = convertExpression(str, i);
    }
    else{
        idx += 2;
    }
    return root;
}

