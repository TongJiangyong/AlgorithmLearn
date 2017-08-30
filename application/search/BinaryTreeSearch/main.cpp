#include <iostream>
#include <stdio.h>
#include "BinarySearch.h"
#define LOCAL
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )
using namespace std;
/**
二叉树查找法
二叉树的基本特征和使用：
http://www.cnblogs.com/yangecnu/p/Introduce-Binary-Search-Tree.html
　基本思想：二叉查找树是先对待查找的数据进行生成树，确保树的左分支的值小于右分支的值，然后在就行和每个节点的父节点比较大小，
查找最适合的范围。 这个算法的查找效率很高，但是如果使用这种查找方法要首先创建树。
即，先对查找的数据，进行处理后，再进行查找的动作.....

　　二叉查找树（BinarySearch Tree，也叫二叉搜索树，或称二叉排序树Binary Sort Tree）或者是一棵空树，或者是具有下列性质的二叉树：

　　1）若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；

　　2）若任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；

　　3）任意节点的左、右子树也分别为二叉查找树。

　　二叉查找树性质：对二叉查找树进行中序遍历，即可得到有序的数列。
即，二叉查找树的重要特征为：一个非常重要的特点的是它的中序遍历为递增序列

即，二叉查找树的性质为，反复比较，并创建新的节点为止......
**/

template <class T>

int getArrayLen(T& array)

{
    //数组作为参数传给函数时传的是指针而不是数组，传递的是数组的首地址
    //如果这里不是引用，则永远都是1，一定要注意即可....
    return (sizeof(array) / sizeof(array[0]));
}



static int arr[]= {1,5,4,3,2,6};


int main()
{
    int i, ilen;
    //1、模板类最好不要分离写
    //2、如果没有implement构造函数，那么这个代码，运行也会出问题
    BSTree<int>* tree=new BSTree<int>();

    cout << "== 依次添加: ";
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }

    cout << "\n== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;

    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();

    cout << "\n== 删除根节点: " << arr[3];
    tree->remove(arr[3]);

    cout << "\n== 中序遍历: ";
    tree->inOrder();
    cout << endl;

    // 销毁二叉树
    tree->destroy();

    return 1;
}
