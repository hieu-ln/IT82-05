#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 100

void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}

int isEmpty(int a[], int &front, int &rear)
{
	if(front == rear)
		return 1;
	else
		return 0;
}

int isfull(int a[], int &front, int &rear)
{
	if((front == 0 && rear == MAX - 1) || (front -rear == 1))
		return 1;
	else
		return 0;
}

int push(int a[],int &front, int &rear, int x)
{
	if(rear - front == MAX - 1)
		return 0;
	else
	{
		if(front == -1)
			front = 0;
		if(rear == MAX - 1)
		{
			for(int i = front;i<=rear;i++)
			{
				a[i-front] = a[i];
			}
			rear = MAX -1 -front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
	return 0;
}

int pop(int a[],int &front, int &rear, int &x)
{
	if(front == -1)
		return 0;
	else
	{
		x = a[front++];
		if(front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}

void process_queue(int a[], int f, int r)
{
	cout<<"f="<<f<<endl;
	cout<<"r="<<r<<endl;
	if(f<=r && f!=-1)
	{
		cout<<"<---  ";
		for(int i=f; i<r+1; i++)
		{
			cout<<a[i]<<"   ";
		}
		cout<<"<---"<<endl;
	}
}

int main()
{
	int a[MAX];
	int choice, f, r, x, i;
	system("cls");
	cout<<" --------- BAT TAP 7 , CHUONG 1 , QUEUE (HANG DOI) --------- "<<endl;
	cout<<"1. khoi tao QUEUE rong !"<<endl;
	cout<<"2. them phan tu vao QUEUE: "<<endl;
	cout<<"3. lay phan tu ra khoi QUEUE: "<<endl;
	cout<<"4. kiem tra QUEUE co rong hay khong "<<endl;
	cout<<"5. kiem tra QUEUE co day hay khong"<<endl;
	cout<<"6. Xuat QUEUE"<<endl;
	cout<<"7. Thoat"<<endl;
	do
	{
		cout<<"\n Chon so thuc hien: ";cin>>choice;
		switch(choice)
		{
		case 1:
			init(a,f,r);
			cout<<"QUEUE da khoi tao thanh cong!"<<endl;
			break;
		case 2:
			cout<<"nhap gia tri x=";cin>>x;
			i=push(a,f,r,x);
			cout<<"QUEUE sau khi them la!";
			process_queue(a,f,r);
			break;
		case 3:
			i=pop(a,f,r,x);
			cout<<"phan tu lay ra tu QUEUE x="<<x<<endl;
			cout<<"QUEUE sau khi lay ra la!";
			process_queue(a,f,r);
			break;
		case 4:
			i=isfull(a,f,r);
			if(i == 0)
				cout<<"QUEUE chua day!"<<endl;
			else
				cout<<"QUEUE dang day!"<<endl;
			break;
		case 5:
			i=isEmpty(a,f,r);
			if(i == 0)
				cout<<"QUEUE khong rong!"<<endl;
			else
				cout<<"QUEUE dang rong!"<<endl;
			break;
		case 6:
			cout<<"QUEUE hien gio!";
			process_queue(a,f,r);
			break;
		case 7:
			cout<<"GOODBYE"<<endl;
			break;
		default:
			break;
		}
	}while(choice != 7);
	system("pause");
	return 0;
}