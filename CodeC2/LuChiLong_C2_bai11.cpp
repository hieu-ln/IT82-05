#include<iostream>
#include<stdio.h>
using namespace std;

//11.1
struct node
{
	int info;
	node *link;
};

node *f , *r;
//11.2
void init()
{
	f=NULL;
	r=NULL;
}

//11.3
int Empty()
{
	if(f==NULL)
		return 1;
	return 0;
}

//11.4
void push(int x)
{
	node *p = new node;
	p->info =x;
	p->link =NULL;
	if(r == NULL)
		f=p;
	else
		r->link=p;
	r=p;
}

//11.5
int pop(int &x)
{
	if(f != NULL)
	{
		node *p =f;
		f =p->link;
		x =p->info;
		if(f == NULL)
		{
			r = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

void process_queue()
{
	if(f!=NULL)
	{
		node *p = f;
		cout<<"<==  ";
		do
		{
			cout<<p->info<<"  ";
			p =p->link;
		}while(p!=NULL);
		cout<<"<=== "<<endl;
	}
	else
		cout<<"<==   <==="<<endl;
}

int main()
{
	int choice ,x ,i;
	system("cls");
	cout<<"-------- BAI TAP 11 , CHUONG 2 , QUEUE(HANG DOI - DSLK) --------"<<endl;
	cout<<"1. khoi tao QUEUE rong!"<<endl;
	cout<<"2. them phan tu vao QUEUE: "<<endl;
	cout<<"3. lay phan tu ra khoi QUEUE: "<<endl;
	cout<<"4. kiem tra QUEUE co Empty khong!"<<endl;
	cout<<"5. Xuat QUEUE hien gio:"<<endl;
	cout<<"6. QUIT!!"<<endl;
	do
	{
		cout<<"Xin chon so thuc hien =";cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"Da khoi tao thanh cong!"<<endl;
			break;
		case 2:
			cout<<"Nhap gia tri x=";cin>>x;
			push(x);
			cout<<"kq QUEUE sau khi them: ";
			process_queue();
			break;
		case 3:
			pop(x);
			cout<<"kq QUEUE da lay ra "<<x<<" QUEUE con lai"<<endl;
			process_queue();
			break;
		case 4:
			i = Empty();
			if(i != 0)
				cout<<"QUEUE Empty!!"<<endl;
			else
				cout<<"QUEUE con phan tu!"<<endl;
			break;
		case 5:
			cout<<"QUEUE hien tai!"<<endl;
			process_queue();
			break;
		case 6:
			cout<<"**hen gap lai**"<<endl;
		default:
			break;
		}
	}while(choice!=6);
	system("pause");
	return 0;
}