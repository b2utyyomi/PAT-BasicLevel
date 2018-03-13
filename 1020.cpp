/**********************
author: yomi
date: 18.1.28
ps:又是WA了很多遍， 库存量是正数, 所以可能是float，而我用了int.
**********************/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

struct yuebing
{
    int no;
    float store;
    float price;
    float single_price;
}cake[1010];
int cmp(yuebing a, yuebing b)
{
    return a.single_price>b.single_price;
}
int main()
{
    int n, m;
    cin >> n >> m ;
    for(int i=0; i<n; i++){
        cake[i].no = i;
        cin >> cake[i].store;
    }
    for(int i=0; i<n; i++){
        cin >> cake[i].price;
    }
    for(int i=0; i<n; i++){
        cake[i].single_price = cake[i].price*1.0/cake[i].store;
        //cout << cake[i].single_price << endl;
    }

    sort(cake, cake+n, cmp);
    float sum = 0.0;
    float s = m;
    for(int i= 0; i<n; i++){
        if(s >= cake[i].store){
            s -= cake[i].store;
            sum += cake[i].price;
        }
        else if(s < cake[i].store){
            sum += cake[i].single_price*s;
            //sum += s*1.0/cake[i].store*cake[i].price;
            break;
        }
    }
    printf("%.2f", sum);
    return 0;
}



























