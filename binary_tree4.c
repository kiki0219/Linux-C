#include <stdio.h>
#include <stdlib.h>
/*
二叉树广度遍历
*/
//定义二叉树节点
typedef struct  binary_tree_node
{
 	char  value;
 	struct binary_tree_node * rchild;
 	struct binary_tree_node * lchild;
}binary_tree_node;


//定义队列节点
typedef struct queue_node
{
	binary_tree_node * ptr_tree_node;//存储树节点地址
	struct queue_node * next;
}queue_node;

//定义队列
typedef struct queue
{
	queue_node* head;
	queue_node* tail;
}queue;
/*--------队列操作-------------------------*/
void  init_queue(queue * qu)
{
	qu->head=qu->tail=NULL;
}
void push(queue * qu,binary_tree_node * ptr_tree_node)
{
	queue_node  * new_queue_node=(queue_node  *)malloc(1*sizeof(queue_node));
	if(new_queue_node==NULL)
	{
		printf("mallo fail\n");
		exit(-1);
	}
	new_queue_node->ptr_tree_node=ptr_tree_node;
	new_queue_node->next=NULL;

	if(qu->head==NULL)
	{
		qu->head=new_queue_node;
		qu->tail=new_queue_node;
	}
	else
	{
		qu->tail->next=new_queue_node;
		qu->tail=new_queue_node;
	}
	new_queue_node=NULL;
}

int is_empty(queue * qu)
{
	if(qu->head==NULL && qu->tail==NULL)
		return 1;
	return 0;
}

void pop(queue * qu)
{
	if(!is_empty(qu))
	{
		queue_node * ptr_tmp_node=qu->head;
		qu->head=qu->head->next;
		if(qu->head==NULL)
		{
			qu->tail=NULL;
		}
		free(ptr_tmp_node);
		ptr_tmp_node=NULL;
	}
}

binary_tree_node *   get_stack_top(queue * qu)
{
	if(!is_empty(qu))
	{
		return qu->head->ptr_tree_node;
	}
	return NULL;
}

/*--------队列操作-------------------------*/
//构件二叉树(键盘输入二叉树节点值)

binary_tree_node*  init_binary_tree()
{
	char value;
	scanf("%c",&value);
	getchar();//清空输入缓存(输出是char)
	if(value=='n')
    {
    	return NULL;
    }
    else
    {
    	binary_tree_node  * root=(binary_tree_node*)malloc(1*sizeof(binary_tree_node));
	    root->value=value;
	    root->lchild=init_binary_tree();
	    root->rchild=init_binary_tree();
	    return root;
    }	    
}

//广度遍历二叉树
void   print_binary_tree1(binary_tree_node * root)
{
	queue qu;
	init_queue(&qu);
	while(root!=NULL)
	{
		printf("%c\t",root->value);

		if(root->lchild!=NULL)
		{
			push(&qu,root->lchild);
		}
		if(root->rchild!=NULL)
		{
			push(&qu,root->rchild);
		}				
		root=get_stack_top(&qu);
		pop(&qu);
	}
}
int main(int argc, char const *argv[])
{
	binary_tree_node* root=init_binary_tree();
	print_binary_tree1(root);
	printf("\n");
	return 0;
}