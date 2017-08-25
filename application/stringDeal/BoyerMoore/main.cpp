#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL
#define CHAR_NUM 255
using namespace std;

/**
�����ı��༭����"����"���ܣ�Ctrl+F����������Boyer-Moore�㷨��
����ԭ��
http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html
�ƶ��Ĺ�����������ַ�����ͺú�׺����
���ַ������Ӵ����һλ��ƥ����ַ�
����λ�� = ���ַ���λ�� - �������е���һ�γ���λ��(���ұ�������һ��)
����λ�� = �ú�׺��λ�� - �������е���һ�γ���λ��
//ע�⣬�ú�׺һ�����ɶ��ѡ�����ԣ�һ��Ҫ����Դ���������Ժú�׺����ȡ��ģ�����
Boyer-Moore�㷨�Ļ���˼���ǣ�ÿ�κ�������������֮�еĽϴ�ֵ��
����˼·��
BM�㷨�ǶԺ�׺����ƥ��ĸĽ�
���������ܹ���ģ��ƶ��Ӵ�

�㷨ʵ�ֿ��Կ���ƪ���£�
http://www.cnblogs.com/xubenben/p/3359364.html
�ڻ��ַ�ģʽ�£������������
1�����ַ���ƥ��
2�����ַ�û��ƥ��
�����������£����Թ���һ�����������ַ������飬Ȼ��������sunday�㷨���漰�û��ַ��ƶ��Ĳ�������
�ںú�׺��ģʽ�£������������
1��ģʽ�������Ӵ�ƥ���Ϻú�׺����ʱ�ƶ�ģʽ�����ø��Ӵ��ͺú�׺���뼴�ɣ��������һ���Ӵ�ƥ���Ϻú�׺����ѡ�����ߵ��Ӵ����롣
2��ģʽ����û���Ӵ�ƥ���Ϻ��׺����ʱ��ҪѰ��ģʽ����һ���ǰ׺�����ø�ǰ׺���ںú�׺�ĺ�׺��Ѱ�ҵ���ǰ׺���ø�ǰ׺�ͺú�׺���뼴��
3��ģʽ����û���Ӵ�ƥ���Ϻ��׺��������ģʽ�����Ҳ����ǰ׺���ø�ǰ׺���ںú�׺�ĺ�׺����ʱ��ֱ���ƶ�ģʽ���ú�׺����һ���ַ���
�����������£�
Ϊ��ʵ�ֺú�׺������Ҫ����һ������suffix[]������suffix[i] = s ��ʾ��iΪ�߽磬
��ģʽ����׺ƥ�����󳤶ȣ�����ͼ��ʾ���ù�ʽ��������������P[i-s, i] == P[m-s, m]����󳤶�s��
*/

//���Ǻ�׺����ƥ�䣬BM�㷨�Ƕ����ĸĽ�
//����㷨�ͱ���ƥ����ʵҲ���.....
int backFit(const string charToFind,const string charToFit)
{
    int j = 0; //����
    int i = charToFit.length()-1; //�Ӵ�
    while (j <= (charToFind.length() - charToFit.length()))
    {
        while(i>=0)
        {
            if(charToFind[j+i]==charToFit[i])
            {
                i--;
            }else
            {
                break;
            }
        }
       if (i < 0)
       {
            return j;
       }
       else
       {
           //BM�㷨��Ҫ�Ƕ��ƶ�����������˽ϴ�ĸ���.....
            j++;
            i=charToFit.length()-1;
       }
    }
    return -1;
}

//�趨���ַ��ƶ��Ĳ���
//�룬charToFitΪ�Ӵ���m���Ӵ�����
void preBmBc(char *charToFit, int m, int bmBc[]) {

   int i;

   for (i = 0; i < CHAR_NUM; ++i)

      bmBc[i] = m;

   for (i = 0; i < m - 1; ++i)

      bmBc[charToFit[i]] = m - i - 1;

}
//�趨�ú�׺�ƶ��Ĳ���
//�룬charToFitΪ�Ӵ���m���Ӵ����ȣ�suffix[]Ϊ��ģʽ��ƥ�����󳤶�����
//����suffix[i] = s ��ʾ��iΪ�߽磬��ģʽ����׺ƥ�����󳤶�
//�������һ�λ������Բο��������ӵĽ��ͣ� ���ַ�������Ҫ......
//http://www.cnblogs.com/xubenben/p/3359364.html
//����suffixes�����ģʽ�����������
void suffixes(char *x, int m, int *suff)
{
����suff[m-1]=m; //�������һ����ƥ��Ϊ��������
����for (i=m-2��i>=0��--i){
        q=i;
        while(q>=0&&charToFit[q]==charToFit[m-1-i+q])
            --q;
        suff[i]=i-q; //���û��ƥ��ĳ��ȣ���suff[i] = 0
    }
}
//����suffix���飬�Ϳ��Զ���bmGs[]���飬bmGs[i] ��ʾ�����ú�׺ʱ��ģʽ��Ӧ���ƶ��ľ��룬
//����i��ʾ�ú�׺ǰ��һ���ַ���λ�ã�Ҳ���ǻ��ַ���λ�ã�������bmGs�����Ϊ���������
//�ֱ��Ӧ�������ƶ�ģʽ�����������
/*
1��ģʽ�������Ӵ�ƥ���Ϻú�׺
2��ģʽ����û���Ӵ�ƥ���Ϻú�׺�����ҵ�һ�����ǰ׺
3��ģʽ����û���Ӵ�ƥ���Ϻú�׺�����Ҳ���һ�����ǰ׺
ʵ���ϵڶ��ֺ����ֺϲ�Ϊһ�ִ������У�
��������������е����������õ�bmGs[i]ֵ���ڵڶ��ִ��ڵ�һ�֡��ʶ�д�����ʱ�������ȼ��������������ټ���ڶ���������ټ����һ�������
Ϊʲô�أ���Ϊ����ͬһ��λ�õĶ���޸�ֻ��ʹ��bmGs[i]Խ��ԽС��
����4-5�ж�Ӧ�˵����������7-11�ж��ڵڶ��������12-13��Ӧ�����������
*/

void preBmGs(char *x, int m, int bmGs[]) {
   int i, j, suff[XSIZE];
   suffixes(x, m, suff);
   for (i = 0; i < m; ++i)
      bmGs[i] = m;
   j = 0;
   for (i = m - 1; i >= 0; --i)
      if (suff[i] == i + 1)
         for (; j < m - 1 - i; ++j)
            if (bmGs[j] == m)
               bmGs[j] = m - 1 - i;
   for (i = 0; i <= m - 2; ++i)
      bmGs[m - 1 - suff[i]] = m - 1 - i;
}


void BM(char *x, int m, char *y, int n) {
   int i, j, bmGs[XSIZE], bmBc[ASIZE];

   /* Preprocessing */
   preBmGs(x, m, bmGs);
   preBmBc(x, m, bmBc);
   /* Searching */
   j = 0;
   while (j <= n - m) {
      for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
      if (i < 0) {
         OUTPUT(j);
         j += bmGs[0];
      }
      else
         j += MAX(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
   }
}


int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
string stringToFind;
string stringToFit;
getline(cin,stringToFind);
getline(cin,stringToFit);
const char * charToFind =stringToFind.data();
const char * charToFit =stringToFit.data();

cout<<charToFind<<endl;
cout<<charToFit<<endl;
cout<<backFit(stringToFind,stringToFit)<<endl;


#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
