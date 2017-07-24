#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP
#include"binaryTree.h"
#include"stackArray.h"
#include "queueArray.h"
#include"except.h"
#include <iostream>
using namespace std;
//ǰ�����ʱ��ÿ���ڵ���������������������֮ǰ���з�
//ֻ��BinaryTreeNode<T>::�����Χ�Ķ��壬����ʹ������˽�б���
template<class T>
void BinaryTreeNode<T>::PreOrder(BinaryTreeNode<T> *t){
    if(t){
        Visit(t);
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

//���������ʱ�����ȷ�����������Ȼ����������ĸ��ڵ㣬������������
template<class T>
void BinaryTreeNode<T>::InOrder(BinaryTreeNode<T> *t){
    if(t){
        InOrder(t->LeftChild);
        Visit(t);
        InOrder(t->RightChild);
    }
}

//�ں������ʱ��������������������֮��ŷ��������ĸ��ڵ�
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
{// ȡ���ڵ��d a t a�򣬷���x
// ���û�и��ڵ㣬�򷵻� f a l s e
    if (root) {x = root->data;
    return true;}
    else return false; // û�и��ڵ�
}

//����Ҫ�����������Ϊ��ͬ����
template<class T>
void BinaryTree <T>::MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right)
{// ��left, right��element �ϲ���һ������
// left, right��t h i s�����ǲ�ͬ����
// ��������,���������������¶����㼴�ɣ�����
    root = new BinaryTreeNode<T>(element, left.root, right.root);
    // ��ֹ����l e f t��r i g h t ������ΪʲôҪ����0��
    left.root = right.root = 0;
}

template<class T>
void BinaryTree <T>::BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right)
{// left, right��this�����ǲ�ͬ����
// ������Ƿ�Ϊ��
    if (!root) throw BadInput(); // ����
    // �ֽ���
    element = root->data;
    left.root = root->LeftChild;
    right.root = root->RightChild;
    delete root;
    root = 0;
}
#ifndef USE_RECURSION
//���ֱ�����Ҫʹ��ջ

//����ǰ�����򣬺������
//�������������˳���ȷ��ʸ��ڵ㣬�ٷ������������������������������ÿ��������˵���ְ���ͬ���ķ���˳����б�������ͼ���������˳��Ϊ��ABDECF���ǵݹ��ʵ��˼·���£�

/**
1������ڵ�P��Ȼ������ջ���ٿ�P�������Ƿ�Ϊ�գ�
2����P�����Ӳ�Ϊ�գ�����P������Ϊ��ǰ�ڵ㣬�ظ�1���Ĳ�����
3����P������Ϊ�գ���ջ���ڵ��ջ�����������������ջ�ڵ���Һ�����Ϊ��ǰ�ڵ㣬�����Ƿ�Ϊ�գ�
4������Ϊ�գ���ѭ����1��������
5�����Ϊ�գ��������ջ�����������ͬʱ����ջ�ڵ���Һ�����Ϊ��ǰ�ڵ㣬�����Ƿ�Ϊ�գ��ظ�4����5��������
6��ֱ����ǰ�ڵ�PΪNULL����ջ�գ�����������
**/
template<class T>
void BinaryTree<T>::PreOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// ǰ�����
    //������Ҫ��ջ�����Խ����޸�
    //���ﴴ��һ����ջ��ע���������Ҫ��ջ���Դ洢�����ͽ����ʵ����޸ģ�������Ӧ
    StackArray <BinaryTreeNode<T> *> stackTemp(20);
    BinaryTreeNode<T> *treeNode;  //���ڴ洢�Ĺ��̼���
    BinaryTreeNode<T> *pCur = t;
    while(pCur||!stackTemp.IsEmpty())
    {
        //�Ӹ��ڵ㿪ʼ�������ǰ�ڵ㣬��������ջ��
        //ͬʱ��������Ϊ��ǰ�ڵ㣬ֱ����û�����ӣ�����ǰ�ڵ�ΪNULL
        //printf("%c ", pCur->data);
        Visit(pCur);
        stackTemp.Add(pCur);
        pCur = pCur->LeftChild;
        //�����ǰ�ڵ�pCurΪNULL��ջ���գ���ջ���ڵ��ջ  ��
        //ע�������Ҫһֱѭ������ǰ�ڵ㲻Ϊ�գ��Ž������
        //ͬʱ�����Һ���Ϊ��ǰ�ڵ�,ѭ���жϣ�ֱ��pCur��Ϊ��
        while(!pCur && !stackTemp.IsEmpty())
        {
            pCur = stackTemp.Top();
            stackTemp.Delete(treeNode);
            pCur = pCur->RightChild;
        }
    }


}

