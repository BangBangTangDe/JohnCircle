#include<iostream>
#include<cmath>
using namespace std;
#pragma once
template <typename T>			//类模板和模板函数必须写在一个文件里
class CircularQueue 
{								// an interface for a circular queue
public:
	CircularQueue(int N = 0, int k =0);	//Initialize a circular queue with capacity= N 
	~CircularQueue();
	int Capacity() const;		// capacity of queue
	int Size() const;			// number of elements in queue
	int Adjust(int N);			//adjust the capacity of the queue to N
	
	const T& Front() const;		// the front element
	const T& Back() const;		// the last element
	
	void enQueue(const T& e);	// enqueue element at rear
	void deQueue();				// dequeue element at front
	
	bool isEmpty();				// is the queue empty?
	bool isFull();				// is the queue full?

public:
	T* data;					//data array
	
	int front;					// the position of front
	int rear;					// the position of rear
	int size;					// the number of elements
	int capa;					// the capacity of queue
	int n;
	int k;
};

//泛型编程
template <typename T>
CircularQueue<T>::CircularQueue(int N , int k )		//Initialize a circular queue with capacity= N 
{
	this->front = 0;					// the position of front
	this->rear = 0;						//the initial position of rear
	
	this->size = 0;
	this->n = N;
	this->capa = N;
	this->k = k;
	
	data = new int[this->capa];
	
	//cout << "this->capa " << this->capa << endl;

	;

}

template <typename T>
CircularQueue<T>::~CircularQueue()
{
	if (data != NULL)
	{
		delete[]data;
		data = NULL;
	}

}



template <typename T>
int	CircularQueue<T>::Capacity() const
{
	return capa;

}
// capacity of queue


template <typename T>
int CircularQueue<T>::Size() const	// number of elements in queue
{
	return this->size;
}

template <typename T>
int CircularQueue<T>::Adjust(int N)			//adjust the capacity of the queue to N
{

	return 0;

}

template <typename T>
const  T& CircularQueue<T>::Front()const			// the front element
{
	//this->front = data[front];
	return this->front;

}

template <class T>
const	 T& CircularQueue<T>::Back()const		// the last element
{
	return this->rear;
}

template <class T>
void	CircularQueue<T>::enQueue(const T &e)	// enqueue element at rear
{
	//cout << "this->capa " << this->capa << endl;
	if (this->capa == 0)
	{
		cout << "enQueue Error"<<endl;
	}
	else
	{
		data[rear] = e;
		this->rear++;
		size++;

	}
	
}

template <class T>
void	CircularQueue<T>::deQueue()			// dequeue element at front
{
	if (this->capa == 0)
	{
		cout << "deQueue Error" << endl;
		abort();
	}
	else
	{
		if (front <= rear)				//前指针向后移动
		{
			cout << "data[front]" << data[front] << endl;;
			front++;
			size--;
		}
		else
		{
			cout << "front <= rear Error" << endl;
			abort();
		}
	}
	;
}

template <class T>
bool	CircularQueue<T>::isEmpty()				// is the queue empty?
{
	return size == 0 ? true : false;
}

template <class T>
bool	CircularQueue<T>::isFull()
{
	return  size == capa ? true : false;
}





class Josephus 
{
public:
	virtual int setParameter(int type, int val) = 0; //set parameter's value
	virtual void solve() = 0;						//solve the problem
	virtual void print() = 0;						//output the solution
	virtual void output(int* sol, int n) = 0;		//虚函数抛出接口，各子类重写接口
	//output the solution in array sol with size n

protected:
	CircularQueue<int> cqPerson;					// circular queue to store person
};


class JosephusP1 : public Josephus
{
public:

JosephusP1(int n, int k);			//n is the number of person (= N +2)
int setParameter(int type, int val); //set parameter's value
void solve();						//solve the problem
void print();						//output the solution
void output(int* sol, int n);

public:
	int n = 0;
	int m = 0;
	CircularQueue<int> jonas1;
};


class JosephusP2 : public Josephus

{
public:

JosephusP2(int n, int m, int k);	// n is the number of person (= 2N)
int setParameter(int type, int val); //set parameter's value
void solve();						//solve the problem
void print();						//output the solution
void output(int* sol, int n);

public:
	int n = 0;
	int shun = 0;//顺时针
	int ni = 0;//逆时针
	CircularQueue<int> jonas2;
};



