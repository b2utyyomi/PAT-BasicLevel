/**********************
author: yomi
date: 18.2.19
ps: 此为AC代码
    总结：
    测试点3、4 WA
    mod k == 1   并不能充当取k间隔的条件
    比如说 start = 3  时  ----->    3+3 = 6
    而利用取余将取到7
    多么痛的领悟。。。
    然而 还是 测试点3 WA
    下面是重点：
    跳过他顺次取下一位。。。
    重写了、要想跳出思维定势，就得删掉写完的代码，从零开始，
    很简单的一道题，居然磨了这么久。木事木事。多练练就好了。
***********************/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int m, k, start;
    cin >> m >> k >> start;
    map<string, bool>visited;
    string name[1010];
    for(int i=1; i<=m; i++){
        cin >> name[i];
        visited[name[i]] = false;
    }
    int cnt = 1;
    int flag = 1;
    int flag1 = 0;
    for(int i=start; i<=m;){
        if(visited[name[i]] == false){
            if(flag1)
                cout << endl;
            flag1++;
            flag = 0;
            visited[name[i]] = true;
            cout << name[i];
            i += k;
        }
        else{
            flag = 0;
            i++;
        }
    }
    if(flag){
        cout << "Keep going...";
    }
    return 0;
}


/**
23 3 3
Imgonnawin!
PickMe
PickMeMeMeee
out:   PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
out:   TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
abc
TryAgainAgain
TryAgainAgain
def
out:   def
qqq
TryAgainAgain
TryAgainAgain
qqq
qqq
out:   qqq
qqq
lll
aaa
aaa
out:   aaa

bbb

PickMeMeMeee
TryAgainAgain
def
qqq
aaa

23 3 3
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
abc
TryAgainAgain
TryAgainAgain
def
qqq
TryAgainAgain
TryAgainAgain
fff
qqq
qqq
lll
ddd
aaa
bbb

PickMeMeMeee
TryAgainAgain
abc
def
fff
lll
bbb



**/
