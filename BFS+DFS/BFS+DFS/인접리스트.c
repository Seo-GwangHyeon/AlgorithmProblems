#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES 20
#define QUEUE_SIZE 100
#define EMPTY -1
#define StackSize 100
typedef struct graph
{
	int node;
	struct graph *link;
} list;

list *adj_list[MAX_VERTICES];
int n;	    	// 그래프의 정점 갯수
int *visited = NULL;

void read_graph_list(char *file_name);
void add_edge(int v1, int v2);
void write_graph_list(void);
void BFS(int i);
void DFS(int i);

//큐관련 변수와 함수
int queue[QUEUE_SIZE];
int front;
int rear;

int isEmpty();
void push(int item);
void pop();
int getFront();
void queueInit();

//스택 관련 함수

int top = 0;
int s[StackSize];

void StackInit()
{
	top = 0;
	for (int i = 0; i < StackSize; i++)
	{
		s[i] = 0;
	}
}

void Stackpush(int d)
{
	s[top] = d;
	top++;
}

void Stackpop()
{
	if (top == 0) { printf("empty\n"); }
	else {
		s[top] = 0;
		top--;
	}
}
int getTop()
{
	return s[top-1];
}

FILE *fout;
int main(void)
{
	fout = fopen("result_adjlist.out", "w");

	read_graph_list("data_adjlist.in");
	fprintf(fout,"\n\n그래프 인접리스트 표현 \n");
	write_graph_list();
	fprintf(fout,"BFS\n");
	for (int i = 0; i < n; i++)
	{
		BFS(i);
		queueInit();
		fprintf(fout,"\n");
	}
	fprintf(fout,"DFS\n");
	for (int i = 0; i < n; i++)
	{
		DFS(i);
		StackInit();
		fprintf(fout,"\n");
	}
	return 0;
}


// 그래프 입력: 인접리스트 표현 
void read_graph_list(char *file_name)
{
	int i,  edges, v1, v2;

	FILE *fp = fopen(file_name, "r");
	if (fp == NULL) return;
	fscanf(fp, "%d\n", &n);
	fscanf(fp, "%d\n", &edges);

	for (i = 0; i<n; i++)
		adj_list[i] = NULL;

	for (i = 0; i<edges; i++) {
		fscanf(fp, "%d %d", &v1, &v2);
		add_edge(v1, v2);
	}
	fclose(fp);
	return;
}

// 그래프의 인접리스트 표현에 간선 추가한다.
void add_edge(int v1, int v2)
{
	list *temp;

	temp = (list *)malloc(sizeof(list));
	temp->node = v2;
	temp->link = adj_list[v1];
	adj_list[v1] = temp;

	temp = (list *)malloc(sizeof(list));
	temp->node = v1;
	temp->link = adj_list[v2];
	adj_list[v2] = temp;

	return;
}

// 그래프 출력 : 인접행렬 표현 
void write_graph_list(void)
{
	int i;
	list *c;

	fprintf(fout,"\n그래프의 정점갯수 : %d \n", n);
	fprintf(fout,"그래프의 인접리스트 표현\n");

	for (i = 0; i<n; i++) {
		c = adj_list[i];
		fprintf(fout,"정점 %d의 인접점 리스트 adj_list[%d] ", i, i);
		while (c != NULL) {
			fprintf(fout," -> %d", c->node);
			c = c->link;
		}
		fprintf(fout,"\n");
	}
	return;
}


void BFS(int i) {
	visited = malloc(sizeof(int)*n);
	int counter = 0;
	for (int m = 0; m < n; m++)
	{
		visited[m] = 0;
	}
	visited[i] = 1;
	push(i);
	fprintf(fout,"%d -> ",i);
	counter++;
	while (!isEmpty())
	{
		i = getFront();
		list *aa = adj_list[i];
		pop();
		for (; aa != NULL; aa = aa->link)
		{
			if (!visited[aa->node])
			{
				push(aa->node);
				visited[aa->node] = 1;
				fprintf(fout,"%d ", aa->node);
				counter++;
				if(counter<n)
					fprintf(fout,"-> ");
			}
		}
	}
}

void DFS(int i) {
	visited = malloc(sizeof(int)*n);
	for (int m = 0; m < n; m++)
	{
		visited[m] = 0;
	}
	int counter = 0;
	visited[i] = 1;
	Stackpush(i);
	fprintf(fout,"%d -> ",i);
	counter++;
	i = getTop();
	list* aa = adj_list[i];
	while (top != 0)
	{
		
		while (aa != NULL)
		{
			if (visited[aa->node]==0)
			{
				Stackpush(aa->node);
				visited[aa->node] = 1;
				fprintf(fout,"%d ", aa->node);
				counter++;
				if (counter < n)
					fprintf(fout,"-> ");
				i = getTop();
				aa = adj_list[i];
			}
			else
			{
				aa = aa->link;
			}
		}
		Stackpop();
		i = getTop();
		aa = adj_list[i];
	}
}
void queueInit()
{
	memset(queue, EMPTY, sizeof(int)*QUEUE_SIZE);
	front = 0;
	rear = 0;
}

int isEmpty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}
void push(int item)
{
	rear = (rear + 1) % QUEUE_SIZE;
	queue[rear] = item;
}
void pop()
{
	if (isEmpty())
	{

	}
	front = (front + 1) % QUEUE_SIZE;
	queue[front] = EMPTY;
}
int getFront()
{
	return front;
	//return queue[ (front + 1 ) % QUEUE_SIZE ];
}
