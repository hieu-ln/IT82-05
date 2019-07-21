//Bai tap 1 - Chuong 4
#include <iostream>
#include <stdio.h>
using namespace std;
#define COUNT 10
//Cau 1.1 Khai bao cau truc cay nhi phan tim kiem
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
//Cau 1.2 Khoi tao cay rong
void Init()
{
	root = NULL;
}
//Cau 1.3 Them 1 phan tu vao cay
void InsertNode(Node *&p, int x)
{
	if(p==NULL)
	{
		p=new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info==x)
			return;
		else if(p->info >x)
			return InsertNode(p->left, x);
		else
			return InsertNode(p->right, x);
	}
}
//int Insert_Node_Recursive(int x, Node *q)
//{
//	if(q->info == x)
//		return 0;
//	else if(q->info > x)
//	{
//		if(q->left==NULL)
//		{
//			Node *p = new Node;
//			p->info = x;
//			p->left = NULL;
//			p->right = NULL;
//			q->left = p;
//			return 1;
//		}
//		else
//			return Insert_Node_Recursive(x, q->right);
//	}
//	else
//	{
//		if(q->right == NULL)
//		{
//			Node *p = new Node;
//			p->info = x;
//			p->left = NULL;
//			p->right = NULL;
//			q->right = p;
//			return 1;
//		}
//	}
//}
//Cau 1.4 Tim 1 phan tu trong cay
Node *search(Node *p, int x)
{
	if(p!= NULL)
	{
		if(p->info==x)
			return p;
		else
			if(x>p->info)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;
}
//Cau 1.5 Xoa 1 nut trong cay
void searchStandFor(Node *&p, Node*&q)
{
	if(p->left == NULL)
	{
		p->info = q->info;
		p=q;
		q=q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Delete(Node *&T, int x)
{
	if(T==NULL)
		return 0;
	if(T->info==x)
	{
		Node *p = T;
		if(T->left == NULL)
			T=T->right;
		else if(T->right==NULL)
			T=T->left;
		else
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info<x)
		return Delete(T->right, x);
	if(T->info>x)
		return Delete(T->left, x);
}
//Cau 1.6 Duyet cay theo thu tu NLR
void duyetNLR(Node *p)
{
	if(p!=NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//Cau 1.7 Duyet cay theo thu tu LNR
void duyetLNR(Node *p)
{
	if(p!=NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}
//Cau 1.8 Duyet cay theo thu tu LRN
void duyetLRN(Node *p)
{
	if(p!=NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}
}
//XUAT
void print2DUtil(Node *p, int space)
{
	if(p==NULL)
		return;
	space += COUNT;
	print2DUtil(p->right, space);
	cout << endl;
	for(int i = COUNT; i<space; i++)
		cout << " ";
	cout << p->info << "\n";
	print2DUtil(p->left, space);
}
void Process_Tree()
{
	print2DUtil(root, 0);
}
int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "----------BAI TAP 1 - CHUONG 4 - CAY NPTK----------\n";
	cout << "1. Khoi tao CAY NPTK rong\n";
	cout << "2. Them phan tu vao CAY NPTK\n";
	cout << "3. Tim phan tu co gia tri x trong CAY NPTK\n";
	cout << "4. Xoa phan tu co gia tri x trong CAY NPTK\n";
	cout << "5. Duyet CAY NPTK theo thu tu NLR\n";
	cout << "6. Duyet CAY NPTK theo thu tu LNR\n";
	cout << "7. Duyet CAY NPTK theo thu tu LRN\n";
	cout << "8. Xuat CAY NPTK\n";
	cout << "9. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao CAY NPTK thanh cong!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x can them : ";
			cin >> x;
			InsertNode(root, x);
			cout << "CAY NPTK sau khi da them la: ";
			Process_Tree();
			break;
		case 3:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			p = search(root, x);
			if(p!=NULL)
				cout << "Tim thay x = " << x << " trong CAY NPTK\n";
			break;
		case 4:
			cout << "Vui long nhap gia tri x can xoa: ";
			cin >> x;
			i = Delete(root, x);
			if(i == 0)
				cout << "Khong tim thay x = " << x << " de xoa!\n";
			else
			{
				cout << "Da xoa thanh cong phan tu x = " << x << " trong CAY NPTK!\n";
				cout << "CAY NPTK sau khi da xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout << "CAY NPTK duyet theo NLR la: ";
			duyetNLR(root);
			break;
		case 6:
			cout << "CAY NPTK duyet theo LNR la: ";
			duyetLNR(root);
			break;
		case 7:
			cout << "CAY NPTK duyet theo LRN la: ";
			duyetLRN(root);
			break;
		case 8:
			cout << "CAY NPTK nhu sau: ";
			Process_Tree();
			break;
		case 9:
			cout << "Good bye!!\n";
			break;
		default:
			break;
		}
	}while(choice != 9);
	system("pause");
	return 0;
}