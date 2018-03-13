/**********************
author: yomi
date: 18.1.29
ps:
**********************/
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int powe(int n)
{
    int ans = 1;
    for(int i=0; i<n; i++){
        ans = 10*ans;
    }
    return ans;
}
int toint(string s)
{
    int sum = 0;
    int cnt = 0;
    for(int i=s.length()-1; i>=0; i--){
        sum += (s[cnt++]-'0')*powe(i);
    }
    return sum;
}
///[+-][1-9]"."[0-9]+E[+-][0-9]+
///+1.23400E-03
int main()
{
    string s;
    cin >> s;
    if(s[0] == '-')
        cout << '-';
        int pos = 0;
    for(int i=1; i<s.length(); i++){
        if(s[i] == 'E'){
            pos = i;
            break;
        }
    }

    string s1 = s.substr(1, pos-1);
    string s2 = s.substr(pos+2, s.length());
    string s3 = "";
    int n = toint(s2);///+1.23400E+03
    if(s[pos+1] == '-'){
        s1 = s1.replace(s1.find("."), 1, "");
        s3 += "0.";
        for(int i=0; i<n-1; i++)
            s3 += "0";
        s3 += s1;
    }
    else if(s[pos+1] == '+'){///-1.2E+10
        int j = s1.find(".");
        string s4 = s1.substr(j+1, s1.length());
        //cout << s4 << endl;
        s1 = s1.replace(s1.find("."), 1, "");
        //cout << s1 << endl;
        int len = s4.length();
        for(int i=0; i<min(n, len)+1; i++)
            s3 += s1[i];
        if(n<s4.length()){
            s3 += ".";
            s3 += s4.substr(n, s4.length());
        }
        else{
            for(int i=0; i<n-s4.length(); i++){
                s3 += "0";
            }
        }
    }
    cout << s3;
    return 0;
}


/*
int main()
{
    string s;
    while(1){
        cin >> s;
        if(s[0] == '-')
            cout << s[0];
        int k = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'E'){
                k = i;
                break;
            }
        }
        string s1 = s.substr(1, k-1);
        char ch = s[k+1];
        string s2 = s.substr(k+2, s.length()-1);
        int n = toint(s2);
        int location = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] == '.'){
                location = i;
                break;
            }
        }

        string s3 = "";
        if(ch == '+'){

            int l = s1.length();//+1.2340E+040
            int zero = s1.length()-location-1;
            if(zero <= n){
                for(int i=0; i<s1.length(); i++){
                    if(s1[i] == '.')
                        continue;
                    s3 += s1[i];
                }

                for(int i=0; i<n-zero; i++)
                    s3 += '0';
                cout << s3;
            }
            else{
                for(int i=0; i<location; i++){
                    s3 += s1[i];
                }
                for(int i=location+1; i<location+n+1; i++){
                    s3 += s1[i];
                }
                s3 += ".";
                for(int i=location+n+1+1; i<s1.length()+1; i++){
                    s3 += s[i];
                }
            }


        }
        else if(ch == '-'){
            int num = n-location;
            s1 = s1.replace(s1.find("."), 1, "");
            if(num >= 0){
                s3 += "0.";
                for(int i=0; i<num; i++){
                    s3 += '0';
                }

                s3 += s1;
            }
            else{
                for(int i=0; i<abs(num); i++){
                    s3 += s1[i];
                }
                s3 += ".";
                for(int i=abs(num); i<s1.length(); i++){
                    s3 += s1[i];
                }

        }




        }

        location = 0;
        for(int i=0; i<s3.length(); i++){
            if(s3[i] == '.'){
                break;
            }
            location++;

        }
        //cout << endl;
        //cout << s3 << endl;
        s1 = s3.substr(0, location);
        n = toint(s1);

//        cout << endl;
//        cout << s3 << endl;
//        cout << location << endl;
//        cout << s1 << endl;
        if(location == 1 && n == 0){
            cout << "0.";
            for(int i=2; i<s3.length(); i++){
                cout << s3[i];
            }
        }
        else if(location!=1 && n!=0 && location!=s3.length()){
            cout << n;
            for(int i=location; i<s3.length(); i++){
                cout << s3[i];
            }
        }
        else if(location != 1 && n == 0){
            cout << "0";
            for(int i=location; i<s3.length(); i++){
                cout << s3[i];
            }
        }
        else if(location == s3.length()){
            ;
        }
        else{//-0.0100E+3
            cout << n;
            for(int i=location; i<s3.length(); i++){
                cout << s3[i];
            }
        }
        cout << endl;

    }


    return 0;
}
*/
/*
+0.100E+3
+0.00
+0.100E+4
+0.000
+0.100E+4
+0.000
+0.100E+6
+0.00000
+0.00100E+6
+0.01000
-0.0100E+3
-0..010
+123.23E-2
+1.2323
+1.234E+2
+11..23
-1.22E+1
-11..2
-1.22E+5
-1122000
____________
+1.23400E+5
+1234000000
____________
-0.00123E-01
-.000123
____________
-0.0100E+1
-00.100
____________
-0.0100E+3
-0010.0
____________
*/
/*
+123.23E-2
+12323
*/
/*
+1.234E+2
+123
*/
/**
+1.23400E-03

-1.2E+10
*/
