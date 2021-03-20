#include<iostream>
#include<cmath>
#include<cstring>

#define M 1000000
using namespace std;
int Qlist[M];                       //状态序列，记录的是NFA状态号     
int transTable0[M],transTable1[M];  //读取0 / 1对应的转移矩阵
int lft[M];                         //左子集合
int rgt[M];                         //右子集合
int QlistAdjust[M];                 //状态序列，记录的是DFA状态号
bool visit[M];                      //标记为已经访问
bool ac[M];                         //接受状态集合

int cnt, n, q, f;
// 将十进制p转化为二进制位对应的下标
int indexOfBinary(int p){
    int x = 1;
    if(p == 1)
        return 0;
    int i = 0;
    while(++i)
    {
        x <<= 1;
        if(p == x)
            return i;
    }
    return 0;
}
// a:sum , b：状态号
int travel(int a, int b){
    while(b)
    {
        int x = b&(-b);                     // b的一个状态x = q
        if(!(a&x))                          // 如果a&x = 0,表示sum中不含x状态，用 ^ 添加
            a ^= x;             
        b ^= x;                             // 剔除b中的的x状态
    }
    return a;                               // 返回a的结果，表示b能到达的子集合
}
// 搜索状态图，从起始位置p开始
void DFS(int p){
    Qlist[cnt] = p;
    int lsum = 0, rsum = 0;
    while(p)
    {
        int x = p&(-p);                     // 选择p的一个状态，我们才用与上p的补运算可以取出最后一个为1的位
        int y = indexOfBinary(x);           // 状态x的下标位置
        lsum = travel(lsum, transTable0[y]);// 经过0到达的子集合
        rsum = travel(rsum, transTable1[y]);// 经过1到达的子集合
        p ^= x;                             // 迭代，p =p^x 剔除已经搜索的状态x，也就是最后一位
    }

    lft[cnt] = lsum;                        // 将DFA中的状态：δ(qcnt，0)保存
    rgt[cnt] = rsum;                        // 将DFA中的状态：δ(qcnt，1)保存
    cnt++;                                  // 指针移动到下一个DFA状态
    if(!visit[lsum])                        // 如果lsum还没有被访问，则要迭代访问lsum
        visit[lsum] = 1, DFS(lsum);
    if(!visit[rsum])                        // 同上
        visit[rsum] = 1, DFS(rsum);           
}

int main()
{
    int t;                                  // t个测试数据
    scanf("%d", &t);                        
    while(t--)                              // 输入测试数据
    {
        scanf("%d%d%d", &n, &q, &f);        // 状态数,起始状态集合,接受状态集合的特征串对应的整数
        for(int i = 0; i < n; i++)          // 输入转移矩阵0 / 1
            scanf("%d", &transTable0[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &transTable1[i]);
        cnt = 0;
        memset(visit, 0, sizeof(visit));
        memset(ac, 0, sizeof(ac));
        visit[q] = 1;
        // 从起始状态开始搜索状态图
        DFS(q);

        // 遍历标记接收状态集合，sum表示当前接受状态个数
        int sum = 0;    
        for(int i = 0; i < cnt; i++)
            if(Qlist[i]&f) ac[i] = 1, sum++;    // 标记接受状态
        for(int i = 0; i < cnt; i++)
            QlistAdjust[Qlist[i]] = i;          // 将ans记录的NFA号调整到DFA上来 
        printf("%d %d %d\n", cnt, sum, 0);      // DFA的状态数，接受状态数，起始状态的编号
        for(int i = 0, j = 0; i < cnt; i++){    // 接收状态的编号
            if(ac[i])
            {
                if(j)   printf(" ");
                printf("%d", i);
                j++;
            }
        }
        printf("\n");
        for(int i = 0; i < cnt; i++) {          // δ（qi，0）→ui
            if(i)   printf(" ");
            printf("%d", QlistAdjust[lft[i]]);
        }
        printf("\n");
        for(int i = 0; i < cnt; i++){           // δ（qi，1）→vi
            if(i) printf(" ");
            printf("%d", QlistAdjust[rgt[i]]);
        }
        printf("\n");
    }
    return 0;
}