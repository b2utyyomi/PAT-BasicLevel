/**********************
author: yomi
date: 18.1.21
ps:��������Ѫ���ᰡ �ҽ��˲��¶�ʮ�� ͦ�򵥵��� ����������
**********************/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string s1[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
///                  0       1      2      3      4
///
int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    string Day = "";
    char HH;
    int cnt = 1;
    int cnt1 = 1;
    int f = 0;
    int len = min(a.length(), b.length());
    for(int i=0; i<len; i++){///��ȫû��Ҫ˫��forѭ��
        if(a[i] == b[i] && a[i]>='A' && a[i]<='G' && f == 0){///a[i]>='A' && a[i]<='Z' �δ���:s1[a[i]-'A']����Խ��
            ///cout << a[i]-'A';
            Day += s1[a[i]-'A'];
            f = 1;
        }
        else if(f && a[i] == b[i] && a[i]>='0' && a[i]<='9'){
           HH  = a[i];
           break;
        }
        else if(f && a[i] == b[i] && a[i]>='A' && a[i]<='N'){
           HH  = a[i];
           break;
        }

    }
    cout << Day << ' ';
    if(HH >='0' && HH<='9')
        printf("0%d", HH-'0');
    else
        cout << HH-'A'+10;
    cout << ":";
    int len1 = min(c.length(), d.length());
    for(int i=0; i<len1; i++){
        if(c[i] == d[i] && ((c[i]>='a' && c[i]<='z')||(c[i]>='A' && c[i]<='Z'))){
            if(i>=0 && i<=9)
                printf("0%d",i);
            else
                printf("%d", i);
            break;
        }
    }
    return 0;
}

/*
2984akDfkkkkggEdsb
3485djDkxh4hhGE
d&Hyscvnm
s&hgsfdk


*/
