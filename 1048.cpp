/**********************
author: yomi
date: 18.2.10
ps:WA�˺ó�һ�������Ҫ������������ ɵ�����İ�ǰ�����ȥ����
��һǵ ��һ�� ����AC�ʲ��ߵ���һ���õ���
����⣬�����ǲ�λ����s1,s2������ȣ�Ȼ�������λ��ż��λ�ֱ������������
��ϸ���룬�Ͼ��Ǽ��ܣ����ȥ����ǰ���㣬��ô�Ժ�Ͳ�֪��ǰ��һ���м������ˣ�
�ǻ���ô����ѽ
**********************/
#include <iostream>
#include <string>
#include <cmath>
#include<sstream>
using namespace std;

int main()
{
    //while(1){
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s2.length();
    int len2 = s1.length();
    int c = abs(len1-len2);
    if(s1.length()>s2.length()){
        for(int i=0; i<c; i++){
            s2 = "0"+s2;
        }
    }
    else{
        for(int i=0; i<c; i++){
            s1 = "0"+s1;
        }
    }
//    cout << c << endl;
//
//    cout << s1 << ' ' << s2 << endl;
    int t = 1;
    for(int i=s2.length()-1; i>=0; i--,t++){
        if(t%2 == 0){
            int tmp =  (s2[i]-'0') - (s1[i]-'0') ;
            if(tmp < 0)
                tmp += 10;
            s2[i] = tmp+'0';
        }
        else{
            int tmp = ((s1[i]-'0') + (s2[i]-'0'))%13;
            //cout << tmp << endl;
            if(tmp == 10){
                s2[i] = 'J';
            }
            else if(tmp == 11){
                s2[i] = 'Q';
            }
            else if(tmp == 12){
                s2[i] = 'K';
            }
            else{
                s2[i] = tmp+'0';
            }

        }

    }

    cout << s2;
   /* ����ȥ��ǰ����
   stringstream is;
    is.str(s2);
    int a=0;
    string ss;
    if(s2[0]>='0' && s2[0]<='9'){
        is >> a;
        is >> ss;
    }

    else
        is >> ss;
    if(a==0 && ss.length() == 0)
        cout << a;
    else if(a>0)
      cout << a;
    if(ss.length()!=0)
        cout << ss;
    }*/
    //cout << s2;


    return 0;
}

///**
//1234567 368782971
//
//**/
