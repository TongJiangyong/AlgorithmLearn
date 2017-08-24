#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL
#define CHAR_NUM 255
using namespace std;
/**
�ɴ˿��Կ������ַ���ƥ���㷨�ĺ������ڣ�����ƶ��Ӵ�������ƥ��ɹ�.....
sunday�㷨�ĺ������ڣ�ÿ�αȽ��Ӵ��������һλ����ƥ����ƶ��ַ���,�㷨�����������ܶ���ַ��Խ�����һ����ƥ��

����T��������һ���򵥶������Ԥ������¼T��ÿһ���ַ������ֵ�λ�ã��������һ��������
Sunday�㷨˼���BM�㷨�����ƣ���ƥ��ʧ��ʱ��ע�����ı����вμ�ƥ�����ĩλ�ַ�����һλ�ַ���
������ַ�û����ƥ�䴮�г�����ֱ�����������ƶ�����= ƥ�䴮����+1������ͬBM�㷨һ�����ƶ�����=ƥ�䴮�����Ҷ˵ĸ��ַ���ĩβ�ľ���+1��
**/

/**
Sunday�㷨��ʵ��ԭ��
http://blog.csdn.net/airfer/article/details/8951802/
http://www.cnblogs.com/huhu0013/p/3227811.html
��������Ҫ��"substring searching algorithm"����"search"���տ�ʼʱ�����Ӵ����ı���߶��룺
substring searching algorithm
search
^
����ڵڶ����ַ������ֲ�ƥ�䣬����Ҫ���Ӵ������ƶ������Ǹ��ƶ������أ�����Ǹ����㷨������ͨ�ĵط��ˣ���򵥵��������ƶ�һ���ַ�λ�ã�KMP�������Ѿ�ƥ�䲿�ֵ���Ϣ���ƶ���BM�㷨��������Ƚϣ��������Ѿ�ƥ��Ĳ�����ȷ���ƶ���������Ҫ���ܵķ����ǿ������ڵ�ǰ�Ӵ�֮����Ǹ��ַ�����ͼ�е� 'i')��

��Ȼ�������ƶ����٣�����ַ��ǿ϶�Ҫ�μ���һ���ıȽϵģ�Ҳ����˵�������һ��ƥ�䵽�ˣ�����ַ��������Ӵ��ڡ����ԣ������ƶ��Ӵ���ʹ�Ӵ��е����ұߵ�����ַ��������롣�����Ӵ�'search'�в�������'i'����˵������ֱ������һ��Ƭ����'i'֮����Ǹ��ַ���ʼ����һ���ıȽϣ�����ͼ��
substring searching algorithm
������  search
������  ^

�ȽϵĽ������һ���ַ��Ͳ�ƥ�䣬�ٿ��Ӵ�������Ǹ��ַ�����'r',�����Ӵ��г����ڵ�������λ�����ǰ��Ӵ���ǰ�ƶ���λ��ʹ����'r'���룬���£�

substring searching algorithm
��������    search

**/

//ʹ��strl���ӳ�����ʵ�ֵ��㷨
int sunday_stl(const string charToFind,const string charToFit){
    //�����ж��Ƿ�Ϸ�
    int text_len = charToFind.length();
    int find_len = charToFit.length();
    if(find_len<=0||text_len<=0)
    {
        return -1;
    }
    //�����ַ���ص�һ������
    char charMap[CHAR_NUM];
    //��һ��ѭ������ʼ�����е�����ֵ
    //��ʼֵΪ�Ӵ��ĳ���+1;
    for(int i =0;i<CHAR_NUM;i++)
    {
        charMap[i]=charToFit.length()+1;
    }
    //�ڶ���ѭ�������ڸ����Ӵ���ص�����Ԫ�ظ�ֵ
    //��Ϊ�趨���ַ�������ĳ��ȣ������ض�λ�õ����鸶�����ȼ���
    //��������ĳ��ȣ�ʵ���������α�仯��ֵ
    for(int i=0;i<find_len;i++)
    {
        charMap[charToFit[i]] =find_len - i;
    }
    //����mΪ�������α�
    int m = 0;
    //nΪ�Ӵ����α�
    int n = 0;
    //������Ϊj�����ǹ̶����������ԣ�j�����н϶�仯......
    while(m<=(text_len-find_len))
    {
        //�Ա��Ӵ�����������������...
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
        //�жϲ�����ѭ��......
        if(n==find_len)
        {
            return m;
        }
        else
        {
            //������Ҫ�ҵ���ǰ�Աȵĺ�һ��λ��
            //��Ҫ�Ƕ��������α���б仯������ÿ���ҵ�λ�ã���������ĩλ�ַ�������������ҵ������ݣ�
            //��Ȼ�ӵ����ϣ�ÿ���������ҵ�λ�ã������Ӵ�����һ���ַ�������ʵ���ϣ������α�ı仯�������ǰ��̶��仯��
            //��Ϊ�Ӵ��ıȽ϶��Ǵ����α꿪ʼ�ĵط���ʼ�Ƚϣ�����Ҫ��ô����
            m=m+charMap[charToFind[m+find_len]];
            //�Ӵ���ÿ�α仯�󣬶��Ǵ�0��ʼ����˲���Ҫ�����ദ��
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
    //mΪ���α�
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
//���ｫstringתΪchar�ദ��
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
