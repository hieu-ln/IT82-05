//#include<iostream>
//using namespace std;
//const int Max = 100;
//
//void init(int a[], int &n)
//{
//	cout<<"Nhap bac cua da thuc: ";
//	cin>>n;
//	for(int i=n;i>=0;i--)
//	{
//		cout<<"Nhap he so cua x^"<<i<<": ";
//		cin>>a[i];
//	}
//}
//int *cong(int p[], int q[], int np, int nq, int &n)
//{
//	if(np >= nq)
//		n = np;
//	else
//		n = nq;
//	int a[Max];
//	for(int i=0;i<=n;i++)
//	{
//		if(i<=np&&i<=nq)
//			a[i] = p[i] + q[i];
//		else
//			if(i<=np&&i>nq)
//				a[i] = p[i];
//			else
//				a[i] = q[i];
//	}
//	return a;
//}
//int *tru(int p[], int q[], int np, int nq, int &n)
//{
//	if(np >= nq)
//		n = np;
//	else
//		n = nq;
//	int a[Max];
//	for(int i=0;i<=n;i++)
//	{
//		if(i<=np&&i<=nq)
//			a[i] = p[i] - q[i];
//		else
//			if(i<=np&&i>nq)
//				a[i] = p[i];
//			else
//				a[i] = q[i];
//	}
//	return a;
//}
//int *nhan(int p[], int q[], int np, int nq, int &n)
//{
//	if(np >= nq)
//		n = np;
//	else
//		n = nq;
//	int a[Max];
//	for(int i=0;i<=n;i++)
//	{
//		if(i<=np&&i<=nq)
//			a[i] = p[i] * q[i];
//		else
//			if(i<=np&&i>nq)
//				a[i] = p[i];
//			else
//				a[i] = q[i];
//	}
//	return a;
//}
//int *chia(int p[], int q[], int np, int nq, int &n)
//{
//	if(np >= nq)
//		n = np;
//	else
//		n = nq;
//	int a[Max];
//	for(int i=0;i<=n;i++)
//	{
//		if(i<=np&&i<=nq)
//			a[i] = p[i] / q[i];
//		else
//			if(i<=np&&i>nq)
//				a[i] = p[i];
//			else
//				a[i] = q[i];
//	}
//	return a;
//}
//void output(int a[], int n)
//{
//	for(int i=n;i>=0;i--)
//	{
//		cout<<a[i]<<"x^"<<i;
//		if(i>0 && a[n-1>0])
//			cout<<"+";
//	}
//}
//
//int main()
//{
//	int p[100],q[100],np,nq,n;
//	int choice = 0;
//
//	cout<<"-----BT NANG CAO CHUONG 2, BAI 13 -----";
//	cout<<"\n1.Cong hai da thuc";
//	cout<<"\n2.Tru hai da thuc";
//	cout<<"\n3.Nhan hai da thuc";
//	cout<<"\n4.Chia hai da thuc";
//
//	do
//	{
//		cout<<"\nChon so thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{		
//			case 1:
//			cout<<"\nNhap da thuc P(x) gom: "<<endl;
//			init(p,np);
//			cout<<"\nNhap da thuc Q(x) gom: "<<endl;
//			init(q,nq);
//			cout<<"\nDa thuc ";
//			output(p,np);
//			cout<<"\nDa thuc ";
//			output(q,nq);
//			int *res = cong(p,q,np,nq,n);
//			cout<<"\nDa thuc KQ(x): ";
//			output(res,n);
//			cout<<endl;
//			break;
//			case 2:
//				cout<<"\nNhap da thuc P(x) gom: "<<endl;
//			init(p,np);
//			cout<<"\nNhap da thuc Q(x) gom: "<<endl;
//			init(q,nq);
//			cout<<"\nDa thuc ";
//			output(p,np);
//			cout<<"\nDa thuc ";
//			output(q,nq);
//			int *res1 = tru(p,q,np,nq,n);
//			cout<<"\nDa thuc KQ(x): ";
//			output(res1,n);
//			cout<<endl;
//				break;
//			case 3:
//				cout<<"\nNhap da thuc P(x) gom: "<<endl;
//			init(p,np);
//			cout<<"\nNhap da thuc Q(x) gom: "<<endl;
//			init(q,nq);
//			cout<<"\nDa thuc ";
//			output(p,np);
//			cout<<"\nDa thuc ";
//			output(q,nq);
//			int *res2 = nhan(p,q,np,nq,n);
//			cout<<"\nDa thuc KQ(x): ";
//			output(res2,n);
//			cout<<endl;
//				break;
//			case 4:
//				cout<<"\nNhap da thuc P(x) gom: "<<endl;
//			init(p,np);
//			cout<<"\nNhap da thuc Q(x) gom: "<<endl;
//			init(q,nq);
//			cout<<"\nDa thuc ";
//			output(p,np);
//			cout<<"\nDa thuc ";
//			output(q,nq);
//			int *res3 = chia(p,q,np,nq,n);
//			cout<<"\nDa thuc KQ(x): ";
//			output(res3,n);
//			cout<<endl;
//				break;
//		}
//	}while(choice !=5);
//	system("pause");
//	return 0;
//}