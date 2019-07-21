#include <iostream>
#include <stdio.h>
using namespace std;
//1.1 khai báo cấu trúc danh sách
#define MAX 100
int a[MAX];
int n;
//1.2 Thủ tục nhập danh sách
void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;

}
void input(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"] = ";
		cin>>a[i];
	}
}
//1.3 Thủ tục xuất danh sách
void output(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
}
//1.4 insertionsort
void insertionsort(int a[],int n)
{
	int x, i, j;
	for(int i=1;i<n;i++)
	{
		x=a[i];
		j=i-1;
		while(j >= 0 && a[j] > x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
//1.5 Selection Sort
void selectionsort(int a[],int n)
{
	int min_pos, i, j;
	for(int i=0;i<n-1;i++)
	{
		min_pos=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[min_pos])
				swap(a[min_pos],a[i]);
	}
}
//1.6 Interchange Sort
void interchangesort (int a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}
//1.7 Bubble Sort
void bubblesort (int a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=n-1;j>i;j--)
			if(a[j-1]>a[j])
				swap(a[j],a[j-1]);
}
//1.8 Quick Sort
void quicksort (int a[],int left, int right)
{
	int x=a[(left+right)/2];
	int i=left;
	int j=right;
	while(i<j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
	}
	if(left<j)
		quicksort(a,left,j);
	if(i<right)
		quicksort(a,i,right);
}
//1.9 Heap Sort
void shift(int a[], int n, int i)
{
	int lager=i;
	int l=2*i+1;
	int j=2*i+2;
	if(l<n&&a[l]>a[lager])
		lager=l;
	if(j<n&&a[j]>a[lager])
		lager=j;
	if(lager!=i)
	{
		swap(a[i],a[lager]);
		shift(a,n,lager);
	}

void heapsort(int a[],int n)
{
	for(int i=n/2;i>=0;i--)
		shift(a,n,i);
	for(int i=n-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		shift(a,i,0);
	}
}
//1.10 Tim kiem tuan tu
int search(int a[], int n, int x)
{
	int i=0;
	while(i<n&&a[i]!=x)
		i++;
	if(i<n)
		return i;
	return -1;
}
//1.11 Tim kiem nhi phan
int binarysearch (int a[],int n, int x)
{
	int left=0,right = n-1,mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==x)
			return mid;
		if(x>a[mid])
			left=mid+1;
		else
			right=mid-1;
	}
	return -1;
}
int main()
{
	int choice,x,n;
	system("cls");
	cout<<"-----------------------BAI TAP1 CHUONG 3, SAP XEP, TIM KIEM-----------------"<<endl;
	cout<<"1. Nhap danh sach"<<endl;
	cout<<"2. Xuat danh sach"<<endl;
	cout<<"3. Insertion Sort"<<endl;
	cout<<"4. Selection Sort"<<endl;
	cout<<"5. Interchange Sort"<<endl;
	cout<<"6. Bubble Sort"<<endl;
	cout<<"7. Quick Sort"<<endl;
	cout<<"8. Heap Sort"<<endl;
	cout<<"9. Search tuan tu"<<endl;
	cout<<"10. Binary Search"<<endl;
	cout<<"11. Thoat";
	do
	{
		cout<<"\nVui long nhap lua chon ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Nhap vao so phan tu: ";
				cin>>n;
				input(a,n);
				break;
			case 2:
				output(a,n);
				break;
			case 3:
				insertionsort(a,n);
				cout<<"Danh sach sau khi sap xep bang Insertion Sort: ";
				output(a,n);
				break;
			case 4:
				selectionsort(a,n);
				cout<<"Danh sach sau khi sap xep bang Selection Sort: ";
				output(a,n);
				break;
			case 5:
				interchangesort(a,n);
				cout<<"Danh sach sau khi sap xep bang Inserchange Sort: ";
				output(a,n);
				break;
			case 6:
				bubblesort(a,n);
				cout<<"Danh sach sau khi sap xep bang Bubble Sort: ";
				output(a,n);
				break;
			case 7:
				quicksort(a,0,n-1);
				cout<<"Danh sach sau khi sap xep bang Quick Sort: ";
				output(a,n);
				break;
			case 8:
				heapsort(a,n);
				cout<<"Danh sach sau khi sap xep bang Heap Sort: ";
				output(a,n);
				break;
			case 9:
				cout<<"Nhap vao gia tri x can tim: ";
				cin>>x;
				if(search(a,n,x)!=-1)
					cout<<"Tim thay x tai vi tri a["<<search(a,n,x)<<"]";
				else
					cout<<"Khong tim thay gia tri x";
				break;
			case 10:
				cout<<"Nhap vao gia tri x can tim: ";
				cin>>x;
				if(binarysearch(a,n,x)!=-1)
					cout<<"Tim thay x tai vi tri a["<<binarysearch(a,n,x)<<"]";
				else
					cout<<"Khong tim thay gia tri x";
				break;
			case 11:
				cout<<"Goodbye!...............";
				break;
			default:
				break;
		}
	}while(choice!=11);
	system("pause");
	return 0;
}