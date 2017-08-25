#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL
#define CHAR_NUM 255
using namespace std;

/**
各种文本编辑器的"查找"功能（Ctrl+F），大多采用Boyer-Moore算法。
基本原理：
http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html
移动的规则包括：坏字符规则和好后缀规则，
坏字符：与子串最后一位不匹配的字符
后移位数 = 坏字符的位置 - 搜索词中的上一次出现位置(从右边数的上一次)
后移位数 = 好后缀的位置 - 搜索词中的上一次出现位置
//注意，好后缀一般是由多个选择属性，一定要区别对待这个，所以好后缀总是取最长的？？？
Boyer-Moore算法的基本思想是，每次后移这两个规则之中的较大值。
基本思路：
BM算法是对后缀蛮力匹配的改进
即，尽量能够多的，移动子串

算法实现可以看这篇文章：
http://www.cnblogs.com/xubenben/p/3359364.html
在坏字符模式下，有两种情况：
1、坏字符有匹配
2、坏字符没有匹配
在以上条件下，可以构造一个包含所有字符的数组，然后类似于sunday算法，涉及好坏字符移动的步长即可
在好后缀的模式下，有三种情况：
1、模式串中有子串匹配上好后缀，此时移动模式串，让该子串和好后缀对齐即可，如果超过一个子串匹配上好后缀，则选择最靠左边的子串对齐。
2、模式串中没有子串匹配上后后缀，此时需要寻找模式串的一个最长前缀，并让该前缀等于好后缀的后缀，寻找到该前缀后，让该前缀和好后缀对齐即可
3、模式串中没有子串匹配上后后缀，并且在模式串中找不到最长前缀，让该前缀等于好后缀的后缀。此时，直接移动模式到好后缀的下一个字符。
在以上条件下：
为了实现好后缀规则，需要定义一个数组suffix[]，其中suffix[i] = s 表示以i为边界，
与模式串后缀匹配的最大长度，如下图所示，用公式可以描述：满足P[i-s, i] == P[m-s, m]的最大长度s。
*/

//这是后缀蛮力匹配，BM算法是对她的改进
//这个算法和暴力匹配其实也差不多.....
int backFit(const string charToFind,const string charToFit)
{
    int j = 0; //父串
    int i = charToFit.length()-1; //子串
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
           //BM算法主要是对移动的情况进行了较大的改善.....
            j++;
            i=charToFit.length()-1;
       }
    }
    return -1;
}

//设定坏字符移动的步数
//想，charToFit为子串，m是子串长度
void preBmBc(char *charToFit, int m, int bmBc[]) {

   int i;

   for (i = 0; i < CHAR_NUM; ++i)

      bmBc[i] = m;

   for (i = 0; i < m - 1; ++i)

      bmBc[charToFit[i]] = m - i - 1;

}
//设定好后缀移动的步数
//想，charToFit为子串，m是子串长度，suffix[]为与模式串匹配的最大长度数组
//其中suffix[i] = s 表示以i为边界，与模式串后缀匹配的最大长度
//理解上面一段话，可以参考下面链接的解释： 这种方法很重要......
//http://www.cnblogs.com/xubenben/p/3359364.html
//这里suffixes求得是模式串自身的属性
void suffixes(char *x, int m, int *suff)
{
　　suff[m-1]=m; //设置最后一个的匹配为整个数组
　　for (i=m-2；i>=0；--i){
        q=i;
        while(q>=0&&charToFit[q]==charToFit[m-1-i+q])
            --q;
        suff[i]=i-q; //如果没有匹配的长度，则suff[i] = 0
    }
}
//有了suffix数组，就可以定义bmGs[]数组，bmGs[i] 表示遇到好后缀时，模式串应该移动的距离，
//其中i表示好后缀前面一个字符的位置（也就是坏字符的位置），构建bmGs数组分为三种情况，
//分别对应上述的移动模式串的三种情况
/*
1、模式串中有子串匹配上好后缀
2、模式串中没有子串匹配上好后缀，但找到一个最大前缀
3、模式串中没有子串匹配上好后缀，但找不到一个最大前缀
实际上第二种和三种合并为一种处理，其中；
而在这三种情况中第三种情况获得的bmGs[i]值大于第二种大于第一种。故而写代码的时候我们先计算第三种情况，再计算第二种情况，再计算第一种情况。
为什么呢，因为对于同一个位置的多次修改只会使得bmGs[i]越来越小。
代码4-5行对应了第三种情况，7-11行对于第二种情况，12-13对应第三种情况。
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
