/**********************
author: yomi
date: 18.1.26
ps:
**********************/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    char a[100010], b[100010];

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    int win_a = 0, lose_a = 0, equ_a = 0;
    int win_b = 0, lose_b = 0, equ_b = 0;
    int cnt1_b = 0, cnt1_c = 0, cnt1_j = 0;
    int cnt2_b = 0, cnt2_c = 0, cnt2_j = 0;
    for(int i=0; i<n; i++){
        if((a[i] == 'B' && b[i] == 'C')||(a[i] == 'C' && b[i] == 'J')||(a[i] == 'J' && b[i] == 'B')){
            win_a++;
            if(a[i] == 'B')
                cnt1_b++;
            else if(a[i] == 'C')
                cnt1_c++;
            else if(a[i] == 'J')
                cnt1_j++;
        }

        else if((a[i] == 'C' && b[i] == 'B')||(a[i] == 'J' && b[i] == 'C')||(a[i] == 'B' && b[i] == 'J')){
            win_b++;
            if(b[i] == 'B')
                cnt2_b++;
            else if(b[i] == 'C')
                cnt2_c++;
            else if(b[i] == 'J')
                cnt2_j++;
        }

        else if((a[i] == 'B' && b[i] == 'B')||(a[i] == 'C' && b[i] == 'C')||(a[i] == 'J' && b[i] == 'J'))
            equ_a++;
    }
    cout << win_a << ' ' << equ_a << ' ' << win_b << endl;
    cout << win_b << ' ' << equ_a << ' ' << win_a << endl;

    if(cnt1_b >= cnt1_c && cnt1_b >= cnt1_j){
        cout  << 'B' << ' ';
    }
    else if(cnt1_c >= cnt1_b && cnt1_c >= cnt1_j){
        cout  << 'C' << ' ';
    }
    else if(cnt1_j >= cnt1_c && cnt1_j >= cnt1_b){
        cout  << 'J' << ' ';
    }
    if(cnt2_b >= cnt2_c && cnt2_b >= cnt2_j){
        cout  << 'B';
    }
    else if(cnt2_c >= cnt2_b && cnt2_c >= cnt2_j){
        cout  << 'C';
    }
    else if(cnt2_j >= cnt2_c && cnt2_j >= cnt2_b){
        cout  << 'J';
    }
    return 0;
}
