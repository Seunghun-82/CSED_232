#include <iostream>
#include "SmartClass.h"

using namespace std;

int main()
{
	SmartPtr<int> ptr = new int(5);
	SmartArray<int> ptr2 = new int[5]{1,2,3,4,5};
	SmartPtr<int> ptr3 = new int(6);
	ptr3 = ptr;
	cout << *ptr3 << endl; //5
	for(int i = 0; i < 5; i++)
		cout << ptr2[i] << " "; //1 2 3 4 5
	cout << endl;
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	SmartMatrix<int> mat(3, 3, arr);
	cout << mat; 
	/*
	1 2 3
	4 5 6
	7 8 9*/
	cout << mat*3;
	/*
	3 6 9
	12 15 18
	21 24 27*/
	return 0;
}
