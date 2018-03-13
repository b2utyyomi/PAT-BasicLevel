/**********************
author: yomi
date: 18.2.8
ps:
**********************/
#include <iostream>

using namespace std;

struct student
{
    string num;
    int a;
    int b;
}stu[1010];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> stu[i].num >> stu[i].a >> stu[i].b;
    }
    int m, data;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> data;
        for(int j=0; j<n; j++){
            if(stu[j].a == data){
                cout << stu[j].num << ' ' << stu[j].b;
            }
        }
        if(i!=m-1)
            cout << endl;
    }
    return 0;
}








