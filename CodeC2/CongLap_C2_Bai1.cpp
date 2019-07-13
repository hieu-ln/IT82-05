#include <stdio.h>
#include <iostream>
using namespace std;
//1.1
#define MAX 100
int a[MAX];
int n;
//1.2
void input(int a[],int &n)
{
	cout<<"Nhap vao so phan tu cua danh sach: ";
	cin>>n;
	cout<<"Nhap cac phan tu cua danh sach\n";
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"] = ";
		cin>>a[i];
	}
}
//1.3
void output(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
}
//1.4
int searchX(int a[],int &n,int x)
{
	int i=0;
	while((i<n)&&(a[i]!=x))
		i++;
	if(i==n)
		return -1;
	return i;
}
//1.5
int insert_Last(int a[],int &n,int x)
{
	if(n<MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	return 0;
}
//1.6
int delete_last(int a[], int &n)
{
	if(n>0)
	{
		n--;
		return 1;
	}
	return 0;
}
//1.7
int Delete(int a[], int &n, int i)
{
	if(i>=0&&i<n)
	{
		for(int j=i;j<n-1;j++)
			a[j]=a[j+1];
		n--;
		return 1;
	}
	return 0;
}
//1.8
int search_And_Delete(int a[],int &n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			Delete(a,n,i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout<<"------------------ BAI TAP 1, CHUONG 2, DANH SACH DAC ------------------"<<endl;
	cout<<"1.Nhap danh sach"<<endl;
	cout<<"2.Xuat danh sach"<<endl;
	cout<<"3.Tim phan tu co gia tri x trong danh sach"<<endl;
	cout<<"4.Them phan tu vao cuoi danh sach"<<endl;
	cout<<"5.Xoa phan tu cuoi danh sach"<<endl;
	cout<<"6.Xoa phan tu tai vi tri i"<<endl;
	cout<<"7.Tim phan tu co gia tri x va xoa no neu co"<<endl;
	cout<<"8.Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				input(a,n);
				cout<<"Nhap danh sach thanh cong\n";
				break;
			case 2:
				cout<<"Danh sach da nhap la:\n";
				output(a,n);
				break;
			case 3:
				cout<<"Nhap phan tu x can tim: ";
				cin>>x;
				cout<<"phan tu X nam o vi tri: "<<searchX(a,n,x);
				break;
			case 4:
				cout<<"Nhap vao phan tu can them: ";
				cin>>x;
				insert_Last(a,n,x);
				output(a,n);
				break;
			case 5:
				delete_last(a,n);
				output(a,n);
				break;
			case 6:
				cout<<"Nhap vi tri i can xoa: ";
				cin>>i;
				Delete(a,n,i);
				output(a,n);
				break;
			case 7:
				cout<<"Nhap vao phan tu x: ";
				cin>>x;
				search_And_Delete(a,n,x);
				output(a,n);
				break;
			case 8:
				cout<<"\nGoodbye!";
				break;
			default:
				break;
			

		}
	}while(choice!=8);
	system("pause");
	return 0;
}








