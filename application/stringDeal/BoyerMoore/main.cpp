#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL
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



**/





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

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
