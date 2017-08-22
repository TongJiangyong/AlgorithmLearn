#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**


**/





int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
int num;
cin>>num;
float *arrayInt = new float[num];
for(int i=0;i<num;i++)
{
    cin>>arrayInt[i];
}


for(int j=0;j<num;j++){
    cout<<arrayInt[j]<<" ";
}

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
