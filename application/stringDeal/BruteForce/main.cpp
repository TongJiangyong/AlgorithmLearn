#include <iostream>
#include <stdio.h>
//在这里引入string更为方便
#include <string>
#include <cstring>
#define LOCAL
using namespace std;
/**
这里是一个很常见的字符串输入输出处理方法
#include <iostream>
#include <string>
int main()
{
    std::string line; // empty string
    while(std::getline(std::cin, line))
    {
            // read line at time until end-of-file
        std::cout << line << std::endl; // write s to the output
    }
    return 0;
}
**/


/**
<string.h>
<string.h>是C版本的头文件，包含比如strcpy、strcat之类的字符串处理函数。
<cstring>
在C++标准化(1998年)过程中，为了兼容以前，标准化组织将所有这些文件都进行了新的定义，加入到了标准库中，加入后的文件名就新增了一个"c"前缀并且去掉了.h的后缀名，所以string.h头文件成了cstring头文件。但是其实现却是相同的或是兼容以前的，这就是<cstring>的来源，不要觉得又多了一个东西。相当于标准库组织给它盖了个章，说“你也是我的标准程序库的一份子了”。
<string>
<string>是C++标准定义的头文件，它定义了一个string的字符串类，里面包含了string类的各种操作，如s.size(), s.erase(), s.insert()等。但<string>又包含了老的C版本的字符串操作如strcpy、strcat等，这就相当于，在<string>的文件中除了定义自己的string类之外，还加了一个#include<string.h>一句包含了C版本的字符串操作。
**/
/***
这里还给出一个c语言定义动态数组的方法，即使用malloc和realoc的方法，最好使用malloc实现即可.....
这也是stl的string的实现方式.....
#include<stdio.h>
int main(int argc, char** argv)
{
    int strLen = 5;
    char ch;
    char* str = (char*)malloc(sizeof(char*) * strLen);
    //printf("str_pre=:%d\n",str);//查看指针str地址
    int count = 0;
    printf("Please input a string: \n");
    do
    {
        ch = getchar();
        count++;
        if (count >= strLen)
        {
            str = (char*)realloc(str, sizeof(char*) * (++strLen));
        }
        str[count-1] = ch;
    }
    while (ch != '\n');
    //printf("str_lat=:%d\n",str);//查看使用realloc后指针str地址
    printf("count=%d\n",count);
    str[count] = '\0';
    puts(str);
    return 0;
}
***/

/**
 Brute force 即为暴力搜索算法
 即从原字符开始，如果一圈后没有 匹配，则从原位置+1重新开始搜索

**/

int BruteForce(const string charToFind,const string charFit)
{
    //如果字符串不符号要求
    //注意stl实际上有size方法，不能使用strlen来求长度，只能是用于char
    //int find_len = strlen(charToFind);
    //int fit_len = strlen(charFit);
    int find_len = charToFind.length();
    int fit_len = charFit.length();
    if(find_len==0||fit_len==0){
        return -1;
    }
    //cout<<find_len<<endl;
    //cout<<fit_len<<endl;
    //cout<<charToFind[2]<<endl;
    /*
    for(int i=0;i<(find_len-fit_len+1);i++)
    {
        for(int j=0;j<fit_len;j++)
        {
            if(charToFind[i]=charFit[j])
        }

    }*/
    int i=0,j=0;
    //判断是否出局，i可以设定直接小于find_len，但是这样效率更高
    //可以看出，由于这里需要循环比较，并且在循环中会有适当变化，所以不能使用for循环，
    //for循环是对于没有特殊情况的定长循环，但是while循环会更加灵活
    while(i<=(find_len-fit_len+2))
    {
        if(charToFind[i]==charFit[j])
        {
            i++;
            j++;
        }else
        {
            i++;
            j=0;
        }
        if(j==fit_len){
            return (i-fit_len);
        }
    }
    return -1;
}




int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//对字符串来说，cin只能获取单词，getline才能获取完整的一句话

//char *charToFind = new char[num];
string  charFit;
string charTofind;
//cin>>charFit;
getline(cin,charTofind);
getline(cin,charFit);


cout<<charFit<<endl;
cout<<charTofind<<endl;
int findPosition = BruteForce(charTofind,charFit);
cout<<findPosition<<endl;

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
