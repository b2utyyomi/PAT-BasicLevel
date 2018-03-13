/**********************
author: yomi
date: 18.2.21
ps:
**********************/
#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n, m, b, t;
    string answer[1010][110];
    string right[1010];
    int mark[1010];
    char ch;
    float goss = 0.0;
    int flag = 0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> mark[i] >> b >> t;
        for(int j=0; j<t; j++){
            cin  >> ch;
            right[i] += ch;
        }
    }

    for(int i=0; i<n; i++){
        goss = 0.0;
        for(int ii=0; ii<m; ii++){
            cin >> ch;
            cin >> t;
            for(int j=0; j<t; j++){
                cin >> ch;
                answer[i][ii] += ch;
            }
            cin >> ch;
            if(answer[i][ii] == right[ii]){
                goss += mark[ii];
            }
            else{
                int k;
                for(k=0; k<answer[i][ii].length(); k++){
                    if(right[ii].find(answer[i][ii][k]) == -1){
                        break;
                    }
                }
                if(k == answer[i][ii].length()){
                    goss += mark[ii]*1.0/2;
                }
                else{
                    flag = 1;
                }

            }
        }
        //cout << goss << endl;
        printf("%.1f\n", goss);
    }
    int max_ = 0;
    if(!flag)
        cout << "Too simple";
    else{
        int cnt[1010][6];
        memset(cnt, 0, sizeof(cnt));
        for(int ii=0; ii<m; ii++){
            for(int i=0; i<n; i++){
                for(int k=0; k<answer[i][ii].length(); k++){
                    if(right[ii].find(answer[i][ii][k]) == -1){
                        cnt[ii][answer[i][ii][k]-'0'-49]++;
                        //cout << answer[i][ii][k] << endl;
                        max_ = max(max_, cnt[ii][answer[i][ii][k]-'0'-49]);
                    }
                }
                //cout << right[ii].length() << endl;
                for(int k=0; k<right[ii].length(); k++){
                    if(answer[i][ii].find(right[ii][k]) == -1){///BUG: Íü¼ÇÐ´[k]ÁË
                        cnt[ii][right[ii][k]-'0'-49]++;
                        //cout << right[ii][k] << endl;
                        max_ = max(max_, cnt[ii][right[ii][k]-'0'-49]);
                    }
                }
            }
        }
        int cn = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<6; j++){
                if(cnt[i][j] == max_){
                    if(cn)
                        cout << endl;
                    cout <<max_ << ' ' << i+1 << "-" << char(j+49+'0');
                    cn++;
                }
            }
        }
    }

    return 0;
}
/**
3 1
5 3 2 b c
(2 a c)
(2 a b)
(1 c)
*/
