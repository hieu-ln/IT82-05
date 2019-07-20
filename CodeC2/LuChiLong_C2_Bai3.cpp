#include<iostream>
#include<stdio.h>
using namespace std;
//3.1
struct node
{
	int info;
	node *link;
};
node *first;
//3.2
void Init()
{
	first = NULL;
}
//3.3
void process_list()
{
	node *p;
	p = first;
	while(p!=NULL)
	{
		cout<<p->info<<endl;
		p=p->link;
	}
}
//3.4
node *search(int x)
{
	node *p=first;
	while((p!=NULL)&&(p->info!=x))
	{
		p=p->link;
	}
	return p;
}
//3.5
void insertfirst(int x)
{
	node *p;
	p = new node;
	p->info =x;
	p->link = first;
	first = p;
}
//3.6 
int deletefirst()
{
	if(first!=NULL)
	{
		node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
//3.7
void insertlast(int x)
{
	node *p;
	p= new node;
	p->info = x;
	p->link = NULL;
	if(first!=NULL)
		first = p;
}
//3.8
int deletelast()
{
	if(first = NULL)
	{
		node *p,*q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q=p;
			p=p->link;
		}
		if(p != first)
		{
			q->link= NULL;
		}
		else first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//3.9
int search_delete(int x)
{
	if(first = NULL)
	{
		node *p,*q;
		p = first;
		q = first;
		while (p->info != x)
		{
			q=p;
			p=p->link;
		}
		if(p != first && p != NULL)
		{
			if(p->link != NULL)
				q->link= p->link;
			else 
				q->link = NULL;
			delete p;
			return 1;
		}
		else if(p == first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
//3.9
//3.10
int main()
{
	int choice =0;
	int x,i;
	system("cls");
	cout<<"-------BAI TAP 3, CHUONG 2, DANH SACH LIEN KET _______"<<endl;
	cout<<"1.Khoi tao dslk don rong "<<endl;
	cout<<"2.Them phan tu vao dau dslk don "<<endl;
	cout<<"3.Them phan tu vao cuoi dslk don "<<endl;
	cout<<"4.Xoa phan tu dau dslk don "<<endl;
	cout<<"5.Xoa phan ti cuoi dslk don "<<endl;
	cout<<"6.Xuat dslk don "<<endl;
	cout<<"7.Tim mot phan tu gia tri X trong dslk don "<<endl;
	cout<<"8.Tim phan tu voi gia tri X trong dslk don "<<endl;
	cout<<"9.Sap xep dslk don tang dan [chua xong] "<<endl;
	cout<<"10.Sap xe[ dslk don giam dan [chua xong] "<<endl;
	cout<<"11.Thoat"<<endl;
	do
	{
		cout<<"chon so thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			Init();
			cout<<"Khoi tao DSLK DON thanh cong"<<endl;
			break;
		case 2:
			cout<<"nhap gia tri x=";
			cin>>x;
			insertfirst(x);
			cout<<"Danh sach sau khi them la: "<<endl;
			process_list();
			break;
		case 3:
			cout<<"nhap gia tri x=";
			cin>>x;
			insertlast(x);
			cout<<"Danh sach sau khi them la: "<<endl;
			process_list();
			break;
		case 4:
			i = deletefirst();
			if(i==0)
				cout<<"danh sach rong, khong the xoa"<<x<<endl;
			else
			{
				cout<<"da xoa thanh cong phan tu dau cua DSLK DON "<<endl;
				cout<<"Danh sach sau khi xoa la:"<<endl;
				process_list();
			}
			break;
		case 5:
			i = deletelast();
			if(i==0)
				cout<<"Danh sach rong, khong the xoa"<<x<<endl;
			else
			{
				cout<<"da xoa thanh cong phan tu cuoi cua DSLK DON "<<endl;
				cout<<"Danh sach sau khi xoa la:"<<endl;
				process_list();
			}
			break;
		case 6:
			cout<<"Danh sach hien tai la:";
			process_list();
			break;
		case 7:
			cout<<"nhap gia tri can tim x=";
			cin>>x;
			if(p!=NULL)
			{
				cout<<"Tim thay phan tu co gia tri x="<<x<<endl;
			}
			else
				cout<<"khong tim thay phan tu co gia tri x="<<x<<endl;
			break;
		case 8:
			cout<<"nhap gia tri can tim x=";
			cin>>x;
			i= search_delete(x);
			if(i==1)
			{
				cout<<"tim thay x="<<x<<"va da xoa thanh cong"<<endl;
				cout<<"Danh sach sau khi xoa la:"<<endl;
				process_list();
			}
			else
				cout<<"khong tim thay phan tu co gia tri x="<<x<<endl;
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			cout<<"GOODBYE"<<endl;
			break;
		}
	}while(choice!=0);
	system("pause");
	return 0;
}