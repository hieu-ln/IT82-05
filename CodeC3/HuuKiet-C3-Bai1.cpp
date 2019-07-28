 //BAI TAP 1 CHUONG 3
#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

#define MAX 5000
//Cau1.1
int a[MAX];
int n;
//Cau 1.0 Nhap danh sach tu dong (khoi tao ngau nhien)
void init(int a[],int &n)
{
	cout<<"Nhap so luong phan tu trong danh sach: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%10000 + 1;
	}
	cout<<"Danh sach da duoc nhap ngau nhien la :"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
//Cau 1.2 Nhap danh sach
void input(int a[],int &n)
{
	cout<<"Nhap so luong phan tu cua danh sach: ";
	cin>>n;
	cout<<"Nhap vao cac phan tu cua danh sach: ";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]= ";
		cin>>a[i];
	}
}
//1.3 Xuat danh sach
void output(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void copyArray(int a[],int b[],int n)
{
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
}
//1.4 Insertion Sort
void InsertionSort(int a[],int n)
{
	int i,key,j;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		/*Di chuyen cac phan tu co gia tri lon hon key ve sau mot vi tri so voi vi tri ban dau cua no*/
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}
//Ham doi cho hai so nguyen
void Swap(int &a,int&b)
{
	int t=a;
	a=b;
	b=t;
}
//1.5 Selection Sort
void SelectionSort(int a[],int n)
{
	int i,j,min_idx;
	Di chuyen ranh gioi cua mang da va chua sap xep
	for(int i=0;i<n-1;i++)
	{
		Tim phan tu nho nhat trong mang chua sap xep
		min_idx=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[min_idx])
				min_idx=j;
		Doi cho phan tu nho nhat voi phan tu dau tien
		Swap(a[min_idx],a[i]);

	}
}
//1.6 Interchange Sort
void InterchangeSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				Swap(a[i],a[j]);
}
//1.7 Bubble Sort
void BubbleSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[j-1]>a[j])//DK phan tu sau nho hon phan tu truoc
				Swap(a[j-1],a[j]);
}
//1.8QuickSort
void QuickSort(int a[],int left,int right)
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
			Swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(left<j)
		QuickSort(a,left,j);
	if(right>i)
		QuickSort(a,i,right);
}//1.9 HeapSort
void shift(int a[],int i,int n)
{
	int j=2*i+1;
	if(j>=n)//Neu vi tri j khong ton tai trong danh sach dang xet thi thoat
		return ;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else{
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
		shift(a,j,n);
	}
}
void HeapSort(int a[],int n)
{
	int i=n/2;
	while(i>=0)//tao Heap ban dau
	{
		shift(a,i,n-1);
		i--;
	}
	int right = n-1;
	while(right>0)
	{
		Swap(a[0],a[right]);
			right--;
		if(right>0)
			shift(a,0,right);
	}
}
//1.10 tim phan tu bang tuan tu
void searchSequence(int a[],int n,int x)
{
	int i=0;
	while(i<n&&a[i]!=x)
		i++;
	if(i==n)
		cout<<"Khong tim thay";
	else
		cout<<"Tim thay vi tri "<<i;
}
//1.11 tim phan tu bang tim kiem nhi phan
int SearchBinary(int a[],int l,int r,int x)
{
	if(r>=l){
		int mid=l+(r-1)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			return SearchBinary(a,l,mid-1,x);
		return SearchBinary(a,mid+1,r,x);
	}
	return -1;
}


int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice,x,i;
	system("cls");
	cout<<"---------------BAI 1,CHUONG 3--------------";
	cout<<"0.kHOI TAO DANH SACH NGAU NHIEN"<<endl;
	cout<<"1.NHAP DANH SACH"<<endl;
	cout<<"2.XUAT DANH SACH"<<endl;
	cout<<"3.XEP THU TU DANH SACH BANH SECLECTION SORT"<<endl;
	cout<<"4.XEP THU TU DANH SACH BANH INTERTION SORT"<<endl;
	cout<<"5.XEP THU TU DANH SACH BANH BUBBLE SORT"<<endl;
	cout<<"6.XEP THU TU DANH SACH BANH INTERCHANGE SORT"<<endl;
	cout<<"7.XEP THU TU DANH SACH BANH QUICKSORT"<<endl;
	cout<<"8.XEP THU TU DANH SACH BANH HEAPSORT"<<endl;
	cout<<"9.TIM KIEM X BANG TIEM KIEM TUAN TU"<<endl;
	cout<<"10.TIM KIEM X BANG TIM KIEM NHI PHAN"<<endl;
	cout<<"11.THOAT"<<endl;
	do{
		cout<<"Chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 0:
				init(a,n);
				break;
			case 1:
				input(a,n);
				break;
			case 2:
				cout<<"Danh sach la: "<<endl;
				output(a,n);
				break;
			case 3:
				copyArray(a,b,n);
				start=clock();
				SelectionSort(a,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi SECLECTIONSORT la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian SELECTION SORT: "<<duration*1000000<<endl;
				break;
			case 4:
				copyArray(a,b,n);
				start=clock();
				InsertionSort(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<10000)
				{
					cout<<"Danh sach sau khi xep thu tu voi INSERTION SORT la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian INSERTION SORT: "<<duration*1000000<<endl;
				break;
			case 5:
				copyArray(a,b,n);
				start=clock();
				BubbleSort(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi BUBBLE	 SORT la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian BUBBLE SORT: "<<duration*1000000<<endl;
				break;
			case 6:
				copyArray(a,b,n);
				start=clock();
				InterchangeSort(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi INTERCHANGE SORT la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian INTERCHANGETION SORT: "<<duration*1000000<<endl;
				break;
			case 7:
				copyArray(a,b,n);
				start=clock();
				QuickSort(b,0,n-1);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi QUICKSORT la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian QUICKSORT: "<<duration*1000000<<endl;
				break;
			case 8:
				copyArray(a,b,n);
				start=clock();
				HeapSort(b,n);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"Danh sach sau khi xep thu tu voi HEAPSORT la: "<<endl;
					output(b,n);
				}
				if(duration>0)
					cout<<"Thoi gian HEAPSORT: "<<duration*1000000<<endl;
				break;
			case 9:
				cout<<"vui long nhap gia tri x= ";
				cin>>x;
				start=clock();
				searchSequence(a,n,x);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(duration>0)
					cout<<"\n Thoi gian tim kiem tuan tu la: "<<duration*10000000<<"Microseconds";
				break;
			case 10:
				cout<<"vui long nhap gia tri x= ";
				cin>>x;
				start=clock();
				i=SearchBinary(b,0,n,x);
				duration=(clock()-start)/(double) CLOCKS_PER_SEC;
				if(i==-1)
					cout<<"Khong tim thay x="<<x<<"trong day"<<endl;
				else
					cout<<"tim thay x="<<x<<"tai vi tri i="<<i<<endl;
				if(duration>0)
					cout<<"\n Thoi gian tim kiem nhi phan la: "<<duration*10000000<<"Microseconds";
				break;
			case 11:
				cout<<"goodbye"<<endl;
			default:
				break;
		} 
	}while(choice!=11);
	system("pause");
	return 0;
}