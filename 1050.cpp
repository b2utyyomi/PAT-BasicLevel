/**********************
author: yomi
date: 18.2.11
ps: 用了很暴力的方法 果然TLE
这时候我们首先要做的是什么？ 对！！！cin改成scanf 结果没有用
那就是方法问题了，
仔细观察行数为2、3、4、5的矩阵， 不难发现，、
螺旋矩阵的层数level与行数m有着 level = m/2+m%2的关系！！！

**********************/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

int cmp(int a, int b)
{
    return a>b;
}
void func(int &a, int n)
{
    int sqr = sqrt(n);
    for(int i=sqr; i>=1; i--){
        if(n%i == 0){
            a = i;
            return;
        }
    }
    return;
//    for(int i=int(sqr); i>=1; i--){    ///TLE
//        for(int j=int(sqr); j<=n; j++){ ///这n^2的复杂度不是可以优化一下吗？只算一个行数或列数就行了
//            if(i*j == n){
//                a = j;
//                b = i;
//                return;
//            }
//        }
//    }
}
int main()
{
    int n;
    int a[10010];

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n, cmp);
    int m, t;
    func(t, n);
    m = n/t;
    int b[m][t]; /// 大概正确答案不能开这个数组吧 7887 就崩掉了 那这样的话 计算完行列数之后再开数组
//    vector<vector<int> > b(m, vector<int>(t));
//    b.clear();
    //cout << m << ' ' << t ;
/*
    for(int j=0; j<t; j++)
        b[0][j] = a[j];
    for(int i=1; i<m; i++)
        b[i][t-1] = a[i+t-1];
    int cnt = 1;
    for(int j=t-2; j>=0; j--){
        b[m-1][j] = a[m-1+t-1+cnt];
        cnt++;
    }
    for(int i=m-2; i>=1; i--){
        b[i][0] = a[m+t-2+cnt];
        cnt++;
    }
    for(int j=1; j<t-1; j++){
        b[1][j] = a[m+t-2+cnt];
        cnt++;
    }
    for(int i=2; i<m-1; i++){
        b[i][t-2] = a[m+t-2+cnt];
        cnt++;
    }
*/
    ///*************************************
//
//    for(int j=0; j<t; j++)
//        b[0][j] = a[j];
//    for(int i=1; i<m; i++)
//        b[i][t-1] = a[i+t-1];
//    int cnt = 1;
//    int cnt1 = 2;
//    int cnt2 = 0;
//    int cnt3 = 1;
//    while(m+t-2+cnt<n){
//        for(int j=t-cnt1; j>=cnt2&&m+t-2+cnt<n; j--){
//            b[m-cnt3][j] = a[m-1+t-1+cnt];
//            cnt++;
//        }
//
//        for(int i=m-cnt1; i>cnt2&&m+t-2+cnt<n; i--){
//            b[i][cnt2] = a[m+t-2+cnt];
//            cnt++;
//
//        }
//        for(int j=cnt3; j<t-cnt3&&m+t-2+cnt<n; j++){
//            b[cnt3][j] = a[m+t-2+cnt];
//            cnt++;
//        }
//        for(int i=cnt1; i<m-cnt3&&m+t-2+cnt<n; i++, cnt1++){
//            b[i][t-cnt1] = a[m+t-2+cnt];
//            cnt++;
//        }
//        cnt2++;
//        cnt3++;
//
//    }
    int cnt = 0;
    int level = m / 2 + m % 2;
    for (int i = 0; i < level; i++) {
        for (int j = i; j <= t - 1 - i && cnt < n; j++) {
            b[i][j] = a[cnt++];
        }
        for (int j = i + 1; j <= m - 2 - i && cnt < n ; j++) {
            b[j][t - 1 - i] = a[cnt++];
        }
        for (int j = t - i - 1; j >= i && cnt < n ; j--) {
            b[m - 1 - i][j] = a[cnt++];
        }
        for (int j = m - 2 - i; j >= i + 1 && cnt < n ; j--) {
            b[j][i] = a[cnt++];
        }
    }



    for(int i=0; i<m; i++){
        for(int j=0; j<t; j++){
            printf("%d",b[i][j]);
            if(j<t-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

/*
16
43 23 78 67 45 90 87 65 88 66 12 10 33 77 22 11
*/
