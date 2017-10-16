#include <stdio.h>
#include <stdlib.h>
/*
树(tree):
树是一种递归定义:
1.n(n>=0)个互不相交节点
2.必定只存一个根节点
3.除开根节点,n-1(n>0)个节点组成子树
树=根节点+子树

二叉树:如果节点存在子节点,子节点数不能超过2
二叉树名词:
1.叶子节点(终端节点):没有子节点
2.子节点:既有父节点又有子节点
3.节点度:存在字节点个数(<=2)
4.树度:最大节点度
5.左节点:左孩子
6.右节点:右孩子
7.树广度:最大树度
8.树深度:树最大层次数

空树也是一个特殊二叉树

如果存在n(n>=0)个节点,树最小深度为:log2 n+1
如果存在一个深度为k 二叉树,其终端节点树为: 2^(k-1)  总结点数为:2^k-1


满二叉树:除开终端节点没有子节点,其它都有2个子节点
完全二叉树:存在字节点只有一个孩子节点,此孩子节点必须是左孩子

遍历二叉树方式:
1.前序遍历:根 左 右
2.中序遍历:左 根  右
3.后续遍历:左 右 根
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

//递归前序输出
void  print_binary_tree1(binary_tree_node*  root)
{
	if(root!=NULL)
	{
		printf("%c\t",root->value);
		print_binary_tree1(root->lchild);
		print_binary_tree1(root->rchild);
	}
}

//递归中序输出
void  print_binary_tree2(binary_tree_node*  root)
{
	if(root!=NULL)
	{
		print_binary_tree2(root->lchild);
		printf("%c\t",root->value);
		print_binary_tree2(root->rchild);
	}
}
//递归后序输出
void  print_binary_tree3(binary_tree_node*  root)
{
	if(root!=NULL)
	{
		print_binary_tree3(root->lchild);
		print_binary_tree3(root->rchild);
		printf("%c\t",root->value);		
	}
}


int main(int argc, char const *argv[])
{
	binary_tree_node*  root= init_binary_tree();
	print_binary_tree1(root);
	printf("\n");
	print_binary_tree2(root);
	printf("\n");
	print_binary_tree3(root);
	printf("\n");
	return 0;
}