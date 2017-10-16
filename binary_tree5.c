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

//计算二叉树深度(递归)
int   get_binary_tree_deep(binary_tree_node * root)
{
	 if(root==NULL)
	 	return 0;
	 int l_deep=get_binary_tree_deep(root->lchild);
	 int r_deep=get_binary_tree_deep(root->rchild);
	 return l_deep>r_deep?l_deep+1:r_deep+1;
}
//张建用非递归实现深度计算


int main(int argc, char const *argv[])
{
	binary_tree_node* root=init_binary_tree();
	int deep=get_binary_tree_deep(root);
	printf("%d\n",deep);
	printf("\n");
	return 0;
}