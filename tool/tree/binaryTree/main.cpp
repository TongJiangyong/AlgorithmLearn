#include<iostream>
#include<stdio.h>
//#define USE_RECURSION

#include"binaryTree.h"
using namespace std;
//#define LOCAL
/*
using namespace std;
//��new����NoMem�쳣��������xalloc�쳣
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
��C��C++�У����ڣ��൱�����¸�ֵ
int t =8;
cout<<&t<<" "<<t<<endl;
int m = t;
cout<<&m<<" "<<m<<endl;
*/
//�������˳��Ϊ��ABDECF
//�������˳��Ϊ��DBEAFC
//�������˳��Ϊ��DEBFCA
//���ֱ�����ò�Ҫ���㷨����⣬���ǰ��չ���ͼ������ȥ��⣬��ʹ�ð�ͼ�����Ĺ�������㷨
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
