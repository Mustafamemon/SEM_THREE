#include<iostream>
using namespace std;
template <class T>
class Queue
{
	private:
		int rear,front ;
		T *array;
		int capacity; 
	public:
		Queue(int c)
		{
			capacity=c;
			rear=front=-1;
			array = new T[capacity];
		}
		bool isEmpty()
		{
			return (front==-1);
		}
		bool isFull()
		{
			return ((rear+1)%capacity==front);
		}
		void enQueue(T data)
		{
			if(!isFull())
			{
				rear=rear+1%capacity;
				array[rear]=data;
				if(front==-1)
					front=rear;
			}
			else
				cout<<"Over Flow!\n";
		}
		int deQueue()
		{
			int data=-1;
			if(!isEmpty())
			{
				data=array[front];
				if(front==rear)
					front=rear-1;
				else
					front=front+1%capacity;
			}
			else
				cout<<"Under Flow!\n";
			return data; 			
		}
};
int main()
{
	Queue <int>q(4);
	q.deQueue();
	for(int i=0;i<5;i++)
		q.enQueue(4);
	cout<<q.deQueue()<<"\n";
}
