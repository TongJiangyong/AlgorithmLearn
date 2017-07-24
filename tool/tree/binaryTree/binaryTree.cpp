#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP
#include"binaryTree.h"
#include"stackArray.h"
#include "queueArray.h"
#include"except.h"
#include <iostream>
using namespace std;
//前序遍历时，每个节点是在其左右子树被访问之前进行访
//只有BinaryTreeNode<T>::这个范围的定义，才能使用它的私有变量
template<class T>
void BinaryTreeNode<T>::PreOrder(BinaryTreeNode<T> *t){
    if(t){
        Visit(t);
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

//在中序遍历时，首先访问左子树，然后访问子树的根节点，最后访问右子树
template<class T>
void BinaryTreeNode<T>::InOrder(BinaryTreeNode<T> *t){
    if(t){
        InOrder(t->LeftChild);
        Visit(t);
        InOrder(t->RightChild);
    }
}

//在后序遍历时，当左右子树均访问完之后才访问子树的根节点
template<class T>
void BinaryTreeNode<T>::PostOrder(BinaryTreeNode<T> *t){
    if(t){
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        Visit(t);
    }
}

template<class T>
void BinaryTreeNode<T>::Visit(BinaryTreeNode<T> * t)
{
    cout<<t->data<<" ";
}



template<class T>
bool BinaryTree<T>::Root(T& x) const
{// 取根节点的d a t a域，放入x
// 如果没有根节点，则返回 f a l s e
    if (root) {x = root->data;
    return true;}
    else return false; // 没有根节点
}

//这里要求函数传入的树为不同的树
template<class T>
void BinaryTree <T>::MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right)
{// 将left, right和element 合并成一棵新树
// left, right和t h i s必须是不同的树
// 创建新树,创建新树，即重新定义结点即可！！！
    root = new BinaryTreeNode<T>(element, left.root, right.root);
    // 阻止访问l e f t和r i g h t ，这里为什么要赋予0？
    left.root = right.root = 0;
}

template<class T>
void BinaryTree <T>::BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right)
{// left, right和this必须是不同的树
// 检查树是否为空
    if (!root) throw BadInput(); // 空树
    // 分解树
    element = root->data;
    left.root = root->LeftChild;
    right.root = root->RightChild;
    delete root;
    root = 0;
}
#ifndef USE_RECURSION
//这种遍历需要使用栈

//树的前序，中序，后序遍历
//根据先序遍历的顺序，先访问根节点，再访问左子树，后访问右子树，而对于每个子树来说，又按照同样的访问顺序进行遍历，上图的先序遍历顺序为：ABDECF。非递归的实现思路如下：

/**
1）输出节点P，然后将其入栈，再看P的左孩子是否为空；
2）若P的左孩子不为空，则置P的左孩子为当前节点，重复1）的操作；
3）若P的左孩子为空，则将栈顶节点出栈，但不输出，并将出栈节点的右孩子置为当前节点，看其是否为空；
4）若不为空，则循环至1）操作；
5）如果为空，则继续出栈，但不输出，同时将出栈节点的右孩子置为当前节点，看其是否为空，重复4）和5）操作；
6）直到当前节点P为NULL并且栈空，遍历结束。
**/
template<class T>
void BinaryTree<T>::PreOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// 前序遍历
    //这里需要对栈的特性进行修改
    //这里创建一个空栈，注意在这里，需要对栈可以存储的类型进行适当的修改，才能适应
    StackArray <BinaryTreeNode<T> *> stackTemp(20);
    BinaryTreeNode<T> *treeNode;  //用于存储的过程即可
    BinaryTreeNode<T> *pCur = t;
    while(pCur||!stackTemp.IsEmpty())
    {
        //从根节点开始，输出当前节点，并将其入栈，
        //同时置其左孩子为当前节点，直至其没有左孩子，及当前节点为NULL
        //printf("%c ", pCur->data);
        Visit(pCur);
        stackTemp.Add(pCur);
        pCur = pCur->LeftChild;
        //如果当前节点pCur为NULL且栈不空，则将栈顶节点出栈  ，
        //注意这里，需要一直循环到当前节点不为空，才进行输出
        //同时置其右孩子为当前节点,循环判断，直至pCur不为空
        while(!pCur && !stackTemp.IsEmpty())
        {
            pCur = stackTemp.Top();
            stackTemp.Delete(treeNode);
            pCur = pCur->RightChild;
        }
    }


}

