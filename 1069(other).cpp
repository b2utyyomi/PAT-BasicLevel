// 1069.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdio>
#include<string>

using namespace std;

bool judge(string str, const vector<string>& v);//判断该名称中奖与否，中奖返回真
void get_win_name(vector<string>& v, vector<string>& win, int M, int N, int S);//获取获奖名称并存入win中
void show_win_name(const vector<string>& win);//打印获奖名称

int main()
{
    int M, N, S;
    vector<string> v,win;//v存储输入的名称，win存储获奖的名称
    string name;

    cin >> M >> N >> S;
    getchar();//读取缓冲区中的回车

    if (M >= S)
    {
        //读取并存入容器
        for (int i = 1; i <= M; ++i)
        {
            getline(cin, name);

            v.push_back(name);
        }

        get_win_name(v, win, M, N, S);//获取获奖名称并存入win中

        show_win_name(win);//打印获奖名称
    }
    else//无人获奖
        cout << "Keep going..." << endl;

    return 0;
}

//判断该名称中奖与否，中奖返回真
bool judge(string str,const vector<string>& v)
{
    if (find(v.begin(), v.end(), str) != v.end())
        return 1;

    return 0;
}

//获取获奖名称并存入win中
void get_win_name(vector<string>& v,vector<string>& win,int M,int N,int S)
{
    vector<string>::iterator x = v.begin(), end = v.end();

    //指向起始中奖名称
    for (int i = 1; i < S; ++i)
        ++x;

    for (int i = S; i <= M; ++x, ++i)
    {
        //如果该名称之前没中奖
        if (!judge(*x, win))
        {
            win.push_back(*x);//将名称存入中奖名单

            //中奖后跳过中间的人数直达下一个中奖名称
            for (int j = 1; j < N && x != end; ++j)
                ++x, ++i;
        }

        if (x == end)//如果一直出现的都为中过奖的，一直循环到最后，就终止
            break;
    }
}

//打印获奖名称
void show_win_name(const vector<string>& win)
{
    vector<string>::const_iterator begin1 = win.cbegin(), end1 = win.cend();

    for (; begin1 != end1; ++begin1)
        cout << *begin1 << endl;
}
