#include<iostream>
#include<stdio.h>
using namespace std;

//10.1
struct node
{
	int info;
	node *link;
};

node *sp;
//10.2
void init()
{
	sp=NULL;
}

//10.3
int isempty()
{
	if(sp == NULL)
		return 1;
	return 0;
}

//10.4
void push(int x)
{
	node *p = new node;
	p->info =x;
	p->link =sp;
	sp =p;
}

//10.5
int pop(int &x)
{
	if (sp!=NULL)
	{
		node *p =sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

//output stack
void process_stack()
{
	node *p = sp;
	do
	{
		cout<<p->info<<"   ";
		p=p->link;
	}while(p!=NULL);
	cout<<endl;
}

int main()
{
	int choice,x,i;
	system("cls");
	cout<<" ------- BAI TAP 10 , CHUONG 2 , STACK (NGAN XEP - DSLK) ------- "<<endl;
	cout<<"1. khoi tao STACK rong!"<<endl;
	cout<<"2. them phan tu vao STACK "<<endl;
	cout<<"3. lay phan tu ra khoi STACK "<<endl;
	cout<<"4. xuat STACK!"<<endl;
	cout<<"5. Thoat"<<endl;
	do
	{
		cout<<"\nnhap so de thuc hien: ";cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"STACK da khoi tao thanh cong!"<<endl;
			break;
		case 2:
			cout<<"nhap gia tri x=";cin>>x;
			push(x);
			cout<<"STACK sau khi them!";
			process_stack();
			break;
		case 3:
			pop(x);
			cout<<"phan tu lay ra tu STACK x="<<x<<endl;
			cout<<"STACK sau khi lay ra: ";
			process_stack();
			break;
		case 4:
			cout<<"STACK hien gio la!";
			process_stack();
			break;
		case 5:
			cout<<"GOODBYE"<<endl;
			break;
		default:
			break;
		}
	}while(choice!=5);
	system("pause");
	return 0;
}