//中序遍历的处理过程
//1）若P的左孩子不为空，则将P入栈并将P的左孩子置为当前节点，然后再对当前节点进行相同的处理；
//2）若P的左孩子为空，则输出P节点，而后将P的右孩子置为当前节点，看其是否为空；
//3）若不为空，则重复1）和2）的操作；
//4）若为空，则执行出栈操作，输出栈顶节点，并将出栈的节点的右孩子置为当前节点，看起是否为空，重复3）和4）的操作；
//5）直到当前节点P为NULL并且栈为空，则遍历结束。

template <class T>
void BinaryTree<T>::InOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// 中序遍历
    //首先建立可以可以保存节点的栈
    StackArray <BinaryTreeNode<T> *> stackTemp(20);
    BinaryTreeNode<T>  *tempNode;
    BinaryTreeNode<T> *pCur = t; //保存当前节点
    //进入循环 当树为0，或者栈为空，则跳出循环
    while(pCur||!stackTemp.IsEmpty()){
        //如果左孩子不为空，则将节点入栈
        if(pCur->LeftChild){
            stackTemp.Add(pCur);
            pCur = pCur->LeftChild;
        }else{
            //如果左孩子为空，则输出当前节点，并访问右孩子
            //这个输出表示访问的是最左边的
            Visit(pCur);
            pCur = pCur->RightChild;
            //如果右孩子为空，且栈不为空，则需要进行一次出栈操作,并输出当前节点，然后进入右孩子
            //同时将它的右孩子设为当前节点，继续判断，直到当前节点不为空
            //这里判断为，如果当前节点为空，且栈不为空，则，退出一个栈，这样就能跳出循环，进入大循环中.....
            //这里 ，即将前序遍历的规则，描述成了算法！！！！
            while(!pCur&&!stackTemp.IsEmpty()){
                pCur = stackTemp.Top();
                Visit(pCur);  //这里当最左边的访问完成则开始访问存储的结点，在每一次访问存储结点前，需要打印自身即可
                stackTemp.Delete(tempNode);
                pCur = pCur->RightChild; //注意，这里的栈，保存的都是下一次循环的根结点，所以一定要注意 ..这里是一个重新设置结点的过程
            }
        }
    }


}

//后序遍历
//注意后序遍历与前两者不同，需要讨论树的分类情况
//后序遍历的核心思想在于：


//第一种思路：对于任一结点P，将其入栈，然后沿其左子树一直往下搜索，直到搜索到没有左孩子的结点，
//此时该结点出现在栈顶，但是此时不能将其出栈并访问，因此其右孩子还为被访问。
//所以接下来按照相同的规则对其右子树进行相同的处理，当访问完其右孩子时，该结点又出现在栈顶，此时可以将其出栈并访问。
//这样就保证了正确的访问顺序。可以看出，在这个过程中，每个结点都两次出现在栈顶，只有在第二次出现在栈顶时，才能访问它。
//因此需要多设置一个变量标识该结点是否是第一次出现在栈顶。
template <class T>
struct flagTest{
public:
    BinaryTreeNode<T> * node;
    bool isSeekAll;
};
template <class T>
void BinaryTree<T>::PostOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t){
    StackArray <flagTest<T>*> stackTemp(20);
    struct flagTest<T> *pCurNode;
    struct flagTest<T> *tempNode;
    BinaryTreeNode<T> *pCur = t; //保存当前节点
    while(pCur!=0||!stackTemp.IsEmpty()){  //
        while(pCur!=0){//沿左子树一直往下搜索，直至出现没有左子树的结点
            struct flagTest<T> *temp  = new flagTest<T>;
            temp->node =pCur;
            temp->isSeekAll = false;
            stackTemp.Add(temp); //首先需要先入栈
            pCur = pCur->LeftChild;
        }//将所有的左子树入栈以后，再进行判断，先出栈，但是出栈以后不能处理，要首先对所有的右子树进行处理
        if(!stackTemp.IsEmpty()){
            pCurNode = stackTemp.Top();
            stackTemp.Delete(tempNode);
            if(pCurNode->isSeekAll == false){
                pCurNode->isSeekAll = true;
                stackTemp.Add(pCurNode);
                pCur = pCurNode->node->RightChild;   //赋值表示重新确立结点！！！
            }else{
                Visit(pCurNode->node);  //可以访问的情况，则表示所有子树都已经访问完毕
                pCur = 0;
            }
        }
     }

}



