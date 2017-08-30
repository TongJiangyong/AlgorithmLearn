#include <iostream>
#include <stdio.h>
#include "BinarySearch.h"
#define LOCAL
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )
using namespace std;
/**
���������ҷ�
�������Ļ���������ʹ�ã�
http://www.cnblogs.com/yangecnu/p/Introduce-Binary-Search-Tree.html
������˼�룺������������ȶԴ����ҵ����ݽ�����������ȷ���������֧��ֵС���ҷ�֧��ֵ��Ȼ���ھ��к�ÿ���ڵ�ĸ��ڵ�Ƚϴ�С��
�������ʺϵķ�Χ�� ����㷨�Ĳ���Ч�ʺܸߣ��������ʹ�����ֲ��ҷ���Ҫ���ȴ�������
�����ȶԲ��ҵ����ݣ����д�����ٽ��в��ҵĶ���.....

���������������BinarySearch Tree��Ҳ�ж�������������ƶ���������Binary Sort Tree��������һ�ÿ����������Ǿ����������ʵĶ�������

����1��������ڵ�����������գ��������������н���ֵ��С�����ĸ�����ֵ��

����2��������ڵ�����������գ��������������н���ֵ���������ĸ�����ֵ��

����3������ڵ����������Ҳ�ֱ�Ϊ�����������

����������������ʣ��Զ������������������������ɵõ���������С�
�����������������Ҫ����Ϊ��һ���ǳ���Ҫ���ص���������������Ϊ��������

�������������������Ϊ�������Ƚϣ��������µĽڵ�Ϊֹ......
**/

template <class T>

int getArrayLen(T& array)

{
    //������Ϊ������������ʱ������ָ����������飬���ݵ���������׵�ַ
    //������ﲻ�����ã�����Զ����1��һ��Ҫע�⼴��....
    return (sizeof(array) / sizeof(array[0]));
}



static int arr[]= {1,5,4,3,2,6};


int main()
{
    int i, ilen;
    //1��ģ������ò�Ҫ����д
    //2�����û��implement���캯������ô������룬����Ҳ�������
    BSTree<int>* tree=new BSTree<int>();

    cout << "== �������: ";
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }

    cout << "\n== ǰ�����: ";
    tree->preOrder();

    cout << "\n== �������: ";
    tree->inOrder();

    cout << "\n== �������: ";
    tree->postOrder();
    cout << endl;

    cout << "== ��Сֵ: " << tree->minimum() << endl;
    cout << "== ���ֵ: " << tree->maximum() << endl;
    cout << "== ������ϸ��Ϣ: " << endl;
    tree->print();

    cout << "\n== ɾ�����ڵ�: " << arr[3];
    tree->remove(arr[3]);

    cout << "\n== �������: ";
    tree->inOrder();
    cout << endl;

    // ���ٶ�����
    tree->destroy();

    return 1;
}
