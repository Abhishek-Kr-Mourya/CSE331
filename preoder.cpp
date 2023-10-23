
#include <bits/stdc++.h>
using namespace std;

struct Node {
	char key;
	vector<Node*> child;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	return temp;
}

void traverse_tree(struct Node* root)
{
	stack<Node*> nodes;
	nodes.push(root);
	while (!nodes.empty()) {
		Node* curr = nodes.top();
		nodes.pop();
	if(curr != NULL)
	{
		cout << curr->key << " ";
		vector<Node*>::iterator it = curr->child.end();

		while (it != curr->child.begin()) {
			it--;
			nodes.push(*it);
		}
	}
	}
}
int main()
{


	Node* root = newNode('A');
	(root->child).push_back(newNode('B'));
	(root->child).push_back(newNode('F'));
	(root->child).push_back(newNode('D'));
	(root->child).push_back(newNode('E'));
	(root->child[0]->child).push_back(newNode('K'));
	(root->child[0]->child).push_back(newNode('J'));
	(root->child[2]->child).push_back(newNode('G'));
	(root->child[3]->child).push_back(newNode('C'));
	(root->child[3]->child).push_back(newNode('H'));
	(root->child[3]->child).push_back(newNode('I'));
	(root->child[0]->child[0]->child).push_back(newNode('N'));
	(root->child[0]->child[0]->child).push_back(newNode('M'));
	(root->child[3]->child[0]->child).push_back(newNode('O'));
	(root->child[3]->child[2]->child).push_back(newNode('L'));

	traverse_tree(root);

	return 0;
}
