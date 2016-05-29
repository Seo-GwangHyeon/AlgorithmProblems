//연결리스트로 만드는 스택

#include <iostream>
using namespace std;

template <class T>
class LinkedStackNode;

template <class T>
class LinkedStack//연결리스트 스택 클래스
{
	friend class LinkedStackNode<T>;
private:
	LinkedStackNode<T> *top;//탑 원소 first 원소가 된다.
public:
	LinkedStack<T>()
	{
		top = NULL;//처음 탑 값 NULL
	}
	void Push(T pushll);
	void Pop();
	bool IsEmpty();
	void Print();
};

template <class T>//탬플릿
class LinkedStackNode//연결리스트 스택 노드 클래스
{
	friend class LinkedStack<T>;
private:
	T data;//탬플릿을 이용한 데이터
	LinkedStackNode<T> *link;//다음 원소
	LinkedStackNode(T data, LinkedStackNode<T> *link)//생성자 다음 노드와 데이터를 받음
	{
		this->data = data;
		this->link = link;
	}
};
