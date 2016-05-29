//���Ḯ��Ʈ�� ����� ����

#include <iostream>
using namespace std;

template <class T>
class LinkedStackNode;

template <class T>
class LinkedStack//���Ḯ��Ʈ ���� Ŭ����
{
	friend class LinkedStackNode<T>;
private:
	LinkedStackNode<T> *top;//ž ���� first ���Ұ� �ȴ�.
public:
	LinkedStack<T>()
	{
		top = NULL;//ó�� ž �� NULL
	}
	void Push(T pushll);
	void Pop();
	bool IsEmpty();
	void Print();
};

template <class T>//���ø�
class LinkedStackNode//���Ḯ��Ʈ ���� ��� Ŭ����
{
	friend class LinkedStack<T>;
private:
	T data;//���ø��� �̿��� ������
	LinkedStackNode<T> *link;//���� ����
	LinkedStackNode(T data, LinkedStackNode<T> *link)//������ ���� ���� �����͸� ����
	{
		this->data = data;
		this->link = link;
	}
};
