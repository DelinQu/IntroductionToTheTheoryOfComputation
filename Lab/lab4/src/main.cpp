#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
unsigned __int64 gcd(unsigned __int64 a, unsigned __int64 b)
{
    if (b > 0)
    {
        return gcd(b, a % b);
    }
    return a;
}
int main(){
    unsigned __int64 a,b;
      while(cin>>a>>b){
        if(gcd(a,b)==1) {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
