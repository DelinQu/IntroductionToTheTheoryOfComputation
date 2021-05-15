//12596
#include <iostream>
#include <string>
using namespace std;
string dp[100][100][100];//表格
string cfg[100];//cfg规则
string str[100];//待测字符串
string sa[100];//sa型规则
string SAB[100];//SAB形规则
int main()
{
    //输入
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>cfg[i]; 
    scanf("%d",&m);    
    for(int i=0;i<m;i++)    cin>>str[i]; 
    //记录长度
    int lstr[m];
    for(int i=0;i<m;i++) lstr[i]=str[i].length();
    //找出所有A->b型规则
    int num=0;
    for(int i=0;i<n;i++)
    {
        for(int k=3;k<cfg[i].length();k++)
        {
            if(cfg[i][k]>='a'&&cfg[i][k]<='z')
            {
                sa[num]+=cfg[i][0];//S->AB|a,记录S
                sa[num]+=cfg[i][k];//记录S->a
                num++;
            }
        }
    }
    //找出所有A->BC型规则
    int num2=0;
    for(int i=0;i<n;i++)
    {
        for(int k=3;k<cfg[i].length();k++)
        {
            if(cfg[i][k]<'a')
            {
                SAB[num2]+=cfg[i][0];//记录S
                SAB[num2]+=cfg[i][k];//记录AB
                SAB[num2]+=cfg[i][k+1];
                k++;
                num2++;
            }
        }
    }
    //考察每一个长为1的子串
    for(int i=0;i<m;i++)//m个字符串中的i
    {
        for(int j=0;j<lstr[i];j++)//第i个字符串的第j个字母
        {
            for(int k=0;k<num;k++)//A->a类型字符串的第k个字符串
            {
                if(str[i][j]==sa[k][1])  //考察CFG文法的每一个字符
                    dp[i][j][j]=sa[k][0];//记录dp[i][j][j]=sa[k][0]起始位置
            }
        }
    }
    //考察l长度的子串
    for(int i=0;i<m;i++)
    {
        for(int l=2;l<=lstr[i];l++)      //l是子串的长度
        {
            for(int p=0;p<lstr[i]-l+1;p++)   //p是子串的起始位置
            {
                int j=p+l-1;                //j是子串的结束位置
                for(int k=p;k<j;k++)     //k是分裂的位置 k<=j-1 ->k<j
                    for(int q=0;q<num2;q++)
                        if(dp[i][p][k].find(SAB[q][1])!=-1&&dp[i][k+1][j].find(SAB[q][2])!=-1) dp[i][p][j]+=SAB[q][0];
            }
        }
    }
    //检查起始变元是否在dp[0][n]中
    for(int i=0;i<m;i++)
    {
        int flag=0;
        if(dp[i][0][lstr[i]-1].find(cfg[0][0])!=-1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

