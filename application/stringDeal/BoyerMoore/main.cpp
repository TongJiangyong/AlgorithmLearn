#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL
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
