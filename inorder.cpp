#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    stack<TreeNode* > nodeStack;
    TreeNode* currentnode=root;
    while(currentnode!=NULL || !nodeStack.empty()){
        while(currentnode!=NULL){
        nodeStack.push(currentnode);
        currentnode=currentnode->left;
        }
    
    currentnode=nodeStack.top();
    nodeStack.pop();
    
    cout<<currentnode->val<<" ";

    currentnode=currentnode->right;
    }

}

int main(){
    
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(7);

    inorder(root);


    return 0;
}