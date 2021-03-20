main():
    while(t--)                              
    {
        Input(DFA);                             // 输入DFA
        DFS();                                  // 搜索状态图
        for(int i = 0; i < cnt; i++)            // 任何包含接受状态的节点都是接受状态
            if(ans[i]&f)
                ac[i] = 1, sum++;
        for(int i = 0; i < cnt; i++)            // 调整序号
            change[ans[i]] = i;
        OutPut(DFA);                            // 输出DFA
    }

DFS(int p):
    while(p)
    {
        int x = p&(-p);                         // 选择p的一个状态，我们才用与上p的补运算可以取出最后一个为1的位
        int y = indexOfBinary(x);               // 状态x的下标位置
        lsum = travel(lsum, transTable0[y]);    // 经过0到达的子集合
        rsum = travel(rsum, transTable1[y]);    // 经过1到达的子集合
        p ^= x;                                 // 迭代，p =p^x 剔除已经搜索的状态x，也就是最后一位
    }

    lft[cnt] = lsum;                            // 将DFA中的状态：δ(qcnt，0)保存
    rgt[cnt] = rsum;                            // 将DFA中的状态：δ(qcnt，1)保存
    cnt++;                                      // 指针移动到下一个DFA状态
    if(!visit[lsum])                            // 如果lsum还没有被访问，则要迭代访问lsum
        visit[lsum] = 1, DFS(lsum);
    if(!visit[rsum])                            // 同上
        visit[rsum] = 1, DFS(rsum);         