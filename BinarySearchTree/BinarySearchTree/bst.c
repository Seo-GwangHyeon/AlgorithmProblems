// Binary Search Tree �� data�� ��ϴ� �ý���

/*
1. Binary Search Tree(BST)�� �̿��� data�����ϴ� program

2. Data�� 0���� ū ���� (1~100 ������ ��) �̸�, ����ü�� Linked List�� ����Ѵ�.


3. �����

(1) insert(id) : Data�� �о BST�� �����Ѵ�. ���� data������ ���ٰ� �����Ѵ�.
(�Է°��� �߸� ������ error message�� ����ϰ� �ٽ� �Է¹޴´�.

(2) delete(id) : id ���� �����Ѵ�. id ���� ���� ��� ���ٰ� ����Ѵ�.
(�ڽ��� ���� ��� ���� subtree���� ���� ū ���ҿ� ��ġ�Ѵ�)

(3) count() : ������ ������ ����Ѵ�.

(4) height() : BST�� ���̸� ����Ѵ�.

(5) level_order() : ������ȸ ������� �湮�� ���Ҹ� ����Ѵ�.

(6) ancestor(id) : ������ ���� node���� ����Ѵ�.

(7) Terminal(): �ܸ� node�� ������ ����Ѵ�.

(8) min_order(id) : id ���� ���� ���Ұ� ���°�� ���� �������� ����Ѵ�.
���Ұ� ���� ��쿡�� 0�� ����Ѵ�.

(9) near(id) : id ���� BST�� ���� ���̸�, ����ϴ� ���Ҵ� id ���� ���� ���̰� ���� ���Ҹ� ����Ѵ�.
���� ���� ���� ���� ���� ���� ���Ҹ� ����Ѵ�.

(10) quit() : program�� ������.

*/
#include <stdio.h>

struct node
{
	int data;
	struct node *right;
	struct node	*left;
};

void insert(struct node *tree, int id);
void delete(id);
int count();
int height();
void level_order();
void ancestor(id);
int min_order(id);
void near(id);
void quit();

void init(struct node *tree, int id);


int main()
{
	
	int arr1[] = { 2,1,7,8,6,3,5,4 };
	
	return 0;
}

void insert(struct node* tree, int id)
{
	
}

void init(struct node *tree, int id)
{

}

void delete(id)
{

}
int count()
{
	return 0;
}
int height()
{
	return 0;
}
void level_order()
{

}
void ancestor(id)
{

}
int min_order(id)
{
	return 0;
}
void near(id)
{

}
void quit()
{

}
