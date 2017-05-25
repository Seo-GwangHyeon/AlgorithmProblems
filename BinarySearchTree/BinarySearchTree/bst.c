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

(5) level_order() : ������ȸ ������� ��M�� ���Ҹ� ����Ѵ�.

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

void insert(struct node *tree,int id);
void delete(id);
int count();
int height();
void level_order();
void ancestor(id);
int min_order(id);
void near(id);
void quit();

void init(struct node *tree,int id);


int main()
{
	static struct node *aa = NULL;
	int arr1[] = { 2,1,7,8,6,3,5,4 };
	for (int i = 0; i < 8; i++)
	{
		printf("*****%d*****\n", arr1[i]);
		_getch();
		insert(aa, arr1[i]);
		if (aa == NULL)
		{
			puts("���̸� �Ӵ�..");
		}
	}
	printf("\n\n%d\n", aa->data);
	return 0; 
}


void insert(struct node* tree,int id)
{
	if (tree == NULL)
	{
		printf("NULL�Դϴ�");
		_getch();
		tree = (struct node*)malloc(sizeof(struct node));
		tree->data = id;
		tree->right = NULL;
		tree->left = NULL;
		printf("%d   ", tree->data);
	//	_getch();
		return;
	}
	else
	{
		printf("else ����\n");

		if (tree->data > id)
		{//id�� ������ ��� �������� ������
			printf("���� id : %d\n", id);
			printf("��尪 : %d\n", tree->data);
			insert(tree->left,id);
			return;
		}
		else if (tree->data < id)
		{//id �� �� ū��� ������ �ڽ�
			printf("���� id : %d\n", id);
			printf("��尪 : %d\n", tree->data);
			insert(tree->right, id);
			return;
		}
		else
		{//error message re typing
			printf("���� �߻� �ӽ÷� \n");
		}
	}
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

