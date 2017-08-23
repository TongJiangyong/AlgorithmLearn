#include <iostream>
#include <stdio.h>
#include <cstring>
#define LOCAL
using namespace std;

/**
KMP算法，以及其他算法的一些特性：
http://www.cnblogs.com/mfryf/archive/2012/08/15/2639565.html
http://blog.csdn.net/yutianzuijin/article/details/11954939/
KMP算法的核心在于，利用了以及匹配的运算值，以及子字符串自身的属性特点......

**/

int kmp(const char *text, const char *tofind)
{
    if (*text == '/0' || *tofind == '/0')
        return -1;
    int find_len = strlen(tofind);
    int text_len = strlen(text);
    if (text_len < find_len)
        return -1;
    int map[find_len];
    memset(map, 0, find_len*sizeof(int));
    //initial the kmp base array: map
    map[0] = 0;
    map[1] = 0;
    int i = 2;
    int j = 0;
    for (i=2; i<find_len; i++)
    {
        while (1)
        {
            if (tofind[i-1] == tofind[j])
            {
                j++;
                if (tofind[i] == tofind[j])
                {
                    map[i] = map[j];
                }
                else
                {
                    map[i] = j;
                }
                break;
            }
            else
            {
                if (j == 0)
                {
                    map[i] = 0;
                    break;
                }
                j = map[j];
            }
        }
    }
    i = 0;
    j = 0;
    for (i=0; i<text_len;)http://www.cnblogs.com/mfryf/archive/2012/08/15/2639565.html
    {
        if (text[i] == tofind[j])
        {
            i++;
            j++;
        }
        else
        {
            j = map[j];
            if (j == 0)
                i++;
        }
        if (j == (find_len))
            return i-j;
    }
    return -1;
}


int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
char *charToFind = "this is a good place";
char *charFit = "oo";
int position = kmp(charToFind,charFit);

cout<<position<<endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
