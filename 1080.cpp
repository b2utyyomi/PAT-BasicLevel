/**********************
author: yomi
date: 18.2.23
ps: 最后一个测试点WA 是个小BUG 三秒解决 乙级一刷毕业打卡
**********************/
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct people
{
    int b;
    int z;
    int m;
    int zp;
    string no;
}peo[30010];

int cmp(people a, people b)
{
    if(a.zp != b.zp){
        return a.zp>b.zp;
    }
    else{
        return a.no< b.no;
    }


}
int main()
{
    int n1, n2, n3;
    int mark;
    map<string, int>mmap;
    mmap.clear();
    map<string, bool>visited;
    for(int i=0; i<30010; i++){
        peo[i].b = -1;
        peo[i].z = -1;
        peo[i].m = -1;
    }
//    cout << mmap["1"] << endl; 默认值为0
    cin >> n1 >> n2 >> n3;
    int cnt1 = 0;
    for(int i=0; i<n1; i++){
        cin >> peo[cnt1].no >> mark;
        visited[peo[cnt1].no] = true;
        mmap[peo[cnt1].no] = cnt1;
        peo[cnt1].b = mark;
        cnt1++;
     }
    for(int i=0; i<n2; i++){
        cin >> peo[cnt1].no >> mark;
        if(visited[peo[cnt1].no]!=true){
            visited[peo[cnt1].no] = true;
            mmap[peo[cnt1].no] = cnt1;
            peo[cnt1].z = mark;
        }
        else{
            peo[mmap[peo[cnt1].no]].z = mark;
        }

        cnt1++;
    }
    for(int i=0; i<n3; i++){
        cin >> peo[cnt1].no >> mark;
        if(visited[peo[cnt1].no]!=true){
            visited[peo[cnt1].no] = true;
            //mmap.insert(make_pair(name[cnt1], cnt));
            mmap[peo[cnt1].no] = cnt1;
            peo[cnt1].m = mark;
        }
        else{
            peo[mmap[peo[cnt1].no]].m = mark;
        }
        cnt1++;
    }
    int cnt2 = 0;
    //cout << peo[mmap["a1903"]].b << endl;
    //multimap<string, int>mtmap;

    for(int i=0; i<cnt1; i++){
        int program = peo[i].b;
        int qizhong = peo[i].z;
        int qimo = peo[i].m;
        //cout << program << ' ' << qizhong << ' ' << qimo << endl;
        int p;
        if(qizhong > qimo){
            double pp =  0.4*qizhong+0.6*qimo;
            if(pp-int(pp)>=0.5){
                pp += 1;
            }
            p = (int)pp;
        }
        else{
            p = qimo;
        }
        peo[i].zp = p;


    }
    sort(peo, peo+cnt1, cmp);
    for(int i=0; i<cnt1; i++){
        int program = peo[i].b;
        int qizhong = peo[i].z;
        int qimo = peo[i].m;
        int p = peo[i].zp;
        if(program<200){
            continue;
        }
        else{

            if(p >= 60.0){
                if(cnt2)
                    cout << endl;
                cout << peo[i].no << ' ';
                cout << program << ' ';
                cout << qizhong << ' ';
                cout << qimo << ' ';
                cout << p;
                cnt2++;

            }

        }

    }
    return 0;
}

/**
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81

*/
