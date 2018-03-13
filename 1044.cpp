/**********************
author: yomi
date: 18.2.9
ps:
**********************/
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>
using namespace std;

int main()
{
    string be[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string af[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int T;
    cin >> T;
    string s;

    getline(cin, s);
    for(int j=0; j<T; j++){
        stringstream is;
        getline(cin, s);
        if(isdigit(s[0])){
            is.str(s);
            int n;
            is >> n;
            if(n == 0){
                cout << "tret";
            }
            else if(n/13 == 0){
                cout << be[n-1];
            }
            else if(n/13 && n%13 == 0){
                cout << af[n/13-1];
            }
            else{
                cout << af[n/13-1] << ' ' << be[n%13-1];
            }
        }
        else{
            string a = "", b = "";
            int aa = 0, bb = 0;
            int sum = 0;
            is.str(s);
            is >> a;
            is >> b;
//            cout << "s:" << s << endl;
//            cout << "a&&b:" << a << " " << b << endl;
            if(a == "tret"){
                sum += 0;
            }
            else{
                int k;
                for(k=0; k<12; k++){
                    if(be[k] == a){
                        aa = k+1;
                        sum = aa;
                        break;
                    }
                }
                if(k==12){
                    for(int i=0; i<12; i++){
                        if(af[i] == a){
                            aa = i+1;
                            break;
                        }
                    }
                    int t;
                    for(t=0; t<12; t++){
                        if(be[t] == b){
                            bb = t+1;
                            sum = 13*aa+bb;
                            break;
                        }
                    }
                    //cout << aa << endl;
                    if(t == 12){
                        sum = 13*aa;
                    }

                }

            }
            cout << sum ;


        }
        if(j!=T-1){
            cout << endl;
        }

    }
    return 0;
}

/**
4
29
5
elo nov
tam tret

hel mar
may
115
13

**/
