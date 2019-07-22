#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 100
// 5.2
void init(int a[],int &space)
{
	space=-1;
}
// 5.3
int SEmpty(int a[],int space)
{
	if(space == -1)
		return 1;
	return 0;
}
// 5.4
int SFull(int a[],int space)
{
	if(space == MAX -1)
		return 1;
	return 0;
}
// 5.5
int Push(int a[],int &space,int x)
{
	if(space < MAX - 1)
	{
		a[++space] = x;
		return 1;
	}
	return 0;
}
int Pop(int a[],int &space,int &x)
{
	if(space != -1)
	{
		x = a[space--];
		return 1;
	}
	return 0;
}
//xuat stack
void Pro_stack(int a[],int space)
{
	for(int i=0;i<space+1;i++)
		cout<<a[i]<<endl;
	cout<<endl;
}
int main()
{
	int a[MAX];
	int choice, space, x, i;
	system("cls");
	cout<<"-------BAI TAP 5 , CHUONG 1, stack (ngan xep - ds dac)-------"<<endl;
	cout<<"1. Khoi tao STACK rong"<<endl;
	cout<<"2. Them phan tu vao STACK"<<endl;
	cout<<"3. Lay phan tu ra thoi STACK"<<endl;
	cout<<"4. Kiem tra STACK co rong hay khong"<<endl;
	cout<<"5. Kiem tra STACK co day hay khong"<<endl;
	cout<<"6. xuat STACK"<<endl;
	cout<<"7. Thoat"<<endl;
	do
	{
		cout<<"vui long chon so thuc hien: ";cin>>choice;
		switch(choice)
		{
			case 1:
				init (a, space);
				cout<<" ban vua khoi toan STACK thanh cong"<<endl;
				break;
			case 2: 
				cout<<"nhap gia tri x=";
				cin>>x;
				i= Push(a,space,x);
				break;
			case 3:
				i=Pop(a,space,x);
				cout<<"Phan tu lay ra tu STACK la x="<<x<<endl;
				Pro_stack(a,space);
				break;
			case 4:
				i =SEmpty(a,space);
				if(i == 0)
					cout<<"stack khong rong"<<x<<endl;
				else
					cout<<"stack rong"<<endl;
				break;
			case 5:
				i= SFull(a,space);
				if(i == 0)
					cout<<"stack chua day"<<x<<endl;
				else
					cout<<"stack da day"<<endl;
				break;
			case 6:
				cout<<"STACK hien tai la: ";
				Pro_stack(a,space);
				break;
			case 7:
				cout<<" BYE "<<endl;
				break;
			default:
				break;
		}
	}while(choice!=7);
	system("pause");
	return 0;
}