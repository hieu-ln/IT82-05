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
Node* CreateNode(int x)
{
    Node* p = new Node();
    p->info = x;
    p->left = p->right = NULL;
    return p;
}
//Kiểm tra vị trí cần thêm
Node* FindInsert(Node* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node* p = root;
    Node* f = p;
    while (p != NULL)
    {
        f = p;
        if (p->info > x)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }        
    return f;
}
//Thêm phần tử vào cây
void InsertNode(Node* &root, int x)
{
    Node* n = CreateNode(x);
    if (root == NULL)
    {
        root = n;
        return;
    }
    else
    {
        Node* f = FindInsert(root, x);
        if (f != NULL)
        {
            if (f->info > x)
            {
                f->left = n;
            }
            else
            {
                f->right = n;
            }
        }
    }
//
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
}
//Hàm main
int main()
{
	int choice,x;

	cout << "---------- CHUONG 4 - BAI 2.3: CAY NHI PHAN TIM KIEM ----------" << endl;
	cout << "1. Khoi tao Cay nhi phan rong" << endl;
	cout << "2. Them phan tu vao Cay nhi phan tim kiem" << endl;
	cout << "3. Thoat" << endl;
	
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
			cout << "Nhap phan tu (x) muon them vao Cay nhi phan: ";
			cin >> x;
			InsertNode(root,x);
			cout << "Cay nhi phan hien tai la: " << endl;
			process_Tree();
			cout << endl;
			break;
		case 3:
			cout << "Goodbye...!" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 3);
	system("pause");
	return 0;
}
