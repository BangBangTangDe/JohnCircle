#include "CS206_studentID_name(CN).h"
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
int ans[100] = { 0 };
int vis[100] = { 0 };
int ans1[100] = { 0 };
int vis1[100] = { 0 };
int visit1[100] = { 0 };

JosephusP1::JosephusP1(int n, int m)			//n is the number of person (= N +2)
{	
	
	this->n = n;
	this->m = m;
	this->jonas1.n = n;
	this->jonas1.k = m;
	this->jonas1.capa = n;
	this->jonas1.data = new int[n];
}
int JosephusP1::setParameter(int type, int val) //set parameter's value
{
	if (type == 1)
	{
		this->m = val;
		this->jonas1.k = val;
		this->jonas1.front = 0;
		this->jonas1.rear = 0;
	}
	else if(type==0)
	{
		this->n = val;
		this->jonas1.n = val;
		this->jonas1.capa = val;
		this->jonas1.size = val;
		this->jonas1.data = new int[val];
		this->jonas1.front = 0;
		this->jonas1.rear = 0;
	}
	return 0;
}
void JosephusP1::solve()						//solve the problem
{
	memset(ans, 0, 100 * sizeof(int));
	memset(vis, 0, 100 * sizeof(int));
	//memset(this->jonas1.data, 0, this->n * sizeof(int));
	for (int i = 0; i <this->n; i++)
	{
		this->jonas1.enQueue(i);
	}

	int cnt = 0;
	int count = this->n;
	while (count != 2)
	{
		for (int i = 0; i < this->m-1; i++)
		{
			this->jonas1.front = (this->jonas1.front + 1) % n;
			this->jonas1.rear = (this->jonas1.rear + 1) % n;
			this->jonas1.data[this->jonas1.rear] = this->jonas1.data[this->jonas1.front];
			
		}
		count--;
		this->jonas1.front = (this->jonas1.front + 1) % n;
		ans[cnt++] = this->jonas1.data[this->jonas1.front];
	}
	delete this->jonas1.data;
}
void JosephusP1::print()						//output the solution
{
	int shuchu[2];
	this->output(shuchu, 2);

	cout << "solution result  is:" <<shuchu[0]<<","<<shuchu[1]<< endl;
	
}
void JosephusP1::output(int* sol, int n)
{
	int k = 0;
	int cnt = 0;
	for (int i = 0; i < this->n-2; i++)
	{
		vis[ans[i]] = 1;
	}

	for (int j = 0; j < this->n; j++)
	{
		if (vis[j] == 0)
		{
			if(j==0)
			sol[cnt++] = n;
			else
			{
				sol[cnt++] = j;
			}
		}
	}
	

}


/**********************************************/
//µÚ¶þÌâ

JosephusP2::JosephusP2(int n, int m, int k)			//n is the number of person (= N +2)
{
	this->n = n;
	this->shun = m;
	this->ni = k;
	this->jonas2.capa = n;
	this->jonas2.data = new int[n];
}


int JosephusP2::setParameter(int type, int val) //set parameter's value
{
	if (type == 0)
	{
		this-> n= val;
		this->jonas2.capa = val;
		this->jonas2.size = val;
		this->jonas2.front = 0;
		this->jonas2.rear = 0;
		this->jonas2.data = new int[val];
	}
	else if (type == 1)
	{
		this->shun = val;
	}
	else if (type == 2)
	{
		this->ni = val;
	}
	return 0;
}


void JosephusP2::solve()						//solve the problemthis->jonas2
{
	memset(ans1, 0, 100 * sizeof(int));
	memset(vis1, 0, 100 * sizeof(int));
	memset(visit1, 0, 100 * sizeof(int));
	for (int i = 1; i <=this->n; i++)
	{
		this->jonas2.enQueue(i);
	}

	int flag = 1;
	int cnt = 0;
	int count = this->n;
	int k = 0;
	while (count != (this->n/2))
	{
		if (flag == 1)
		{
			cnt = 0;
			while (cnt<this->shun-1)
			{
				if (visit1[this->jonas2.front] == 0)
				{
					cnt++;
				}
				this->jonas2.front = (this->jonas2.front + 1) % n;
			}
			while (visit1[this->jonas2.front])
			{
				this->jonas2.front = (this->jonas2.front + 1) % n;
			}
			visit1[this->jonas2.front] = 1;
			ans1[k++] = this->jonas2.data[this->jonas2.front];
			while (visit1[this->jonas2.front])
			{
				this->jonas2.front = (this->jonas2.front + 1) % n;
			}
		}
		else
		{
			cnt = 0;
			while (cnt < this->ni - 1)
			{
				if (visit1[this->jonas2.front] == 0)
				{
					cnt++;
				}
				this->jonas2.front = (this->jonas2.front - 1 + n) % n;
			}
			while (visit1[this->jonas2.front])
			{
				this->jonas2.front = (this->jonas2.front - 1+n) % n;
			}
			visit1[this->jonas2.front] = 1;
			ans1[k++] = this->jonas2.data[this->jonas2.front];
			while (visit1[this->jonas2.front])
			{
				this->jonas2.front = (this->jonas2.front - 1 + n) % n;
			}
			
			
		}
		flag = -flag;
		count--;
	}
}
void JosephusP2::print()						//output the solution
{
	int *shuchu=new int[this->n/2];
	this->output(shuchu, this->n);
	cout << "solution result  is:";
	for (int i = 0; i < this->n/2; i++)
		cout << shuchu[i]<<" ";
	cout << endl;
}
void JosephusP2::output(int* sol, int n)
{
	int k = 0;
	for (int i = 0; i < this->n/2; i++)
	{
		sol[k++] = ans1[i];
	}
}



