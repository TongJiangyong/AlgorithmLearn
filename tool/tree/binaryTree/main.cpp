#include<iostream>
#include<stdio.h>
//#define USE_RECURSION

#include"binaryTree.h"
using namespace std;
//#define LOCAL
/*
using namespace std;
//让new引发NoMem异常，而不是xalloc异常
void my_new_handler(){
    throw NoMem();
}
new_handler Old_Handler_=set_new_handler(my_new_handler);
*/


int count = 0;
BinaryTree<char> temp,A,B, C, D, E, F,G,H;

template<class T>
void ct(BinaryTreeNode<T> *t) {
    t->Visit(t);
    cout<<endl;
    //t->Visit(t)
    count++;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

/*
在C和C++中，等于，相当于重新赋值
int t =8;
cout<<&t<<" "<<t<<endl;
int m = t;
cout<<&m<<" "<<m<<endl;
*/
//先序遍历顺序为：ABDECF
//中序遍历顺序为：DBEAFC
//后序遍历顺序为：DEBFCA
//三种遍历最好不要从算法上理解，而是按照规则按图索骥的去理解，并使用按图索骥的规律设计算法
//         A
//       B   C
//     D  E F

//G.MakeTree( 'G' , temp , temp ) ;
//H.MakeTree( 'H' , temp , temp ) ;
//D.MakeTree( 'D' , G , H ) ;
D.MakeTree( 'D' , temp , temp ) ;
E.MakeTree( 'E' , temp , temp  ) ;
F.MakeTree( 'F' , temp , temp ) ;
B.MakeTree( 'B' , D , E ) ;
C.MakeTree( 'C' , F , temp  ) ;
A.MakeTree( 'A' , B , C ) ;
A.LevelOrder(ct);
//y.PreOrder(y.GetRoot()->Visit(y.GetRoot())) ;
cout <<"num is " <<count << endl;
#ifdef LOCAL
    fclose("in.txt", "r", stdin);
    fclose("out.txt", "w", stdout);
#endif

}
