//���Ḯ��Ʈ�� ����� ����

#include <iostream>
using namespace std;

template <class T>
class LinkedNode;

template <class T>
class LinkedStack//���Ḯ��Ʈ ���� Ŭ����
{
	friend class LinkedNode<T>;
private:
	LinkedNode<T> *top;//ž ���� first ���Ұ� �ȴ�.
public:
	LinkedStack<T>()
	{
		top = NULL;//ó�� ž �� NULL
	}
	void Push(T pushll);
	void Pop() ;
	bool IsEmpty() const;
	void Print() const;
};
//----------------------------------------------------------
template <class T>
class LinkedQueue//���Ḯ��Ʈ ť Ŭ����
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

template <class T>//���ø�
class LinkedNode//���Ḯ��Ʈ ���� ��� Ŭ����
{
	friend class LinkedStack<T>;
	friend class LinkedQueue<T>;
private:
	T data;//���ø��� �̿��� ������
	LinkedNode<T> *link;//���� ����
	LinkedNode(T data, LinkedNode<T> *link)//������ ���� ���� �����͸� ����
	{
		this->data = data;
		this->link = link;
	}
};
