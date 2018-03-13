/**********************
author: yomi
date: 18.1.
ps:这眼神儿，四个数组开了100010，一个却开了1000，
我哪能不知道错误，愣是没看见呐，WA了一篇，OMG。
**********************/
#include <iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;

struct student
{
    char num[10];//若是开大小正好的数组,将会10000001S
    int de;
    int cai;
}stu[100010], s1[100010], s2[100010], s3[100010], s4[100010];
int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;
int cnt4 = 0;

/*   创造了一个神奇的BUG
int cmp(const void *a,const void *b)
{
    int sum1 = ((student*)a)->de + ((student*)a)->cai;
    int sum2 = ((student*)b)->de + ((student*)b)->cai;
    int de1 = ((student*)a)->de;
    int de2 = ((student*)b)->de;
    char num1[8];
    char num2[8];
    strcpy(num1, ((student*)a)->num);
    strcpy(num2, ((student*)b)->num);
    if(sum1!=sum2)
         return sum2>sum1?1:-1;
    else if(de1!=de2)
         return de1-de2;
    else
        return strcmp(num1,num2)==-1?1:-1;
}
*/
int cmp(student a, student b)
{
    int sum1 = a.de+a.cai;
    int sum2 = b.de+b.cai;
    if(sum1!=sum2){
        return sum1>sum2;
    }
    else if(a.de != b.de){
        //cout << a.de << ' ' << b.de << endl;
        return a.de>b.de;
    }
    else{
        return strcmp(a.num, b.num)<0;
    }

}
int main()
{
    int n, l, h;
    //cin >> n >> l >> h;
    scanf("%d%d%d", &n, &l, &h);
    for(int i=0; i<n; i++){
        //cin >> stu[i].num >> stu[i].de >> stu[i].cai;
        scanf("%s%d%d",stu[i].num, &stu[i].de, &stu[i].cai);
        if(stu[i].de >= h && stu[i].cai >= h){
            s1[cnt1++] = stu[i];
        }
        else if(stu[i].de >= h && stu[i].cai < h && stu[i].cai >= l){
            s2[cnt2++] = stu[i];
        }
        else if(stu[i].de < h && stu[i].de >= l&& stu[i].cai < h && stu[i].cai >= l && stu[i].de >= stu[i].cai){
            s3[cnt3++] = stu[i];
        }
        else if(stu[i].de >= l&& stu[i].cai >= l){
            s4[cnt4++] = stu[i];
        }
    }

    sort(s1, s1+cnt1, cmp);
    sort(s2, s2+cnt2, cmp);
    sort(s3, s3+cnt3, cmp);
    sort(s4, s4+cnt4, cmp);
    printf("%d\n", cnt1+cnt2+cnt3+cnt4);
    for(int i=0; i<cnt1; i++){
        printf("%s %d %d\n", s1[i].num, s1[i].de, s1[i].cai);
    }
    //cout << endl;
    for(int i=0; i<cnt2; i++){
        printf("%s %d %d\n", s2[i].num, s2[i].de, s2[i].cai);
    }
    //cout << endl;
    for(int i=0; i<cnt3; i++){
        printf("%s %d %d\n", s3[i].num, s3[i].de, s3[i].cai);
    }
    //cout << endl;
    for(int i=0; i<cnt4; i++){
        printf("%s %d %d", s4[i].num, s4[i].de, s4[i].cai);
        if(i!=cnt4-1)
            printf("\n");
    }

    return 0;
}
