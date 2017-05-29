#include <stdio.h>
#include <malloc.h>

#define MAX 100

typedef struct node {
	int id;
	struct node *left;
	struct node *right;
	struct node *parent;//parent
}NODE;

NODE* search(NODE *, int);
void insert(NODE **, int);
void delete(NODE **, int);
void display_node(NODE *);
void display_level(NODE *);
int main(void)
{
	NODE *root = NULL;
	int select = 0;
	int temp_insert = 0, temp_delete = 0;
	while (1)
	{
		printf("1) insert\n");
		printf("2) delete\n");
		printf("3) display(DFS)\n : ");
		scanf("%d", &select);
		if (select == 1)
		{
			scanf("%d", &temp_insert);
			insert(&root, temp_insert);
		}
		else if (select == 2)
		{
			scanf("%d", &temp_delete);
			delete(&root, temp_delete);
		}
		else if (select == 3)
		{
			display_node(root);
			_getch();
		}
		else
		{
			break;
		}
	}
	/*insert(&root, 50);
	insert(&root, 30);
	insert(&root, 70);
	insert(&root, 25);
	insert(&root, 40);
	insert(&root, 60);
	insert(&root, 80);
	insert(&root, 15);
	insert(&root, 35);
	insert(&root, 45);

	delete(&root, 30);
	delete(&root, 50);

	display_node(root);*/
	return 0;
}

NODE* search(NODE *t, int id)
{
	while (t != NULL && t->id != id)
	{
		if (t->id > id)
		{//���ϸ� Ž��
			t = t->left;
		}
		else
		{
			t = t->right;
		}
	}

	return t;
}


void insert(NODE **t, int id)
{
	NODE *new_node = (NODE *)malloc(sizeof(NODE));
	NODE *temp = *t; // temporary node.

	new_node->id = id;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	// if there is not any node.
	if (temp == NULL)
	{//�� Ʈ���� �ٷ� new_node�� �߰��Ѵ�.
		*t = new_node;
		return;
	}

	// find the position that new node will be inserted.
	while (temp != NULL)
	{
		new_node->parent = temp;//new_node�� parent�� ����Ű�����Ѵ�.
		//
		if (temp->id > id)//id�� new_node�� id�̴�
		{//����id�� ������ left child�� �̵�
			temp = temp->left;
		}
		else
		{//����id�� ũ�� right child�� �̵�
			temp = temp->right;
		}
	}

	//parent�� new_node�� ����Ű�����Ѵ�
	if ((new_node->parent)->id > id)
	{//����id�� ������ left child
		(new_node->parent)->left = new_node;//temp->left
	}
	else
	{//����id�� ũ�� right child
		(new_node->parent)->right = new_node;//temp->right
	}
}

void delete(NODE **t, int id)
{
	NODE *temp = NULL;
	NODE *del_node = NULL;

	temp = search(*t, id);

	// if there is not id.
	if (temp == NULL)
	{
		printf("�ش� id ����\n");
		return;
	}

	// �����ҳ�尡 �ڽ��� ���°��
	if (temp->left == NULL && temp->right == NULL)
	{
		if (temp == *t)
		{//��Ʈ 1���� Ʈ���ΰ��
			*t = NULL;
		}
		else if ((temp->parent)->id > id)
		{//left child�ϰ��
			(temp->parent)->left = NULL;
		}
		else
		{//right child�ϰ�� 
			(temp->parent)->right = NULL;
		}
		free(temp);
	}

	else if (temp->left == NULL)
	{//right child�� �����ϴ°��
		temp->id = (temp->right)->id;
		//right child�� del_node�� �ְ� right child�� �����
		delete(&(temp->right), (temp->right)->id);
	}
	
	else if (temp->right == NULL)
	{//left child�� �����ϴ°��
		temp->id = (temp->left)->id;
		//left child�� del_node�� �ְ� left child�� �����
		delete(&(temp->left), (temp->left)->id);
	}
	else
	{//2���� child�� ������ �ִ°��
		del_node = temp;

		temp = temp->right;
		//right child�߿�
		while (temp->left != NULL)
		{//right child�߿� ���� �������� ã�´�.
			temp = temp->left;
		}

		del_node->id = temp->id;
		//�����Ϸ��� ��忡 ight child�߿� ���� ������ �� �����Ѵ�.
		delete(&(del_node->right), temp->id);//�׸��� ������ġ�� ���� �����Ѵ�.
	}
}
void display_level(NODE *t)
{
	NODE *queue = NULL;
	if (t == NULL)
	{
		return;
	}

}

void display_node(NODE *t)
{
	if (t == NULL)
	{
		return;
	}

	printf("NODE [%d] > ", t->id);

	if (t->left != NULL)
	{
		printf("LEFT [%d] ", (t->left)->id);
	}
	if (t->right != NULL)
	{
		printf("RIGHT [%d]", (t->right)->id);
	}
	printf("\n");

	if (t->left)
	{
		display_node(t->left);
	}
	if (t->right)
	{
		display_node(t->right);
	}
}