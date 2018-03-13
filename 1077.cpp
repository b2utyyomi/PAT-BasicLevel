/**********************
author: yomi
date: 18.2.21
ps:所有其他组的评分中，去掉一个最高分和一个最低分，
剩下的分数取平均分记为 G1；老师给这个组的评分记为 G2。
该组得分为 (G1+G2)/2，最后结果四舍五入后保留整数分.
题目保证老师的评分都是合法的，并且每个组至少会有3个来自同学的合法评分。

总结： 题目很简单 但是我居然理解错了题意，耽误了好一会儿。
    每个组至少会有3个来自同学的合法评分。这样就是确保能够去掉一个最低分和一个最高分嘛。
    然而， 我理解成了如果剩三个同学的话就不用去掉最低分和高了， 还能行不？ 真是害怕。
**********************/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, full;
    cin >> n >> full;
    int tea;
    int group[n-1];
    int flag1 = 0;
    int flag2 = 0;
    int sum;
    for(int i=0; i<n; i++){
        flag1=0, flag2 = 0;
        cin >> tea;
        for(int j=0; j<n-1; j++){
            cin >> group[j];
            if(group[j] < 0){
                flag1++;
            }
            else if(group[j] > full){
                flag2++;
            }
        }
        sort(group, group+n-1);
        int sum = 0;
        int t = n-1-flag1-flag2;
        t -= 2;
        for(int j=flag1+1; j<n-1-flag2-1; j++){
            sum += group[j];
        }

        double ans1 = sum*1.0/t;
//        if(ans1-sum/t>=0.5){
//            sum = sum/t+1;
//        }
//        else
            sum = sum/t;
        tea += sum;
        ans1 = tea*1.0/2;
        if(ans1-tea/2>=0.5)
            tea = tea/2+1;
        else
            tea = tea/2;
        cout << tea;
        if(i!=n-1)
            cout << endl;
    }
    return 0;
}

/**
6 50
42 49 49 35 38 41
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29

*/
