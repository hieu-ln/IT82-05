#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;

#define MAX 3000

//1.1
int a[MAX];
int n=0;

//1.2
void init(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	for(int i=0; i<n; i++)
		a[i] = rand() % 10000 + 1;
	cout << "DS da duoc nhap ngau nhien nhu sau: " << endl;
	for (int i=0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

//1.2
void input(int a[], int &n)
{
	cout << "Nhap vao so luong pt cua ds: ";
	cin >> n;
	cout << "Nhap vao cac pt cua ds: " << endl;
	for(int i=0; i<n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//1.3
void output(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
//1.4
void Insertion_Sort(int a[], int n)
{
	int i, j, key;
	for(i=1; i<n;i++)
	{
		key = a[i];
		j = i-1;
		while(j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = key;
	}
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

//1.5
void Selection_Sort(int a[], int n)
{
	int i, j, min;
	for(i=0; i< n-1; i++)
	{
		min = i;
		for(j= i+1; j<n; j++)
			if(a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
}

//1.6
void Interchange_Sort(int a[], int n)
{
	for(int i=0; i< n-1; i++)
		for(int j= 1+1; j<n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}

//1.7
void Bubble_Sort(int a[], int n)
{
	bool haveSwap = false;
	for(int i=0; i<n; i++)
	{
		haveSwap = false;
		for(int j=0; j< n-i-1; j++)
			if(a[j] > a[j+1])
			{
				swap( a[j], a[j+1] );
				haveSwap = true;
			}
		if(haveSwap == false)
			break;
	}
}

//1.8
void Quick_Sort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while(i < j)
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left < j)
		Quick_Sort(a, left, j);
	if(i < right)
		Quick_Sort(a, i, right);
}

//1.9
void shift(int a[], int i, int n)
{
	int j = 2*j+1;
	if(j >= n) 
		return;
	if(j+1 < n) 
		if(a[i] < a[j+1])
			j++;

	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);\
	}
}

void Heap_Sort(int a[], int n)
{
	int i = n/2 - 1;
	while(i >= 0)
	{
		shift(a, i, n);
		i--;
	}
	int right = n-1;
	while(right > 0)
	{
		swap(a[0] , a[right]);
		right--;
		if(right > 0)
			shift(a, 0, right);
	}
}

//1.10
int Search_Sequence(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i] != x)
		i++;
	if(i == n)
		return -1;
	else
		return i; //cout << "Tìm thấy tại vtri " << i;
}

//1.11
int Search_Binary(int a[], int l, int r, int x)
{
	if(r >= l)
	{
		int mid = l+(r-1) /2;
		if(a[mid] == x)
			return mid;
		if(a[mid] > x)
			return Search_Binary(a, l, mid-1, x);
		return Search_Binary(a, mid+1, r, x);
	}
	return -1;
}

int main()
{
	int b[MAX];
	int choice, x=10, i;
	system("cls");
	cout << "--------BAI TAP 1, CHUONG 3, XEP THU TU va TIM KIEM---------" << endl;
	cout << "0. Khoi tao danh sach ngau nhien " << endl;
	cout << "1. Nhap danh sach " << endl;
	cout << "2. Xuat danh sach " << endl;
	cout << "3. Xep thu tu ds bang SECLECTION SORT" << endl;
	cout << "4. Xep thu tu ds bang INSERTION SORT" << endl;
	cout << "5. Xep thu tu ds bang BUBBLE SORT" << endl;
	cout << "6. Xep thu tu ds bang INTERCHANGE SORT" << endl;
	cout << "7. Xep thu tu ds bang QUICK SORT" << endl;
	cout << "8. Xep thu tu ds bang HEAP SORT" << endl;
	cout << "9. Tim kiem pt x bang TIM KIEM TUAN HOAN" << endl;
	cout << "10. Tim kiem pt x bang TIM KIEM NHI PHAN" << endl;
	cout << "11. Thoat" << endl;
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			cout << "Danh sach la: " << endl;
			output(a, n);
			break;
		case 3:
			Selection_Sort(b, n);
			if(n < 100)
			{
				cout << "DS sau khi sax voi SECLECTION SORT la: " << endl;
				output(b, n);
			}
			break;
		case 4:
			Insertion_Sort(b, n);
			if(n < 100)
			{
				cout << "DS sau khi sax voi INSERTION SORT la: " << endl;
				output(b, n);
			}
			break;
		case 5:
			
			Bubble_Sort(b, n);
			if(n < 100)
			{
				cout << "DS sau khi sax voi BUBBLE SORT la: " << endl;
				output(b, n);
			}
			break;
		case 6:
			Interchange_Sort(b, n);
			if(n < 100)
			{
				cout << "DS sau khi sax voi INTERCHANGE SORT la: " << endl;
				output(b, n);
			}
			break;
		case 7:
			Quick_Sort(b, 0, n-1);
			if(n < 100)
			{
				cout << "DS sau khi sax voi Quick SORT la: " << endl;
				output(b, n);
			}
			break;
		case 8:
			Heap_Sort(b, n);
			if(n < 100)
			{
				cout << "DS sau khi sax voi HEAP SORT la: " << endl;
				output(b, n);
			}
			break;
		case 9:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			i = Search_Sequence(a, n ,x);
			if(i == -1)
				cout << "Khong tim thay x = " << x << " trong mang" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			break;
		case 10:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			i = Search_Binary(b, 0, n, x);
			if(i == -1)
				cout << "Khong tim thay x = " << x << " trong mang" << endl;
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			break;
		case 11:
			cout << "\nGood bye";
			break;
		default:
			break;
		}
	}while(choice != 11);
	system("pause");
	return 0;
}