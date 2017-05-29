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
		{//비교하며 탐색
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
	{//빈 트리면 바로 new_node를 추가한다.
		*t = new_node;
		return;
	}

	// find the position that new node will be inserted.
	while (temp != NULL)
	{
		new_node->parent = temp;//new_node가 parent를 가리키도록한다.
		//
		if (temp->id > id)//id는 new_node의 id이다
		{//현재id가 작으면 left child로 이동
			temp = temp->left;
		}
		else
		{//현재id가 크면 right child로 이동
			temp = temp->right;
		}
	}

	//parent가 new_node를 가리키도록한다
	if ((new_node->parent)->id > id)
	{//현재id가 작으면 left child
		(new_node->parent)->left = new_node;//temp->left
	}
	else
	{//현재id가 크면 right child
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
		printf("해당 id 없음\n");
		return;
	}

	// 삭제할노드가 자식이 없는경우
	if (temp->left == NULL && temp->right == NULL)
	{
		if (temp == *t)
		{//루트 1개인 트리인경우
			*t = NULL;
		}
		else if ((temp->parent)->id > id)
		{//left child일경우
			(temp->parent)->left = NULL;
		}
		else
		{//right child일경우 
			(temp->parent)->right = NULL;
		}
		free(temp);
	}

	else if (temp->left == NULL)
	{//right child가 존재하는경우
		temp->id = (temp->right)->id;
		//right child를 del_node에 넣고 right child를 지운다
		delete(&(temp->right), (temp->right)->id);
	}
	
	else if (temp->right == NULL)
	{//left child가 존재하는경우
		temp->id = (temp->left)->id;
		//left child를 del_node에 넣고 left child를 지운다
		delete(&(temp->left), (temp->left)->id);
	}
	else
	{//2개의 child를 가지고 있는경우
		del_node = temp;

		temp = temp->right;
		//right child중에
		while (temp->left != NULL)
		{//right child중에 가장 작은값을 찾는다.
			temp = temp->left;
		}

		del_node->id = temp->id;
		//삭제하려는 노드에 ight child중에 가장 작은값 을 대입한다.
		delete(&(del_node->right), temp->id);//그리고 원래위치에 값을 제거한다.
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