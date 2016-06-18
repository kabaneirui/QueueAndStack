#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include <deque>

using namespace std;


template < class T, class Sequence = deque<T> >

class queue 
{
	friend bool operator== __STL_NULL_TMPL_ARGS (const queue& x, const queue& y );
	friend bool operator< __STL_NULL_TMPL_ARGS (const queue<T, Sequence>& x, const queue<T, Sequence>& y);
	//以下的__STL_NULL_TMPL_ARGS会展开为 <>
public:
	typedef typename Sequence::value_type value_type;
	typedef typename Sequence::size_type size_type;
	typedef typename Sequence::reference reference;
	typedef typename Sequence::const_reference const_reference;
protected:
	Sequence c;
public:
	//以下完全利用 Sequence c 的操作，完成queue的操作
	bool empty() const { return c.empty(); }
	size_type size() const { return c.size(); }
	reference front() { return c.front(); }
	const_reference front() const { return c.front(); }
	reference back() { return c.back(); }
	const_reference back() const { return c.back(); }
	//deque是两头可进可出，queue是末端进，前端出（所以先进者先出）
	void push (const value_type& x) { c.push_back(); }
	void pop() { c.pop_front(); } 
};

template <class T, class Sequence>

bool operator==(const queue< T, Sequence >& x, const queue<T, Sequence>& y )
{
	return x.c == y.c;
}

template <class T, class Sequence >

bool operator<(const queue<T, Sequence>& x, const queue<T, Sequence>& y)
{
	return x.c < y.c;
}

//用list做底层容器
int main()
{
	queue<int, list<int> > iqueue;
	iqueue.push(1);
	iqueue.push(3);
	iqueue.push(5);
	iqueue.push(7);

	cout<< iqueue.size() <<endl;	//4
	cout<< iqueue.front() <<endl;	//1
	
	iqueue.pop(); cout << iqueue.front() <<endl;	//3
	iqueue.pop(); cout << iqueue.front() <<endl;	//5
	iqueue.pop(); cout << iqueue.front() <<endl;	//7
	cout<< iqueue.size() << endl;	//1

	return 0;
}

/*
//数组队列

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
*/
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