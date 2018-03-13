/**********************
author: yomi
date: 18.2.24
ps: ��������治�ᡣ   sort(start,end,���򷽷�)                                         j
����һ�ε�������sort(a, a+i+2);   3 1 2 8    7    5     9 4 6 0
sort(a, a+n)---> 0~n-1            1 2 3 7    8    5     9 4 6 0
so,                                          i    i+1
sort(a, a+i+2)---> 0~i+1

�Ƚ�iָ���м�����������������Ǵ�С����˳������һ���±꣬�ٽ�jָ���i+1��ʼ��
��һ��������a[j] == b[j]���±꣬���j˳���������±�n��˵���ǲ�������
����һ�ε�������sort(a, a+i+2);����˵���ǹ鲢���򡣹鲢����ͱ����м������ˣ�
ֱ�Ӷ�ԭ�������н���ģ��鲢ʱ��Ĺ鲢���̣�i��0��n/k��
ÿ��һ�ζε�sort(a + i * k, a + (i + 1) * k);
�������ǻ������ʣ�ಿ�ֵ�sort(a + n / k * k, a + n);������һ�ι鲢�Ĺ��̡�
ֱ����һ�η���a��˳���b��˳����ͬ�����ٹ鲢һ�Σ�Ȼ���˳�ѭ����
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
