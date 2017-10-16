#include <stdio.h>
#include <stdlib.h>
//定义二叉树节点
typedef struct  binary_tree_node
{
 	char  value;
 	struct binary_tree_node * rchild;
 	struct binary_tree_node * lchild;
}binary_tree_node;


//定义栈(非递归必须使用栈)
typedef struct stack_node
{
	//binary_tree_node  tree_node;//复制树节点(值存储)
	binary_tree_node * ptr_tree_node;//存储树节点地址
	struct stack_node * next;
}stack_node;

//定义栈
typedef struct stack
{
	stack_node* top;
}stack;
/*--------栈操作-------------------------*/
void  init_stack(stack * st)
{
	st->top=NULL;
}
void push(stack * st,binary_tree_node * ptr_tree_node)
{
	stack_node  * new_stack_node=(stack_node  *)malloc(1*sizeof(stack_node));
	if(new_stack_node==NULL)
	{
		printf("mallo fail\n");
		exit(-1);
	}
	new_stack_node->ptr_tree_node=ptr_tree_node;
	new_stack_node->next=NULL;

	new_stack_node->next=st->top;
	st->top=new_stack_node;
}

int is_empty(stack * st)
{
	if(st->top==NULL)
		return 1;
	return 0;
}

void pop(stack * st)
{
	if(!is_empty(st))
	{
		stack_node * ptr_tmp_node=st->top;
		st->top=st->top->next;
		free(ptr_tmp_node);
		ptr_tmp_node=NULL;
	}
}

binary_tree_node *   get_stack_top(stack * st)
{
	if(!is_empty(st))
	{
		return st->top->ptr_tree_node;
	}
	return NULL;
}

/*--------栈操作-------------------------*/
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

//非递归实现二叉树前序遍历
void   print_binary_tree1(binary_tree_node*  root)
{
	stack  st;
	init_stack(&st);
    while(root!=NULL || !is_empty(&st))
    {
    	 while(root!=NULL)
    	{
    		push(&st,root);
	   	 	printf("%c\t",root->value);
	    	root=root->lchild;
    	}
    
    	if(!is_empty(&st))
    	{
    		root=get_stack_top(&st);
    		pop(&st);
    		root=root->rchild;
    	}	
    }   
}

//非递归实现二叉树前序中历
void   print_binary_tree2(binary_tree_node*  root)
{
	stack st;
	init_stack(&st);
    while(root!=NULL|| !is_empty(&st))
    {
    	while(root!=NULL)
	    {
	    	push(&st,root);
			root=root->lchild;
	    }
	    if(!is_empty(&st))
	    {
	    	root=get_stack_top(&st);
		    printf("%c\t",root->value);
		    pop(&st);
		    root=root->rchild;
	    }	
    }    
}
int main(int argc, char const *argv[])
{
	binary_tree_node* root=init_binary_tree();
	print_binary_tree1(root);
	printf("\n");
	print_binary_tree2(root);
	printf("\n");
	return 0;
}