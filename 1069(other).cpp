// 1069.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdio>
#include<string>

using namespace std;

bool judge(string str, const vector<string>& v);//�жϸ������н�����н�������
void get_win_name(vector<string>& v, vector<string>& win, int M, int N, int S);//��ȡ�����Ʋ�����win��
void show_win_name(const vector<string>& win);//��ӡ������

int main()
{
    int M, N, S;
    vector<string> v,win;//v�洢��������ƣ�win�洢�񽱵�����
    string name;

    cin >> M >> N >> S;
    getchar();//��ȡ�������еĻس�

    if (M >= S)
    {
        //��ȡ����������
        for (int i = 1; i <= M; ++i)
        {
            getline(cin, name);

            v.push_back(name);
        }

        get_win_name(v, win, M, N, S);//��ȡ�����Ʋ�����win��

        show_win_name(win);//��ӡ������
    }
    else//���˻�
        cout << "Keep going..." << endl;

    return 0;
}

//�жϸ������н�����н�������
bool judge(string str,const vector<string>& v)
{
    if (find(v.begin(), v.end(), str) != v.end())
        return 1;

    return 0;
}

//��ȡ�����Ʋ�����win��
void get_win_name(vector<string>& v,vector<string>& win,int M,int N,int S)
{
    vector<string>::iterator x = v.begin(), end = v.end();

    //ָ����ʼ�н�����
    for (int i = 1; i < S; ++i)
        ++x;

    for (int i = S; i <= M; ++x, ++i)
    {
        //���������֮ǰû�н�
        if (!judge(*x, win))
        {
            win.push_back(*x);//�����ƴ����н�����

            //�н��������м������ֱ����һ���н�����
            for (int j = 1; j < N && x != end; ++j)
                ++x, ++i;
        }

        if (x == end)//���һֱ���ֵĶ�Ϊ�й����ģ�һֱѭ������󣬾���ֹ
            break;
    }
}

//��ӡ������
void show_win_name(const vector<string>& win)
{
    vector<string>::const_iterator begin1 = win.cbegin(), end1 = win.cend();

    for (; begin1 != end1; ++begin1)
        cout << *begin1 << endl;
}
