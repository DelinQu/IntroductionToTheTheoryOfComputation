#include <iostream>
#include <cstring>
using namespace std;
int n,m,t,a;
int s[1000][1000],F[1000];                     // 状态转换矩阵和接受状态集
int main(){
    while(scanf("%d%d%d%d",&n,&m,&t,&a)!=EOF){                     // 多个序列输入
        memset(s,0,sizeof(s));                  // 初始化为0
        memset(F,0,sizeof(F));
        // 状态转换矩阵
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++)
                scanf("%d",&s[i][j]);
        }
        // 输入接收状态F
        for(int i = 0;i<t;i++){
            int cur;
            cin>>cur;
            F[cur] = 1;
        }
        // 输入测试串
        while(a--){
            string temps;
            cin>>temps;
            int cur = 1;
            for(int i = 0;i<temps.length();i++){
                // 转移
                cur = s[cur][temps[i]-'a'+1];
            }
            if(F[cur]==1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}