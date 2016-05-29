//연결리스트로 만드는 스택

#include <iostream>
using namespace std;

template <class T>
class LinkedNode;

template <class T>
class LinkedStack//연결리스트 스택 클래스
{
	friend class LinkedNode<T>;
private:
	LinkedNode<T> *top;//탑 원소 first 원소가 된다.
public:
	LinkedStack<T>()
	{
		top = NULL;//처음 탑 값 NULL
	}
	void Push(T pushll);
	void Pop() ;
	bool IsEmpty() const;
	void Print() const;
};
//----------------------------------------------------------
template <class T>
class LinkedQueue//연결리스트 큐 클래스
{
	friend class LinkedNode<T>;
private:
	LinkedNode<T> *front;
	LinkedNode<T> *rear;
public:
	LinkedQueue<T>()
	{
		this->front = new LinkedNode<T>(0, NULL);
		front->link = this->rear;
	}
	void Push(T pushll);
	void Pop();
	bool IsEmpty() const;
	void Print() const;
};

template <class T>//탬플릿
class LinkedNode//연결리스트 스택 노드 클래스
{
	friend class LinkedStack<T>;
	friend class LinkedQueue<T>;
private:
	T data;//탬플릿을 이용한 데이터
	LinkedNode<T> *link;//다음 원소
	LinkedNode(T data, LinkedNode<T> *link)//생성자 다음 노드와 데이터를 받음
	{
		this->data = data;
		this->link = link;
	}
};
