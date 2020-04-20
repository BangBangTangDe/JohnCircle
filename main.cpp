#include "CS206_studentID_name(CN).h"
//#include"CS206_studentID_name(CN).cpp"
#include<iostream>
#include<cmath>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

bool check(int* pa, int* pb, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (pa[i] != pb[i])
			return false;
	}
	return true;
}



int main() {
	
	cout << "test for circularqueue" << endl;
	CircularQueue<int> jonas(20);
	CircularQueue<int> jonas2(20);

	for (int i = 0; i < 20; i++)
	{
		jonas.enQueue(i);
	}
	for (int i = 0; i < 20; i++)
	{
		jonas.deQueue();
	}
	cout << "test for problem1\n\n" << endl;



	
	//test for problem 1
	int sol1[2];
	int ans1[2] = { 13, 15 };
	JosephusP1 jp1(25, 7);
	jp1.solve();
	jp1.output(sol1, 2);

	if (check(sol1, ans1, 2))
		cout << "right!" << endl;
	else
		cout << "wrong!" << endl;

	jp1.setParameter(0, 15); //set number of person = 15
	jp1.setParameter(1, 4); //set counting step = 4

	jp1.solve();

	jp1.print();

	//test for problem 2
	cout << "test for problem 2" << endl;
	int sol2[9];
	int ans2[9] = { 5, 17, 3, 14, 1, 11, 16, 8, 13 };//Ïà·´£º2 4 6 7 9 10 12 15 18
	int n = 9;
	JosephusP2 jp2(18, 5, 7);
	jp2.solve();
	jp2.output(sol2, n);
	if (check(sol2, ans2, n))
	{
		cout << "right!" << endl;
	}

	else
	{ 
		cout << "wrong!" << endl;
	}


	jp2.setParameter(0, 26); //set number of person = 26
	jp2.setParameter(1, 7); //set anti clockwise counting step = 7
	jp2.setParameter(2, 7); //set couter clockwise counting step = 7
	jp2.solve();
	jp2.print();

	return 0;

}




