#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;

    stack<TreeNode*> nodeStack;
    stack<int> resultStack;

    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode* currentNode = nodeStack.top();
        nodeStack.pop();

        resultStack.push(currentNode->val);

        if (currentNode->left)
            nodeStack.push(currentNode->left);
        if (currentNode->right)
            nodeStack.push(currentNode->right);
    }

    while (!resultStack.empty()) {
        cout << resultStack.top() << " ";
        resultStack.pop();
        
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Postorder traversal: ";
    postorderTraversal(root);

    return 0;
}
