//// BTChuong 2
////Bai Thuc Hanh So 1
//#include<iostream>
//using namespace std;
////Cau 1.1 Khai bao cau truc
//const int MAX = 100;
//int a[MAX];
//int n;
////Cau 1.2 Nhap danh sach
//void input (int a[], int &n )
//{
//	cout<<"Nhap n: ";
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		cout<<"Nhap a["<<i<<"] = ";
//		cin>>a[i];
//	}
//}
////Cau 1.3 Xuat danh sach
//void output (int a[], int n)
//{
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//}
////Cau 1.4 Tim phan tu trong danh sach
//int search (int a[], int n, int x)
//{
//	int i=0;
//	while((i<n) && (a[i] != x))
//	i++;
//	if (i == n)
//		return -1;
//	return i;
//}
////Cau 1.5 Chen phan tu cuoi danh sach
//int insert_last (int a[],int &n, int x)
//{
//	if(n<MAX)
//	{
//			a[n] = x;
//		n++;
//		return 1;
//	}
//	return 0;
//}
////Cau 1.6 Xoa phan tu cuoi danh sach
//int delete_last (int a[], int &n)
//{
//	if (n > 0)
//	{
//		n--;
//		return 1;
//	}
//	return 0;
//}
////Cau 1.7
//int Delete (int a[], int &n, int i)
//{
//	if(i >= 0 && i<n)
//	{
//		for(int j=i;j<n-1;j++)
//			a[j] = a[j + 1];
//		n--;
//		return 1;
//	}
//	return 0;
//}
//int search_delete (int a[], int &n, int x)
//{
//	for(int i=0 ; i<n; i++)
//	{
//		if(a[i] == x)
//		{
//			Delete(a,n,x);
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int choice = 0;
//	int  x,i;
//	system("cls");
//	cout<<"===== BAI TAP DANH SACH LIEN KET DAC =====";
//	cout<<"\n1.Nhap danh sach "<<endl;
//	cout<<"2.Xuat danh sach "<<endl;
//	cout<<"3.Tim phan tu trong danh sach "<<endl;
//	cout<<"4.Them phan tu cuoi danh sach "<<endl;
//	cout<<"5.Xoa phan tu cuoi danh sach "<<endl;
//	cout<<"6.Xoa phan tu tai vi tri i = "<<endl;
//	cout<<"7.Tim phan tu va xoa phan tu do trong dach sach "<<endl;
//	cout<<"8.Thoat ";
//	do
//	{
//		cout<<"Vui long nhap so de thuc hien: ";
//		cin>>choice;
//		switch (choice)
//			{
//				case 1:
//					input(a,n);
//					cout<<"\nBan da nhap thanh cong ! ";
//					input(a,n);
//					break;
//				case 2:
//					cout<<"\nBan da nhap la: ";
//					output(a,n);
//					break;
//				case 3:
//					cout<<"\nNhap x: ";
//					cin>>x;
//					i = search(a,n,x);
//					if( i == -1)
//						cout<<"Tim khong thay phan tu co gia tri"<<x<<endl;
//					else
//						cout<<"Tim thay phan tu co gia tri i= "<<i<<endl;
//					break;
//				case 4:
//					cout<<"Nhap x: ";
//					cin>>x;
//					i = insert_last(a,n,x);
//					if(i == 0)
//						cout<<"Danh sach da day, khong the them !"<<x<<endl;
//					else
//					{
//						cout<<"Da them phan tu x = "<<i<<" vao cuoi danh sach "<<endl;
//						cout<<"Danh sach sau khi them la: ";
//						output(a,n);
//					}
//					break;
//				case 5:
//					cout<<"Nhap x: ";
//					cin>>x;
//					i = delete_last(a,n);
//					if(i>0)
//					{
//						cout<<"Xoa thanh cong !";
//						cout<<"\nDanh sach xoa phan tu cuoi la: ";
//						output(a,n);
//					}
//					else
//						cout<<"Danh sach khong co phan tu nao !"<<endl;
//					break;
//				case 6:
//					cout<<"Nhap vi tri can xoa i = ";
//					cin>>i;
//					i = Delete(a,n,i);
//					if(i == 1)
//					{
//						cout<<" Xoa thanh cong !";
//						cout<<"\nDanh sach sau khi xoa ";
//						output(a,n);
//					}
//					else
//						cout<<"Danh sach khong co phan tu de xoa "<<endl;
//					break;
//				case 7:
//					cout<<"Nhap vi tri x: ";
//					cin>>x;
//					i = search_delete(a,n,x);
//					if(i == 1)
//					{
//						cout<<"Xoa thanh cong ";
//						cout<<"Danh sach sau khi xoa ";
//						output(a,n);
//					}
//					else
//						cout<<"Khong co phan tu de xoa ";
//					break;
//				case 8:
//					cout<<"Chao tam biet !";
//					break;
//				default:
//					break;
//		}
//	}while(choice != 8);
//		
//	system("pause");
//	return 0;
//		
//}