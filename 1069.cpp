/**********************
author: yomi
date: 18.2.19
ps: ��ΪAC����
    �ܽ᣺
    ���Ե�3��4 WA
    mod k == 1   �����ܳ䵱ȡk���������
    ����˵ start = 3  ʱ  ----->    3+3 = 6
    ������ȡ�ཫȡ��7
    ��ôʹ�����򡣡���
    Ȼ�� ���� ���Ե�3 WA
    �������ص㣺
    ������˳��ȡ��һλ������
    ��д�ˡ�Ҫ������˼ά���ƣ��͵�ɾ��д��Ĵ��룬���㿪ʼ��
    �ܼ򵥵�һ���⣬��Ȼĥ����ô�á�ľ��ľ�¡��������ͺ��ˡ�
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
