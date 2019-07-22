#include<iostream>
#include<stdio.h>
using namespace std;
int SA[100], SB[100], SC[100], SN[100];
void chuyendia(int a,int b,int c,int n,int &space)
{ 
	space++;
	SN[space]=n-1;SA[space]=c;SB[space]=b;SC[space]=a;
	space++;
	SN[space]=1;SA[space]=a;SB[space]=b;SC[space]=c;
	space++;
	SN[space]=n-1;SA[space]=a;SB[space]=c;SC[space]=b;
}
void thaphanoi(int a,int b, int c, int n)
{ 
	SN[0]=n;SA[0]=a;SB[0]=b;SC[0]=c;
	int space=0;
	while (space>=0)
	{
	space--;
	if (SN[space+1]==1) 
	{
		cout<<endl;
		printf("%c -> %c\t",SA[space+1],SB[space+1]);
	}
	else
		chuyendia(SA[space+1],SB[space+1],SC[space+1],SN[space+1],space);
	}

}
int main()
{	
	int n,a=65,b=66,c=67;
	cout<<"nhap so dia: ";
	cin>>n;
	thaphanoi(a,b,c,n);
	system("pause");
	return 0;
}