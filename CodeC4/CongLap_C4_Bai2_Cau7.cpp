#include <iostream>
#include <stdio.h>
using namespace std;

#define COUNT 10;
// Khai bao cau truc cay nhi phan tim kiem
struct Node
{
	int info;
	Node *left;
	Node * right;
};
Node *root;
//Khoi tao cay rong
void tree_empty()
{
	root=NULL;
}
// Them 1 phan tu vao cay
void insertNode(Node *&p, int x)
{
	if(p==NULL)
	{
		p =new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info==x)
			return;
		else if(p->info>x)
			return insertNode(p->left,x);
		else
			return insertNode(p->right,x);
	}
}
struct stack
{
	int info;
	stack *next;
};
stack *sp;
//Khoi tao stack rong
void init_Stack()
{
	sp = NULL;
}
//Them phan tu vao stack
void Push(int x)
{
	stack *p = new stack;
	p->info = x;
	p->next = sp;
	sp = p;
}
//Lay 1 phan tu ra khoi stack
int Pop(int &x)
{
	if (sp != NULL)
	{
		stack *p = sp;
		x = p->info;
		sp = p->next;
		delete p;
		return 1;
	}
	return 0;
}
void Process_LNR(Node *p)
{
	if (p != NULL)
	{
		Process_LNR(p->right);
		Push(p->info);
		Process_LNR(p->left);
	}
}
void process_Bin_Tree(Node *p, int space)
{
	if (p == NULL)
		return;

	space = space + COUNT;

	process_Bin_Tree(p->right, space);	
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	process_Bin_Tree(p->left, space);
}
void process_Tree()
{
	process_Bin_Tree(root,0);
}
int main()
{
	int choice, result, x;

	cout << "---------- CHUONG 4 - BAI 2.7: CAY NHI PHAN TIM KIEM ----------" << endl;
	cout << "1. Khoi tao Cay nhi phan rong" << endl;
	cout << "2. Khoi tao Stack rong" << endl;
	cout << "3. Them phan tu vao Cay nhi phan tim kiem" << endl;
	cout << "4. Duyet Cay nhi phan tim kiem" << endl;
	cout << "5. Duyet Cay nhi phan tim kiem theo LNR (su dung Stack)" << endl;
	cout << "6. Thoat" << endl;
	
	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			tree_empty();
			cout << "Khoi tao Cay nhi phan rong thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			init_Stack();
			cout << "Khoi tao Stack rong thanh cong!" << endl;
			cout << endl;
			break;
		case 3:
			cout << "Nhap phan tu (x) muon them vao Cay nhi phan: ";
			cin >> x;
			insertNode(root,x);
			cout << "Cay nhi phan hien tai la: " << endl;
			process_Tree();
			cout << endl;
			break;
		case 4:
			cout << "Cay nhi phan hien tai la: " << endl;
			process_Tree();
			cout << endl;
			break;
		case 5:
			cout << "Cay nhi phan tim kiem duyet theo LRN la: " << endl;
			Process_LNR(root);
			while (sp != NULL)
			{
				Pop(x);
				cout << x << "\t";
			}
			cout << endl << endl;
			break;
		case 6:
			cout << "Goodbye...!" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}