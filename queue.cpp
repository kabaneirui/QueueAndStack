//数组队列

#include <iostream>

using namespace std;


class Queue
{
private:
	int size;
	int top;
	int *date;
public:
	Queue(int s = 10)
	{
		size = s;
		top = -1;
		date = new int[s];
	}
	
	~Queue()
	{
		delete [] date;
	}
	void push(int d);
	int pop();
	int isEmpty();
};

int Queue::isEmpty()
{
	if(top == -1)
		return 0;
	if(top >= 0 && top < size)
		return 1;
}

void Queue::push(int d)
{
	if(top == size-1)return;
	date[++top] = d;
}

int Queue::pop()
{
	if(isEmpty == 0)throw;
	int temp = date[0];
	for(int i = 0; i<=top-1; i++)
		date[i] = date[i+1];
	top--;
	return temp;
}

void main()
{
	Queue s(3);
	s.push(5);
	s.push(8);
	s.push(9);
	s.push(7);
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
}

//链表队列

/*class Node
{
public:
	int node;
	Node * next;
	Node(int n)
	{
		node = n;
	}
	Node(Node &n)
	{
		node = n.node;
	}
};
class Queue
{
private:
	int size;	
public:
	 Node *top;
	 int num;
	Queue(int s)
	{
		size = s;
		top = NULL;
		num = -1;
	}
	
	~Queue()
	{
		delete [] top;
	}
	void push(Node &d);
	Node pop();
	int isEmpty();
};

int Queue::isEmpty()
{
	if( num == -1)
		return 0;
	else 
		return 1;
}

void Queue::push(Node &n)
{
	if(num == size-1)return;
	if(top == NULL)
	{
		top = &n;
		top->next = NULL;
		cout<<top->node;
	}		
	else
	{
	n.next = top;
	top = &n;
	}
	num++;
}

Node Queue::pop()
{
	if(isEmpty() == 0)
		return NULL;
	num--;
	for(Node * n = top;n->next != NULL; n = n->next);
	Node temp(*n);
	delete n;
	return temp;
}

void main()
{
	Node node1(5);
	Node node2(8);
	Node node3(9);
	Node node4(3);
	Queue s(3);
	s.push(node1);
	//s.push(node2);
	//s.push(node3);
	//cout<<s.pop().node<<" "<<s.pop().node<<" "<<s.pop().node<<endl;
}*/