//��������Ĵ������
//1����P�����Ӳ�Ϊ�գ���P��ջ����P��������Ϊ��ǰ�ڵ㣬Ȼ���ٶԵ�ǰ�ڵ������ͬ�Ĵ���
//2����P������Ϊ�գ������P�ڵ㣬����P���Һ�����Ϊ��ǰ�ڵ㣬�����Ƿ�Ϊ�գ�
//3������Ϊ�գ����ظ�1����2���Ĳ�����
//4����Ϊ�գ���ִ�г�ջ���������ջ���ڵ㣬������ջ�Ľڵ���Һ�����Ϊ��ǰ�ڵ㣬�����Ƿ�Ϊ�գ��ظ�3����4���Ĳ�����
//5��ֱ����ǰ�ڵ�PΪNULL����ջΪ�գ������������

template <class T>
void BinaryTree<T>::InOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// �������
    //���Ƚ������Կ��Ա���ڵ��ջ
    StackArray <BinaryTreeNode<T> *> stackTemp(20);
    BinaryTreeNode<T>  *tempNode;
    BinaryTreeNode<T> *pCur = t; //���浱ǰ�ڵ�
    //����ѭ�� ����Ϊ0������ջΪ�գ�������ѭ��
    while(pCur||!stackTemp.IsEmpty()){
        //������Ӳ�Ϊ�գ��򽫽ڵ���ջ
        if(pCur->LeftChild){
            stackTemp.Add(pCur);
            pCur = pCur->LeftChild;
        }else{
            //�������Ϊ�գ��������ǰ�ڵ㣬�������Һ���
            //��������ʾ���ʵ�������ߵ�
            Visit(pCur);
            pCur = pCur->RightChild;
            //����Һ���Ϊ�գ���ջ��Ϊ�գ�����Ҫ����һ�γ�ջ����,�������ǰ�ڵ㣬Ȼ������Һ���
            //ͬʱ�������Һ�����Ϊ��ǰ�ڵ㣬�����жϣ�ֱ����ǰ�ڵ㲻Ϊ��
            //�����ж�Ϊ�������ǰ�ڵ�Ϊ�գ���ջ��Ϊ�գ����˳�һ��ջ��������������ѭ���������ѭ����.....
            //���� ������ǰ������Ĺ������������㷨��������
            while(!pCur&&!stackTemp.IsEmpty()){
                pCur = stackTemp.Top();
                Visit(pCur);  //���ﵱ����ߵķ��������ʼ���ʴ洢�Ľ�㣬��ÿһ�η��ʴ洢���ǰ����Ҫ��ӡ������
                stackTemp.Delete(tempNode);
                pCur = pCur->RightChild; //ע�⣬�����ջ������Ķ�����һ��ѭ���ĸ���㣬����һ��Ҫע�� ..������һ���������ý��Ĺ���
            }
        }
    }


}

//�������
//ע����������ǰ���߲�ͬ����Ҫ�������ķ������
//��������ĺ���˼�����ڣ�


//��һ��˼·��������һ���P��������ջ��Ȼ������������һֱ����������ֱ��������û�����ӵĽ�㣬
//��ʱ�ý�������ջ�������Ǵ�ʱ���ܽ����ջ�����ʣ�������Һ��ӻ�Ϊ�����ʡ�
//���Խ�����������ͬ�Ĺ������������������ͬ�Ĵ��������������Һ���ʱ���ý���ֳ�����ջ������ʱ���Խ����ջ�����ʡ�
//�����ͱ�֤����ȷ�ķ���˳�򡣿��Կ���������������У�ÿ����㶼���γ�����ջ����ֻ���ڵڶ��γ�����ջ��ʱ�����ܷ�������
//�����Ҫ������һ��������ʶ�ý���Ƿ��ǵ�һ�γ�����ջ����
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
    BinaryTreeNode<T> *pCur = t; //���浱ǰ�ڵ�
    while(pCur!=0||!stackTemp.IsEmpty()){  //
        while(pCur!=0){//��������һֱ����������ֱ������û���������Ľ��
            struct flagTest<T> *temp  = new flagTest<T>;
            temp->node =pCur;
            temp->isSeekAll = false;
            stackTemp.Add(temp); //������Ҫ����ջ
            pCur = pCur->LeftChild;
        }//�����е���������ջ�Ժ��ٽ����жϣ��ȳ�ջ�����ǳ�ջ�Ժ��ܴ���Ҫ���ȶ����е����������д���
        if(!stackTemp.IsEmpty()){
            pCurNode = stackTemp.Top();
            stackTemp.Delete(tempNode);
            if(pCurNode->isSeekAll == false){
                pCurNode->isSeekAll = true;
                stackTemp.Add(pCurNode);
                pCur = pCurNode->node->RightChild;   //��ֵ��ʾ����ȷ����㣡����
            }else{
                Visit(pCurNode->node);  //���Է��ʵ���������ʾ�����������Ѿ��������
                pCur = 0;
            }
        }
     }

}



