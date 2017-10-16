#include <stdio.h>
#include <stdlib.h>
/*
查找二叉树:是一个有序二叉树,根 左 右节点存在大小顺序:
1.根节点大于所有左孩子节点
2.根节点小于所有右孩子节点
构造查找树时,避免出现全是左孩子或右孩子(链表).一般查找时间复杂度(O(logn))
AVL 平衡二叉树:是一个特殊查找二叉树,主要任何一个根节点,左右孩子深度相差<=1
*/
//定义二叉树节点
typedef struct  binary_tree_node
{
 	int  value;
 	struct binary_tree_node * rchild;
 	struct binary_tree_node * lchild;
}binary_tree_node;


//为了避免出现全是左孩子或右孩子,计算目标数平均值作为树的根节点
int  get_array_avg(int *a,int len)
{
	int sum=0;
	int i;
	for(i=0;i<len;i++)
	{
		sum+=a[i];
	}
	return sum/len;
}

//构造树节点
binary_tree_node * create_sort_binary_tree_node(int value)
{
	binary_tree_node *  ptr_new_node=(binary_tree_node *)malloc(1*sizeof(binary_tree_node));
	if(ptr_new_node==NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ptr_new_node->value=value;
	ptr_new_node->lchild=NULL;
	ptr_new_node->rchild=NULL;
	return ptr_new_node;
}

//创建查找二叉树
binary_tree_node *  create_sort_binary_tree(binary_tree_node * root,int value)
{
    if(root->value>value && root->lchild==NULL)
    {
        binary_tree_node * ptr_new_node=create_sort_binary_tree_node(value);
        root->lchild=ptr_new_node;
        ptr_new_node=NULL;
        return root;
    }
    if(root->value<value && root->rchild==NULL)
    {
    	binary_tree_node * ptr_new_node=create_sort_binary_tree_node(value);
        root->rchild=ptr_new_node;
        ptr_new_node=NULL;
        return root;
    }
    if(root->value>value &&  root->lchild!=NULL)
    {
    	create_sort_binary_tree(root->lchild,value);
    }
    if(root->value<value && root->rchild!=NULL)
    {
    	create_sort_binary_tree(root->rchild,value);
    }
}

//初始化查找二叉树
binary_tree_node *   init_sort_binary_tree(int *a,int len)
{
   int i;
   binary_tree_node * root=create_sort_binary_tree_node(get_array_avg(a,len));
   for(i=0;i<len;i++)
   {
		create_sort_binary_tree(root,a[i]);
   }
   return root;
}

//中序输出树
void  printf_binary_tree(binary_tree_node *  root,int value)
{
	if(root!=NULL)
	{
		printf_binary_tree(root->lchild,value);
		if(root->value!=value)
		{
			printf("%d\t",root->value);
		}		
		printf_binary_tree(root->rchild,value);
	}
}

int main(int argc, char const *argv[])
{
	int a[]={12,5,89,10,4,23,1,56};
	binary_tree_node * root=init_sort_binary_tree(a,8);
	printf_binary_tree(root,get_array_avg(a,8));
	printf("\n");
	return 0;
}

//堆排序(阳博)
//介绍:大堆/小堆  如何构建大堆/小堆
//haffman 树(哈夫曼树)