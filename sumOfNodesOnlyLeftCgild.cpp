#include<bits/stdc++.h>
using namespace std;

struct treenode{
    int val;
    treenode* left;
    treenode* right;

    treenode(int n){
        val=n;
        left=nullptr;
        right=nullptr;
    }
};

int sumOfLeftNodes(treenode* root){
    if(root==nullptr){
        return 0;
    }

    int sum=0;

    if(root->left!=nullptr && root->right==nullptr){
        cout<<root->val<<" ";
        sum=sum+root->val;
    }

    sum=sum+sumOfLeftNodes(root->left);
    sum=sum+sumOfLeftNodes(root->right);

    return sum;
}

int main(){
    treenode* root=new treenode(100);
    root->left=new treenode(70);
    root->right=new treenode(110);
    root->left->left=new treenode(65);
    root->left->left->left=new treenode(60);
    root->left->right=new treenode(90);
    root->left->right->left=new treenode(85);
    root->left->right->left->left=new treenode(80);
    root->left->right->right=new treenode(95);
    root->right->left=new treenode(105);

    cout<<"nodes having only left child:";
    int result=sumOfLeftNodes(root);
    cout<<endl;
    cout<<"sum of all nodes having only left child:";
    cout<<result;

    return 0;

}