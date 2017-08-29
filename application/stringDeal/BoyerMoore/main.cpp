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
http://blog.csdn.net/joylnwang/article/details/6785743
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
void preBmBc(const char *charToFit, int m, int bmBc[]) {

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
void suffixes(const char *x, int m, int *suff)
{
    //�������һ����ƥ��Ϊ��������
    suff[m-1]=m;
    int i,q;
    for (i=m-2;i>=0;--i){
        q=i;
        while(q>=0&&x[q]==x[m-1-i+q])
        {
             --q;
        }

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
Ŀ���ǻ�þ�ȷ��bmGs[i]
*/
void preBmGs(const char *x, int m, int bmGs[]) {
   int i, j, suff[CHAR_NUM];
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

int maxNum(int a,int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}

int bm_2(const char *x, const char *y) {
   int i, j, bmGs[CHAR_NUM], bmBc[CHAR_NUM];
   /* Preprocessing */
   int n = strlen(x);
   int m = strlen(y);
   preBmGs(y, m, bmGs);
   preBmBc(y, m, bmBc);
   /* Searching */
   j = 0;
   while (j <= n - m) {
      for (i = m - 1; i >= 0 && x[i] == y[i + j]; --i);
      if (i < 0) {
         return j;
         j += bmGs[0];
      }
      else
         j += maxNum(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
   }
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  bm
 *         Descritexttion:  Boyer�CMoore method for string match.
 *======================================================================================
 */
int bm_1(const char *text, const char *charToFit)
{
    if (*text == '/0' || *charToFit == '/0')
        return -1;
    int i, j, k;
    int text_len = strlen(text);
    int find_len = strlen(charToFit);
    if (text_len < find_len)
        return -1;
    int delta_1[CHAR_MAX];
    for (i=0; i<CHAR_MAX; i++)
        delta_1[i] = find_len;
    for (i=0; i<find_len; i++)
        delta_1[charToFit[i]] = find_len - i - 1;
    int rpr[find_len];
    rpr[find_len-1] = find_len - 1;
    for (i=find_len-2; i>=0; i--)
    {
        int len = (find_len - 1) - i;
        //charToFit the reoccurence of the right most (len) chars
        for (j=find_len-2; j>=(len-1); j--)
        {
            if (strncmp(charToFit+i+1, charToFit+j-len+1, len) == 0)
            {
                if ((j-len) == -1 || charToFit[i] != charToFit[j-len])
                {
                    rpr[i] = j - len + 1;
                    break;
                }
            }
        }
        //if the right most (len) chars not completely occur, we find the right
        //substring of (len). every step, we try to find the right most (len-k)
        //chars.
        for (k=1; j<(len-1) && k<len; k++)
        {
            if (strncmp(charToFit+i+k, charToFit, len-k) == 0)
            {
                rpr[i] = 0 - k;
                break;
            }
        }
        if (j<(len-1) && k == len)
        {
            rpr[i] = 0 - len;
        }
    }
    int delta_2[find_len];
    for (i=0; i<find_len; i++)
        delta_2[i] = find_len - rpr[i];
    i = find_len - 1;
    j = find_len - 1;
    while (i < text_len)
    {
        if (text[i] == charToFit[j])
        {
            i--;
            j--;
        }
        else
        {
            if (delta_1[text[i]] > delta_2[j])
            {
                i += delta_1[text[i]];
            }
            else
            {
                i += delta_2[j];
            }
            j = find_len - 1;
        }
        if (j == -1)
            return i+1;
    }

    return -1;
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
http://blog.csdn.net/joylnwang/article/details/6785743
cout<<charToFind<<endl;
cout<<charToFit<<endl;
cout<<bm_2(charToFind,charToFit)<<endl;


#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
