/**********************
author: yomi
date: 18.2.24
ps: 这道题是真不会。   sort(start,end,排序方法)                                         j
再下一次的序列是sort(a, a+i+2);   3 1 2 8    7    5     9 4 6 0
sort(a, a+n)---> 0~n-1            1 2 3 7    8    5     9 4 6 0
so,                                          i    i+1
sort(a, a+i+2)---> 0~i+1

先将i指向中间序列中满足从左到右是从小到大顺序的最后一个下标，再将j指向从i+1开始，
第一个不满足a[j] == b[j]的下标，如果j顺利到达了下标n，说明是插入排序，
再下一次的序列是sort(a, a+i+2);否则说明是归并排序。归并排序就别考虑中间序列了，
直接对原来的序列进行模拟归并时候的归并过程，i从0到n/k，
每次一段段得sort(a + i * k, a + (i + 1) * k);
最后别忘记还有最后剩余部分的sort(a + n / k * k, a + n);这样是一次归并的过程。
直到有一次发现a的顺序和b的顺序相同，则再归并一次，然后退出循环～
**********************/
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int *a = new int [n];
    int *b = new int [n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    for (j = i + 1; a[j] == b[j] && j < n; j++);
    if (j == n) {
        cout << "Insertion Sort" << endl;
        sort(a, a + i + 2);
    } else {
        cout << "Merge Sort" << endl;
        int k = 1, flag = 1;
        int cnt = 0;
        while(flag) {
            flag = 0;
            for (i = 0; i < n; i++) {
                if (a[i] != b[i])
                    flag = 1;
            }
            k = k * 2;
            for (i = 0; i < n / k; i++)
                sort(a + i * k, a + (i + 1) * k);
            sort(a + n / k * k, a + n);
            cnt++;
        }
        cout << endl << cnt << endl;
    }
    for (j = 0; j < n; j++) {
        if (j != 0) printf(" ");
        printf("%d", a[j]);
    }

    delete [] a;
    delete [] b;
    return 0;
}
/**
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
*/
