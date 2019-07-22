//#include <iostream>
//#include <stdio.h>
//using namespace std;
//#define MAX 100
//
//int a[MAX];
//int space;
//void init(int a[],int &space)
//{
//	space=-1;
//}
////chuyen doi co so
//void he2(int a[],int &space, int x)
//{
//	while(x>0)
//	{
//		a[++space]=x%2;
//		x=x/2;
//	}
//}
//void he8(int a[],int &space, int x)
//{
//	while(x>0)
//	{
//		a[++space]=x%8;
//		x=x/8;
//	}
//}
//void he16(int a[],int &space, int x)
//{
//	while(x>0)
//	{
//		a[++space]=x%16;
//		x=x/16;
//	}
//}
//void pro_list(int a[],int space)
//{
//	int x;
//	int i=space;
//	while(i>=0)
//	{
//		x=a[i];
//		if (x >= 10)
//		{
//			if (x == 10)
//				cout << "\tA";
//			else if (x == 11)
//				cout << "\tB";
//			else if (x == 12)
//				cout << "\tC";
//			else if (x == 13)
//				cout << "\tD";
//			else if (x == 14)
//				cout << "\tE";
//			else if (x == 15)
//				cout << "\tF";
//		}
//		else
//			cout << "\t" << a[i];
//		i--;
//	}
//}
//int main()
//{
//	init(a,space);
//	int hethapphan;
//	int chonhe;
//	cout<<"Nhap gia tri he thap phan(10) can chuyen: ";
//	cin>>hethapphan;
//	cout<<"chon he can doi: ";
//	cin>>chonhe;
//	switch(chonhe)
//	{
//		case 2:
//		{
//			he2(a,space,hethapphan);
//			pro_list(a,space);
//			cout<<endl;
//			break;
//		}
//		case 8:
//		{
//			he8(a,space,hethapphan);
//			pro_list(a,space);
//			cout<<endl;
//			break;
//		}
//		case 16:
//		{
//			he16(a,space,hethapphan);
//			pro_list(a,space);
//			cout<<endl;
//			break;
//		}
//		default:
//			break;
//	}
//	system("pause");
//	return 0;
//}