//第二种思路：要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
//1、一开始就要先入栈，然后再采取措施
//2、
//1）先将节点P入栈；
//2）若P不存在左孩子和右孩子，或者P存在左孩子或右孩子，但左右孩子已经被输出，则可以直接输出节点P，并将其出栈，将出栈节点P标记为上一个输出的节点，再将此时的栈顶结点设为当前节点；
//3）若不满足2）中的条件，则将P的右孩子和左孩子依次入栈，当前节点重新置为栈顶结点，之后重复操作2）；
//4）直到栈空，遍历结束。

//
//
//template <class T>
//void BinaryTree<T>::PostOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
//{// 后序遍历
//    //首先建立可以可以保存节点的栈
//    StackArray <BinaryTreeNode<T> *> stackTemp(20);
//    BinaryTreeNode<T>  * pCur = t;
//    BinaryTreeNode<T>  *tempNode;
//
//    BinaryTreeNode<T> * pPre = 0;       //定义指针，指向上一个访问的节点
//    stackTemp.Add(pCur); //首先需要先入栈
//    //这里的流程为：进入循环，
//    while(!stackTemp.IsEmpty()){
//        //如果左子树不为空，则将节点入栈
//        pCur = stackTemp.Top();
//        if((pCur->LeftChild==0&&pCur->RightChild == 0)||
//           //#这里能够这样写的原因在于，只有访问完其左边结点或者其右结点，才能继续出栈！！！
//           (pPre!=0 && (pCur->LeftChild==pPre || pCur->RightChild==pPre)))
//        {
//            //如果当前节点没有左右孩子，或者有左孩子或有孩子，但已经被访问输出，
//            //则直接输出该节点，将其出栈，将其设为上一个访问的节点
//            Visit(pCur);
//            stackTemp.Delete(tempNode);
//            pPre = pCur; //注意这里每一次结点还原，都要遍历整个过程
//
//        }else
//        {
//            //如果不满足上面两种情况,则将其右孩子左孩子依次入栈
//            if(pCur->RightChild != 0)
//                stackTemp.Add(pCur->RightChild);
//            if(pCur->LeftChild != 0)
//                stackTemp.Add(pCur->LeftChild);
//        }
//    }
//
//
//}



#else
//树的前序，中序，后序遍历
template<class T>
void BinaryTree<T>::PreOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// 前序遍历
    if (t) {
        Visit(t) ;
        PreOrder( Visit, t->LeftChild);
        PreOrder( Visit, t->RightChild);
    }
}
template <class T>
void BinaryTree<T>::InOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// 中序遍历
    if (t) {
        InOrder(Visit, t->LeftChild);
        Visit(t) ;
        InOrder( Visit, t->RightChild);
    }
}
template <class T>
void BinaryTree<T>::PostOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// 后序遍历
    if (t){
        PostOrder(Visit, t->LeftChild);
        PostOrder( Visit, t->RightChild);
        Visit(t) ;
    }
}

#endif // USE_RECURSION

/*
template<class T>
void BinaryTree<T>::LevelOrder(void(*Visit)BinaryTreeNode<T> *u,BinaryTreeNode<T> *t)
{// 逐层遍历
    //这里增加了一个队列的用法，暂且不说明
    LinkedQueue<BinaryTreeNode<T>*> Q;
    BinaryTreeNode<T> *t;
    t = root;
    while (t) {
        Visit( t ) ;
        if (t->LeftChild) Q.Add(t->LeftChild);
        if (t->RightChild) Q.Add(t->RightChild);
        try {Q.Delete(t);}
        catch (OutOfBounds) {return;}
    }
}
*/

//逐层遍历 ，从上到下-->队列 从下到上 栈
template<class T>
void BinaryTree<T>::LevelOrder(void(*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
    QueueArray<BinaryTreeNode<T> *> queueList(20);
    while(t){
        Visit(t);
        if(t->LeftChild){
            queueList.Add(t->LeftChild);
        }
        if(t->RightChild){
            queueList.Add(t->RightChild);
        }
        //if(queueList.IsEmpty()){
        try{
            //一定要这么处理，不然queuelist不会很好使用
            queueList.Delete(t);
        }catch(OutOfBounds){
            return ;
        }

        //}

    }
}


template<class T>
void BinaryTreeNode<T>::Output(ostream& out) const
{
    cout<<"just a test"<<endl;
}
//重载< <
template <class T>
ostream& operator<<(ostream& out, const BinaryTreeNode<T> * x)
{
    x.Output(out); return out;
}



#endif // BINARYTREE_CPP
