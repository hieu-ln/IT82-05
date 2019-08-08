#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
#define COUNT 12
struct Node
{
	int info;
	Node* right, * left;
};
Node* root;
void init()
{
	root = NULL;
}
Node* CreateNode(int x)
{
	Node* p = new Node();
	p->info= x;
	p->left = p->right = NULL;
	return p;
}
Node* FindInsert(Node *p, int x)
{
	Node* f = p;
	while (p != NULL)
	{
		f = p;
		if (p->info == x)
			return NULL;
		else
			if (p->info > x)
				p = p->left;
			else
				p = p->right;
	}
	return f;
}
Node* Search(Node* p, int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (p->info > x)
				p = p->left;
			else
				p = p->right;
	}
	return NULL;
}
void InsertNode(Node*& p, int x)
{
	Node* n = CreateNode(x);
	if (p == NULL)
		p = n;
	else
	{
		Node* f = FindInsert(p, x);
		if (f != NULL)
		{
			if (f->info > x)
				f->left = n;
			else
				f->right = n;
		}
	}
}
void NLR(Node* root)
{
	if (root == NULL)
		return;
	Tao stack rong va them node root vao stack
	stack<Node*> stack;
	stack.push(root);
	while (!stack.empty())
	{
		Node* p = stack.top();
		Lay 1 Node ra khoi stack va In ra man hinh
		stack.pop();
		cout << p->info << " ";
		if (p->right) //Them node con ben phai vao stack
			stack.push(p->right);
		if (p->left) //Them node con ben trai vao stack
			stack.push(p->left);
	}
}
void print2DUtil(Node* p, int space)
{
	if (p == NULL) //base case
		return;
	space += COUNT; //Increase distance between levels
	Process right child
	print2DUtil(p->right, space);
	Print current node after space
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	Process left child
	print2DUtil(p->left, space);
}
void Process_Tree()
{
	print2DUtil(root, 0);
}
int main()
{
	int choice, x;
	Node* p;
	system("cls");
	cout << " ----------- BAI TAP 1, CHUONG 4, CAY NPTK ----------- " << endl;
	cout << "1. Khoi tao CAY NPTK rong" << endl;
	cout << "2. Them mot phan tu vao CAY NPTK\n";
	cout << "3. Tim mot phan tu trong CAY NPTK\n";
	cout << "4. Xoa mot phan tu trong CAY NPTK\n";
	cout << "5. Duyet CAY NPTK theo NLR\n";
	cout << "6. Duyet CAY NPTK theo LNR\n";
	cout << "7. Duyet CAY NPTK theo LRN\n";
	cout << "8. Xuat CAY NPTK\n";
	cout << "9. Thoat\n";
	do
	{
		cout << "Vui Long nhap so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong CAY NPTK\n";
			break;
		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			InsertNode(root, x);
			cout << "CAY NPTK sau khi them x = " << x << " la:\n";
			Process_Tree();
			cout << endl;
			break;
		case 3:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			p = Search(root, x);
			if (p == NULL)
				cout << "Khong tim thay phan tu x = " << x << endl;
			else
				cout << "Tim thay phan tu x = " << x << endl;
			break;
		case 5:
			cout << "Ket qua duyet NLR: " << endl;
			NLR(root);
			break;
		case 8:
			cout << "CAY NPTK hien tai:\n";
			Process_Tree();
			cout << endl;
			break;
		case 9:
			cout << "GOODBYE......!!!!!\n";
			break;
		default:
			break;
		}
	} while (choice != 9);
	system("pause");
	return 0;
}