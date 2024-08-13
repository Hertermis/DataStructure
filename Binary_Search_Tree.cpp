/*笔记：简单实现二叉搜索树(不重复)*/
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct TreeBSNode {
	ElemType val;		// 结点数据
	struct TreeBSNode* left, * right; // 左右孩子指针
}BSTreeNode, * BSTree;

//初始化二叉树
void InitBSTree(BSTree& T) {
	T = NULL;
}

//销毁二叉树
void DestroyBSTree(BSTree& T) {
	if (T) {
		DestroyBSTree(T->left);
		DestroyBSTree(T->right);
		delete T;
		T = NULL;
	}
}

//插入结点
void InsertNode(BSTree& T, ElemType x, TreeBSNode *parent=nullptr) {
	if(!T){
		TreeBSNode* p = new TreeBSNode;
		p->val = x;
		p->left = p->right = NULL;
		if (!parent) {
			T = p;
		}
		else {
			if (x < parent->val) {
				parent->left = p;
			}
			else {
				parent->right = p;
			}
		}
	}
	else {
		if (x == T->val) {
			return;
		}
		else if (x < T->val) {
			InsertNode(T->left, x, T);
		}
		else {
			InsertNode(T->right, x, T);
		}
	}
}

//最小值
ElemType FindMin(BSTree T) {
	if (!T) {
		return NULL;
	}
	while (T->left) {
		T = T->left;
	}
	return T->val;
}

//最大值
ElemType FindMax(BSTree T) {
	if (!T) {
		return NULL;
	}
	while (T->right) {
		T = T->right;
	}
	return T->val;
}

//删除值为x结点
void DeleteNode(BSTree& T, ElemType x,TreeBSNode* p=nullptr) {
	if(!T){
		return;
	}
	if(x<T->val){
		DeleteNode(T->left,x,T);
	}
	else if(x>T->val){
		DeleteNode(T->right,x,T);
	}
	else{
		if(T->right){
			int Rmin = FindMin(T->right);
			T->val = Rmin;
			DeleteNode(T->right,Rmin,T);
		}
		else if(T->left){
			int Lmax = FindMax(T->left);
			T->val = Lmax;
			DeleteNode(T->left,Lmax,T);
		}
		else{
			if(p->left==T){
				p->left = NULL;
			}
			else{
				p->right = NULL;
			}
			delete T;
		}
	}
}

//查找值为x的结点
TreeBSNode* FindBSNode(BSTree T, ElemType x) {
	if (!T) {
		return NULL;
	}
	if (x == T->val) {
		return T;
	}
	else if (x < T->val) {
		return FindBSNode(T->left, x);
	}
	else {
		return FindBSNode(T->right, x);
	}
}

//获取结点内容
ElemType GetElem(BSTree T) {
	return T->val;
}

//中序遍历
void InOrder_BST(BSTree T) {
	if (T) {
		InOrder_BST(T->left);
		cout << GetElem(T) << " ";
		InOrder_BST(T->right);
	}
}

//判空
bool isEmptyBST(BSTree T) {
	return T == NULL;
}

//获取树的深度
int GetBSTreeDepth(BSTree T) {
	if (!T) {
		return 0;
	}
	int ldepth = GetBSTreeDepth(T->left);
	int rdepth = GetBSTreeDepth(T->right);
	return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
}


//int main() {
//	BSTree T;
//	InitBSTree(T);
//	InsertNode(T, 5);
//	InsertNode(T, 3);
//	InsertNode(T, 7);
//	InsertNode(T, 2);
//	InsertNode(T, 4);
//	InsertNode(T, 6);
//	InsertNode(T, 8);
//	InOrder_BST(T);
//	cout << endl;
//	cout << "Min: " << FindMin(T) << endl;
//	cout << "Max: " << FindMax(T) << endl;
//	DeleteNode(T, 5);
//	InOrder_BST(T);
//	cout << endl;
//	cout << "Depth: " << GetBSTreeDepth(T) << endl;
//	DestroyBSTree(T);
//	return 0;
//}


