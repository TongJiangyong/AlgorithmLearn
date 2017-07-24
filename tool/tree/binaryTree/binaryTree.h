#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>

using namespace std;

template <class T>
class BinaryTree;
//二叉树和树的根本区别是：
//• 二叉树可以为空，但树不能为空。
//• 二叉树中每个元素都恰好有两棵子树（其中一个或两个可能为空）。而树中每个元素可有
//若干子树。
//• 在二叉树中每个元素的子树都是有序的，也就是说，可以用左、右子树来区别。而树的
//子树间是无序的。

//二叉树的每一层都是一个深度
//
//二叉树的基本特性：
/**
特性1 包含n (n> 0 )个元素的二叉树边数为n-1。

特性2 若二叉树的高度为h， h≥0，则该二叉树最少有h个元素，最多有2h - 1个元素。高度即为深度

特性3 包含n 个元素的二叉树的高度最大为n，最小为[ l o g2 (n+ 1 )]。

特别的二叉树
满二叉树
当高度为h 的二叉树恰好有2h - 1个元素时，称其为满二叉树（ full binary tree）。

完全二叉树

假设对高度为 h 的满二叉树中的元素按从第上到下，从左到右的顺序从 1到2h- 1进行编号
（如图8 - 6所示）。假设从满二叉树中删除 k个元素，其编号为 2h -i, 1≤i≤k，所得到的二叉树被
称为完全二叉树（ complete binary tree）
只有最下的两层结点能小于2，并且最下面一层的结点，都集中在该层的最左边
通常用数组来处理完全二叉树

特性4 设完全二叉树中一元素的序号为i, 1≤i≤n。则有以下关系成立：
1) 当i = 1时，该元素为二叉树的根。若i > 1，则该元素父节点的编号为[i / 2]。
2) 当2i >n时，该元素无左孩子。否则，其左孩子的编号为 2i。
3) 若2i + 1 >n，该元素无右孩子。否则，其右孩子编号为 2i + 1。

形象上看，完全二叉树的特点是，只有最后两层有空缺，而且最后一层上，只能缺少右边的若干结点
结构特性上看： 是一个数据上有特性的二叉树，具体特性见分析即可

二叉树通常使用链表和指针来进行描述：
包括一个leftChild和rightChild


二叉树的常用操作为：
• 确定其高度。
• 确定其元素数目。
• 复制。
• 在屏幕或纸上显示二叉树。
• 确定两棵二叉树是否一样。
• 删除整棵树。
• 若为数学表达式树，计算该数学表达式。
• 若为数学表达式树，给出对应的带括号的表达式

以上操作都可以通过遍历二叉树来完成.....

在二叉树的表示中，这里用指针，来表示所有的二叉树.....
**/

//这里使用的技巧非常巧妙，使用化繁为简的方法，让makeTree变成简单的数据结构组合即可
template <class T>
class BinaryTreeNode {
     friend class BinaryTree<T>;
     void InOrder(BinaryTreeNode<T> *);  //中序遍历
     void PreOrder(BinaryTreeNode<T> *); //前序遍历
     void PostOrder(BinaryTreeNode<T> *); //后序遍历
     void LevelOrder(BinaryTreeNode<T> *);  //逐层遍历
     void Output(ostream& out) const;
public:
    void Visit(BinaryTreeNode<T> *);
    //这里定义了三个初始化函数即可
    BinaryTreeNode() {LeftChild = RightChild = 0;}
    BinaryTreeNode(const T& e){data = e;LeftChild = RightChild = 0;}
    BinaryTreeNode(const T& e, BinaryTreeNode *l,BinaryTreeNode *r)
    {
        data = e;
        LeftChild = l;
        RightChild = r;
    }
private:
    T data;
    BinaryTreeNode<T> *LeftChild; //左子树
    BinaryTreeNode<T> *RightChild; // 右子树
} ;


template<class T>
class BinaryTree {
public :
    BinaryTree( ) {root = 0; };
    ~BinaryTree( ) {};
    bool IsEmpty( ) const
    {reurn ((root) ? false : true);}
    bool Root(T& x) const; //取x为根节点；如果操作失败，则返回 f a l s e，否则返回 t r u e
    void MakeTree(const T& element,BinaryTree<T>& left, BinaryTree<T>& right);  //创建一个二叉树， ro o t作为根节点， l e f t作为左子树， r i g h t作为右子树
    void BreakTree(T& element,BinaryTree<T>& left , BinaryTree<T>& right);     //拆分二叉树
    //这里的visit是一个函数指针形参，你在调用QueueTraverse这个函数时第二个参数需要传入对应的函数
    //即这里的visit表示PreOrder函数的一个参数，预备调用这个函数即可
    //函数visit作为遍历函数的参数
    void PreOrder(void(*Visit)(BinaryTreeNode<T> *u))
    {
        PreOrder(Visit,root);
    }
    void InOrder(void (*Visit)(BinaryTreeNode<T> *u))
    {
         InOrder(Visit,root) ;
    }
    void PostOrder(void(*Visit )(BinaryTreeNode<T> *u))
    {
        PostOrder (Visit, root);
    }
    void LevelOrder(void(*Visit) (BinaryTreeNode<T> *u)){
        LevelOrder (Visit, root);
    };
    BinaryTreeNode<T> * GetRoot(){
        return root;
    }
private:
    BinaryTreeNode<T> *root; // 根节点指针
    void PreOrder (void (*Visit) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
    void InOrder(void(*Visit) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
    void PostOrder(void (*Visit) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
    void LevelOrder(void (*Visit) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
} ;



#include"binaryTree.cpp"
#endif // BINARYTREE_H

