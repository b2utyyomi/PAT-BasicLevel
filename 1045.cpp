/**********************
author: yomi
date: 18.2.11
ps:��������س�ʱ��
1 3 2 4 5
1 2 3 4 5
���������о�һ�¿��Է���һ������
����֮��˳�򲻱������Ԫ�� Ȼ�󡣡��������ڲ����ˡ�����
2 4 3 1 5
1 2 3 4 5
��������� 3��������Ҫ��
û��Ҫ��set�� ��Ϊ�Ѿ��Ź�����
**********************/
#include <iostream>
#include <algorithm>
#include <string>
#include<set>
using namespace std;

int main()
{
    int a[100010], b[100010];
    set<int>s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n);
    int cnt = 0;
    //int s[100010];
    int ans = 0;

    for(int i=0; i<n; i++){

        if(a[i] == b[i] && b[i]>ans){

            s.insert(a[i]);

        }
        ans = max(ans, b[i]);
    }
    cout << s.size() << endl;
    for(set<int>::iterator iter=s.begin(); iter!=s.end(); ++iter){
        if(*iter == *s.rbegin()){
            cout << *iter;
            break;
        }
        cout << *iter << ' ';
    }
    cout << endl;//���Ե�2
    return 0;
}
