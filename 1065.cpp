/**********************
author: yomi
date: 18.2.17
ps: �ֳ�ʱ�ˣ� ��ʵ�������֮ǰ�ķ�ת�������ƣ������϶���ʱ
    ��������i��Ӧj���������couple[i] = j, �Ĺ�֮���ǳ��� cin��scanf�������
    scanf��������stringѽ, �ĳ�char*���治���ף� ���ϸĳ�int, ���ʱ����һ�¸�ʽ��AC�ˡ�
**********************/
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>s3;
    set<int>s;
    map<int, int>couple;
    int a, b, c;
    for(int i=0; i<n; i++){
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++){

        scanf("%d", &c);
        s3.push_back(c);
    }

    for(int i=0; i<s3.size(); i++){
        int k = count(s3.begin(), s3.end(), couple[s3[i]]);
        if(k == 0)
            s.insert(s3[i]);
    }
    int cnt = 0;
    cout << s.size() << endl;
    for(set<int>::iterator iter=s.begin(); iter!=s.end(); ++iter){
        if(cnt)
            cout << ' ';
        printf("%05d", *iter);
        cnt++;
    }
    return 0;
}

/**
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
*/
