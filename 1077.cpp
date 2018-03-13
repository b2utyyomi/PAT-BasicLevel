/**********************
author: yomi
date: 18.2.21
ps:����������������У�ȥ��һ����߷ֺ�һ����ͷ֣�
ʣ�µķ���ȡƽ���ּ�Ϊ G1����ʦ�����������ּ�Ϊ G2��
����÷�Ϊ (G1+G2)/2������������������������.
��Ŀ��֤��ʦ�����ֶ��ǺϷ��ģ�����ÿ�������ٻ���3������ͬѧ�ĺϷ����֡�

�ܽ᣺ ��Ŀ�ܼ� �����Ҿ�Ȼ���������⣬�����˺�һ�����
    ÿ�������ٻ���3������ͬѧ�ĺϷ����֡���������ȷ���ܹ�ȥ��һ����ͷֺ�һ����߷��
    Ȼ���� �����������ʣ����ͬѧ�Ļ��Ͳ���ȥ����ͷֺ͸��ˣ� �����в��� ���Ǻ��¡�
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
