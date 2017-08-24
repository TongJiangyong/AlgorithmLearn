#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL
#define CHAR_NUM 255
using namespace std;
/**
由此可以看到，字符串匹配算法的核心在于，如何移动子串，让其匹配成功.....
sunday算法的核心在于，每次比较子串后面的那一位，来匹配和移动字符串,算法能跳过尽可能多的字符以进行下一步的匹配

对于T，我们做一个简单而巧妙的预处理：记录T中每一种字符最后出现的位置，将其存入一个数组中
Sunday算法思想跟BM算法很相似，在匹配失败时关注的是文本串中参加匹配的最末位字符的下一位字符。
如果该字符没有在匹配串中出现则直接跳过，即移动步长= 匹配串长度+1；否则，同BM算法一样其移动步长=匹配串中最右端的该字符到末尾的距离+1。
**/

/**
Sunday算法的实现原理：
http://blog.csdn.net/airfer/article/details/8951802/
http://www.cnblogs.com/huhu0013/p/3227811.html
例如我们要在"substring searching algorithm"查找"search"，刚开始时，把子串与文本左边对齐：
substring searching algorithm
search
^
结果在第二个字符处发现不匹配，于是要把子串往后移动。但是该移动多少呢？这就是各种算法各显神通的地方了，最简单的做法是移动一个字符位置；KMP是利用已经匹配部分的信息来移动；BM算法是做反向比较，并根据已经匹配的部分来确定移动量。这里要介绍的方法是看紧跟在当前子串之后的那个字符（上图中的 'i')。

显然，不管移动多少，这个字符是肯定要参加下一步的比较的，也就是说，如果下一步匹配到了，这个字符必须在子串内。所以，可以移动子串，使子串中的最右边的这个字符与它对齐。现在子串'search'中并不存在'i'，则说明可以直接跳过一大片，从'i'之后的那个字符开始作下一步的比较，如下图：
substring searching algorithm
　　　  search
　　　  ^

比较的结果，第一个字符就不匹配，再看子串后面的那个字符，是'r',它在子串中出现在倒数第三位，于是把子串向前移动三位，使两个'r'对齐，如下：

substring searching algorithm
　　　　    search

**/

//使用strl，加持数组实现的算法
int sunday_stl(const string charToFind,const string charToFit){
    //首先判断是否合法
    int text_len = charToFind.length();
    int find_len = charToFit.length();
    if(find_len<=0||text_len<=0)
    {
        return -1;
    }
    //构造字符相关的一个数组
    char charMap[CHAR_NUM];
    //第一个循环，初始化所有的数组值
    //初始值为子串的长度+1;
    for(int i =0;i<CHAR_NUM;i++)
    {
        charMap[i]=charToFit.length()+1;
    }
    //第二个循环，用于给和子串相关的数组元素赋值
    //因为设定了字符串数组的长度，即给特定位置的数组付给长度即可
    //这个给定的长度，实际上是主游标变化的值
    for(int i=0;i<find_len;i++)
    {
        charMap[charToFit[i]] =find_len - i;
    }
    //这里m为主串的游标
    int m = 0;
    //n为子串的游标
    int n = 0;
    //这里因为j并不是固定递增，所以，j可能有较多变化......
    while(m<=(text_len-find_len))
    {
        //对比子串和主串进行找数据...
        while(n<find_len)
        {
            if(charToFit[n]==charToFind[m+n])
            {
                n++;
            }
            else
            {
                break;
            }

        }
        //判断并结束循环......
        if(n==find_len)
        {
            return m;
        }
        else
        {
            //对主串要找到当前对比的后一个位置
            //主要是对主串的游标进行变化，即，每次找的位置，都是主串末位字符，经过计算后，找到的数据，
            //虽然从道理上，每次主串上找的位置，都是子串的下一个字符，但是实际上，主串游标的变化，并不是按固定变化的
            //因为子串的比较都是从主游标开始的地方开始比较，所以要这么处理
            m=m+charMap[charToFind[m+find_len]];
            //子串在每次变化后，都是从0开始，因此不需要做过多处理
            n=0;
        }

    }
    return -1;
}

int sunday(const char *text,const char *fit)
{
    if(*text=='/0'||*fit=='/0')
    {
        return -1;
    }
    char charMap[CHAR_NUM];
    int text_len = strlen(text);
    int find_len = strlen(fit);
    for(int i=0;i<CHAR_MAX;i++)
        charMap[i] = find_len+1;
    for(int i = 0;i<find_len;i++)
        charMap[fit[i]] = find_len-i;
    //m为主游标
    int m = 0;
    while(m<=(text_len-find_len))
    {
        if(strncmp(fit,text+m,find_len)==0)
            return m;
        else
            m+=charMap[text[m+find_len]];
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
//这里将string转为char类处理
const char * charToFind =stringToFind.data();
const char * charToFit =stringToFit.data();
cout<<charToFind<<endl;
cout<<charToFit<<endl;
cout<<sunday(charToFind,charToFit)<<endl;



#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
