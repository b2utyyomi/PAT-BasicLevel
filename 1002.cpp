#include<iostream>
#include <string>
using namespace std;
int main()
{
    string b[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string s;
    cin >> s;
    int sum = 0;
    for(int i=0; i<s.length(); i++){
        sum += s[i]-'0';
    }
    string a = "";
    while(sum){
        a += sum % 10;
        sum = sum /10;
    }

    for(int i=a.length()-1; i>=0; i--){
        cout << b[a[i]] ;
        if(i!=0)
            cout << ' ' ;

    }
    return 0;
}
