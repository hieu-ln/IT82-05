#include <iostream>
#include <stdio.h>
using namespace std;

const int COUNT = 10;

struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

void tree_empty()
{
	root=NULL;
}

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
struct queue
{
	int info;
	queue *next;
};
queue *front, *rear;

void init_queue()
{
	front=NULL;
	rear=NULL;
}

void Push(int x)
{
	queue *p;
	p = new queue;
	p->info = x;
	p->next = NULL;
	if(rear==NULL)
		front=p;
	else
		rear->next=p;
	rear = p;
}

int Pop(int &x)
{
	if (front != NULL)
	{
		queue *p = front;
		x = p->info;
		front = front->next;
		if(front==NULL)
			rear=NULL;
		delete p;
		return 1;
	}
	return 0;
}
void sort_LRN(Node *p)
{
	if (p != NULL)
	{
		Process_LRN(p->left);
		Process_LRN(p->right);
		Push(p->info);
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
	Node *p;

	cout << "---------- CHUONG 4 - BAI 2.8: CAY NHI PHAN TIM KIEM ----------" << endl;
	cout << "1. Khoi tao Cay nhi phan rong" << endl;
	cout << "2. Khoi tao Stack rong" << endl;
	cout << "3. Them phan tu vao Cay nhi phan tim kiem" << endl;
	cout << "4. Duyet cay nhi phan tim kiem: " << endl;
	cout << "5. Duyet Cay nhi phan tim kiem theo LRN (su dung Queue)" << endl;
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
				init_queue();
				cout << "Khoi tao Queue rong thanh cong!" << endl;
				cout << endl;
				break;
			case 3:
				cout << "Nhap phan tu x muon them vao Cay nhi phan x=";
				cin >> x;
				insertNode(root, x);
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
				sort_LRN(root);
					while (front != NULL)
					{
					Pop(x);
					cout << x << "\t";
				}
				cout << endl << endl;
				break;
			case 6:
				cout << "GOODBYE!"<<endl;
				break;
			default:
				break;
		}
	}while(choice!=6);
	system("pause");
	return 0;
}