/**********************
author: yomi
date: 18.1.31
ps: 被超时折磨的不行了，
搜了题解，
原来是思路跑偏了
看看大神的代码， 感慨自己菜如狗。
没事没事， 看我杰尼龟进化！！！

————————每K个结点反转——————————
————————而不是只反转前k个——————

答应我， 逐字读题好么？
**********************/
#include <iostream>
#include <algorithm>
#include<cstdio>
using namespace std;
int main() {
    int first, k, n, temp;
    cin >> first >> n >> k;
    int data[100005], next[100005], list[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    int sum = 0;//不一定所有的输入的结点都是有用的，加个计数器
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    for (int i = 0; i < sum/k; i++)/// 1 2 3 4 5 6     -----》    4 1        2 3      5 1        6 1
        reverse(begin(list) + i*k, begin(list) + i*k + k);
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
    printf("%05d %d -1", list[sum - 1], data[list[sum - 1]]);
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

struct node
{
    int addr;
    int data;
    int next;
}node1;
*/
/// use vector to try again   ------>  TLE+WA
/*
int main()
{
    vector<node>e, d, f;
    int start, n, m;
    //cin >> start >> n >> m;
    scanf("%d%d%d", &start, &n, &m);
    if(start == -1){
        printf("-1");
    }
    else{
            for(int i=0; i<n; i++){
            //cin >> d[i].addr >> d[i].data >> d[i].next;

            scanf("%d%d%d", &node1.addr, &node1.data, &node1.next);
            d.push_back(node1);
        }

        int cnt = 0;
        //cout << "1" << endl;
        //for(vector<node>::iterator iter=d.begin(); iter!=d.end(); ++iter){
        for(int i=0; i<n; i++){
            if(d[i].addr == start){
                e.push_back(d[i]);
                break;
            }
        }
        //cout << "1" << endl;
        while(e.size() != n){
            int  i = e.size()-1;
            for(int j=0; j<d.size(); ++j){

                if(e[i].next == d[j].addr){
                    e.push_back(d[j]);
                }
            }

        }

        //cout << "1" << endl;
        //reverse(e.begin(), e.begin()+m);
        int j = 0;
        for(int i=m-1;i>=0; i--){
            d[j++] = e[i];
        }
        int t = 0;
        for(int i=0;i<j; i++){
            e[t++] = d[i];
        }
        for(int i=0; i<n; i++){
            if(i+1<n)
                e[i].next = e[i+1].addr;
            else
                e[i].next = -1;
        }

        for(int i=0; i<n; ++i){
            printf("%05d %d ", e[i].addr, e[i].data);
            if(e[i+1].addr>=0 && i+1<n)
                printf("%05d\n", e[i+1].addr);
            else
                printf("-1\n");
            //cout <<  e[i].addr << ' ' << e[i].data << ' ' << e[i].next;
        }


    }

    return 0;
}
*/
/* TLE + WA
struct node
{
    int addr;
    int data;
    int next;
}d[100010], e[100010];

int main()
{
    int start, n, m;
    //cin >> start >> n >> m;
    scanf("%d%d%d", &start, &n, &m);
    for(int i=0; i<n; i++){
        //cin >> d[i].addr >> d[i].data >> d[i].next;
        scanf("%d%d%d", &d[i].addr, &d[i].data, &d[i].next);
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(d[i].addr == start){
            e[cnt++] = d[i];
            break;
        }
    }

    while(cnt<n){///n我竟然写成6
        for(int i=0; i<n; i++){
            if(d[i].addr == e[cnt-1].next){///cnt-1
                //cout << d[i].addr << ' ' << e[cnt].next << endl;
                e[cnt++] = d[i];
            }
        }
    }

    int j = 0;
    for(int i=m-1;i>=0; i--){
        d[j++] = e[i];
    }
    int t = 0;
    for(int i=0;i<j; i++){
        e[t++] = d[i];
    }
    for(int i=0; i<n; i++){
        if(i+1<n)
            e[i].next = e[i+1].addr;
        else
            e[i].next = -1;
    }

    for(int i=0; i<n; i++){
        printf("%05d %d ", e[i].addr, e[i].data);
        if(e[i].next>=0)
            printf("%05d\n", e[i].next);
        else
            printf("-1");
        //cout <<  e[i].addr << ' ' << e[i].data << ' ' << e[i].next;

    }
    return 0;
}
*/
/*
00100 6 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/









