#include <iostream>
#include <stdio.h>
//����������string��Ϊ����
#include <string>
#include <cstring>
#define LOCAL
using namespace std;
/**
������һ���ܳ������ַ����������������
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
<string.h>��C�汾��ͷ�ļ�����������strcpy��strcat֮����ַ�����������
<cstring>
��C++��׼��(1998��)�����У�Ϊ�˼�����ǰ����׼����֯��������Щ�ļ����������µĶ��壬���뵽�˱�׼���У��������ļ�����������һ��"c"ǰ׺����ȥ����.h�ĺ�׺��������string.hͷ�ļ�����cstringͷ�ļ���������ʵ��ȴ����ͬ�Ļ��Ǽ�����ǰ�ģ������<cstring>����Դ����Ҫ�����ֶ���һ���������൱�ڱ�׼����֯�������˸��£�˵����Ҳ���ҵı�׼������һ�����ˡ���
<string>
<string>��C++��׼�����ͷ�ļ�����������һ��string���ַ����࣬���������string��ĸ��ֲ�������s.size(), s.erase(), s.insert()�ȡ���<string>�ְ������ϵ�C�汾���ַ���������strcpy��strcat�ȣ�����൱�ڣ���<string>���ļ��г��˶����Լ���string��֮�⣬������һ��#include<string.h>һ�������C�汾���ַ���������
**/
/***
���ﻹ����һ��c���Զ��嶯̬����ķ�������ʹ��malloc��realoc�ķ��������ʹ��mallocʵ�ּ���.....
��Ҳ��stl��string��ʵ�ַ�ʽ.....
#include<stdio.h>
int main(int argc, char** argv)
{
    int strLen = 5;
    char ch;
    char* str = (char*)malloc(sizeof(char*) * strLen);
    //printf("str_pre=:%d\n",str);//�鿴ָ��str��ַ
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
    //printf("str_lat=:%d\n",str);//�鿴ʹ��realloc��ָ��str��ַ
    printf("count=%d\n",count);
    str[count] = '\0';
    puts(str);
    return 0;
}
***/

/**
 Brute force ��Ϊ���������㷨
 ����ԭ�ַ���ʼ�����һȦ��û�� ƥ�䣬���ԭλ��+1���¿�ʼ����

**/

int BruteForce(const string charToFind,const string charFit)
{
    //����ַ���������Ҫ��
    //ע��stlʵ������size����������ʹ��strlen���󳤶ȣ�ֻ��������char
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
    //�ж��Ƿ���֣�i�����趨ֱ��С��find_len����������Ч�ʸ���
    //���Կ���������������Ҫѭ���Ƚϣ�������ѭ���л����ʵ��仯�����Բ���ʹ��forѭ����
    //forѭ���Ƕ���û����������Ķ���ѭ��������whileѭ����������
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
//���ַ�����˵��cinֻ�ܻ�ȡ���ʣ�getline���ܻ�ȡ������һ�仰

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
