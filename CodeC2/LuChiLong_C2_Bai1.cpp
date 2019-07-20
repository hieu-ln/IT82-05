//#include <iostream>
//#include <stdio.h>
//using namespace std;
////1.1
//#define MAX 100
//int a[MAX];
//int n;
////1.2
//void input(int a[], int &n)
//{
//	for(int i=0; i<n; i++)
//	{
//		cout<<"nhap a["<<i<<"]=";
//		cin>>a[i];
//	}
//}
////1.3
//void output(int a[],int n)
//{
//	for(int i=0; i<n; i++)
//		cout<<a[i]<<endl;
//} 
////1.4
//int search(int a[],int n,int x)
//{
//	int i=0;
//	while((i<n)&&(a[i]=!x))
//		i++;
//	if(i==n)
//		return -1;
//	return i;
//}
////1.5
//int insert_last(int a[],int &n,int x)
//{
//	if(n<MAX)
//	{
//		a[n]=x;
//		n++;
//		return 1;
//	}
//	else
//		return 0;
//}
////1.6
//int delete_last(int a[],int &n,int x)
//{
//	if(n>0)
//	{
//		n--;
//		return 1;
//	}
//	else
//		return 0;
//}
////1.7
//int delete_i(int a[],int &n,int i)
//{
//	if(i>=0 && i<n)
//	{
//		for(int j=i;j<n;j++)
//		{
//			a[j]=a[j]+1;
//		}
//		n--;
//		return 1;
//	}
//	return 0;
//}
////1.8
//int search_delete(int a[],int &n,int x)
//{
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]==x)
//		{
//			delete_i(a,n,i);
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int choice=0;
//	int x,i;
//	system("cls");
//	cout<<" -----BAI TAP 1, CHUONG 2, DANH SACH DAC-----"<<endl;
//	cout<<"1. Nhap danh sach"<<endl;
//	cout<<"2. xuat danh sach"<<endl;
//	cout<<"3. Tim gia tri trong danh sach"<<endl;
//	cout<<"4. Them phan tu trong danh sach"<<endl;
//	cout<<"5. Xoa phan tu cuoi trong danh sach"<<endl;
//	cout<<"6. Xoa phan tu thu i trong danh sach"<<endl;
//	cout<<"7. Tim va xoa danh sach"<<endl;
//	cout<<"8. thoat danh sach"<<endl;
//	do{
//		cout<<"lua chon: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				cout<<"nhap n: ";
//				cin>>n;
//				input(a,n);
//				cout<<"DONE";
//				break;
//			case 2:
//				output(a,n);
//				cout<<"DONE";
//				break;
//			case 3:
//				cout<<"nhap gia tri x can tim: ";
//				cin>>x;
//				if(search(a,n,x)>=0)
//					cout<<x<<"o vi tri: "<<search(a,n,x)<<endl;
//				else
//					cout<<"khong tim thay"<<endl;
//				break;
//			case 4:
//				cout<<"nhap them phan tu cuoi: ";
//				cin>>x;
//				insert_last(a,n,x);
//				output(a,n);
//				break;
//			case 5:
//				cout<<"xoa phan tu cuoi: ";
//				delete_last(a,n,x);
//				output(a,n);
//				break;
//			case 6:
//				cout<<"xoa phan tu vi tri i: ";
//				cin>>i;
//				delete_i(a,n,i);
//				output(a,n);
//				break;
//			case 7:
//				cout<<"nhap gia tri can tim va xoa: ";
//				cin>>x;
//				search_delete(a,n,x);
//				output(a,n);
//				break;
//			case 8:
//				cout<<"GOODBYE";
//				break;
//		}
//	}while(choice!=8);
//	system("pause");
//	return 0;
//}