#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void insert(Node **root, int newData){
	if (*root == nullptr){
		Node *newNode;
		newNode = new Node;

		newNode -> data = newData;
		newNode -> left = nullptr;
		newNode -> right = nullptr;

		*root = newNode;

		cout << "Data has been added\n";
	}
	else if (newData < (*root) -> data){
		insert(&((*root)->left), newData);
	}
	else if (newData > (*root) -> data){
		insert(&((*root)->right), newData);
	}
	else if (newData == (*root) -> data){
		cout << "Data is already exist\n";
	}
}

void preOrder(Node *root){
	if (root != nullptr){
		cout <<root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
	}
}

void inOrder(Node *root){
	if (root != nullptr){
		inOrder(root->left);
		cout<<root->data << " ";
		inOrder(root->right);
	}
}

void postOrder(Node *root){
	if (root != nullptr){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data << " ";
	}
}

void printTree(Node* root, int space = 0, int height = 5){
	if (root != nullptr) {
		space+= height;
		printTree(root->right, space);
		cout << endl;
    	for (int i = height; i < space; i++) cout << " ";
    	cout << root->data << "\n";
		printTree(root->left, space);
	}
};

void freeTree(Node* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main(){
    int opt, val;
    Node *tree;
    tree = NULL; 

    do {
    	system("cls");

	printTree(tree);
	cout<<endl;
	cout << "1. Insert\n";
	cout << "2. PreOrder\n";
	cout << "3. InOrder\n";
	cout << "4. PostOrder\n";
	cout << "5. Exit\n";
	
	cout << "\nOption: "; cin >> opt;

	switch (opt) {

		case 1:
			cout << "\n Input:";
			cout << "\n ------";
			cout << "\n New data: ";
			cin >> val;
			insert(&tree, val);
			break;

		case 2:
			cout << "PreOrder Traversal\n";
			cout << "==========================\n";
			if (tree == NULL) {
				cout << "Tree is empty!\n";
			}
			else {
				preOrder(tree);
			}
			break;

		case 3:
			cout << "InOrder Traversal\n";
			cout << "==========================\n";
			if (tree == NULL) {
				cout << "Tree is empty!\n";
			}
			else {
				inOrder(tree);
			}
			break;

		case 4:
			cout << "PostOrder Traversal\n";
			cout << "==========================\n";
			if (tree == NULL) {
				cout << "Tree is empty!\n";
			}
			else {
				postOrder(tree);
			}
			break;

		case 5:
			cout << "\nTERIMA KASIH\n";
            cout << "Program was made by Hamka Arifani (2410817110006)" << endl;
			break;
			
		default:
			cout << "Option is not valid! Please re-enter your option";
			break;
	}
	
	getch();
    } while(opt != 5);
	freeTree(tree);
    return 0;
}