//�ڶ���˼·��Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ�����P���������Ӻ��Һ��ӣ������ֱ�ӷ�����������P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣�������������������P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
//1��һ��ʼ��Ҫ����ջ��Ȼ���ٲ�ȡ��ʩ
//2��
//1���Ƚ��ڵ�P��ջ��
//2����P���������Ӻ��Һ��ӣ�����P�������ӻ��Һ��ӣ������Һ����Ѿ�������������ֱ������ڵ�P���������ջ������ջ�ڵ�P���Ϊ��һ������Ľڵ㣬�ٽ���ʱ��ջ�������Ϊ��ǰ�ڵ㣻
//3����������2���е���������P���Һ��Ӻ�����������ջ����ǰ�ڵ�������Ϊջ����㣬֮���ظ�����2����
//4��ֱ��ջ�գ�����������

//
//
//template <class T>
//void BinaryTree<T>::PostOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
//{// �������
//    //���Ƚ������Կ��Ա���ڵ��ջ
//    StackArray <BinaryTreeNode<T> *> stackTemp(20);
//    BinaryTreeNode<T>  * pCur = t;
//    BinaryTreeNode<T>  *tempNode;
//
//    BinaryTreeNode<T> * pPre = 0;       //����ָ�룬ָ����һ�����ʵĽڵ�
//    stackTemp.Add(pCur); //������Ҫ����ջ
//    //���������Ϊ������ѭ����
//    while(!stackTemp.IsEmpty()){
//        //�����������Ϊ�գ��򽫽ڵ���ջ
//        pCur = stackTemp.Top();
//        if((pCur->LeftChild==0&&pCur->RightChild == 0)||
//           //#�����ܹ�����д��ԭ�����ڣ�ֻ�з���������߽��������ҽ�㣬���ܼ�����ջ������
//           (pPre!=0 && (pCur->LeftChild==pPre || pCur->RightChild==pPre)))
//        {
//            //�����ǰ�ڵ�û�����Һ��ӣ����������ӻ��к��ӣ����Ѿ������������
//            //��ֱ������ýڵ㣬�����ջ��������Ϊ��һ�����ʵĽڵ�
//            Visit(pCur);
//            stackTemp.Delete(tempNode);
//            pPre = pCur; //ע������ÿһ�ν�㻹ԭ����Ҫ������������
//
//        }else
//        {
//            //��������������������,�����Һ�������������ջ
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
//����ǰ�����򣬺������
template<class T>
void BinaryTree<T>::PreOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// ǰ�����
    if (t) {
        Visit(t) ;
        PreOrder( Visit, t->LeftChild);
        PreOrder( Visit, t->RightChild);
    }
}
template <class T>
void BinaryTree<T>::InOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// �������
    if (t) {
        InOrder(Visit, t->LeftChild);
        Visit(t) ;
        InOrder( Visit, t->RightChild);
    }
}
template <class T>
void BinaryTree<T>::PostOrder(void (*Visit) (BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{// �������
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
{// ������
    //����������һ�����е��÷������Ҳ�˵��
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

//������ �����ϵ���-->���� ���µ��� ջ
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
            //һ��Ҫ��ô������Ȼqueuelist����ܺ�ʹ��
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
//����< <
template <class T>
ostream& operator<<(ostream& out, const BinaryTreeNode<T> * x)
{
    x.Output(out); return out;
}



#endif // BINARYTREE_CPP
