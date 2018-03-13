/**********************
author: yomi
date: 18.2.19
ps: 数据范围2^24 只能利用string做喽 ----->    想法很好 但是并不是10^24   int是32位 所以int就够用了。
    万绿丛中的一点红，即有*独一无二*颜色的那个像素点，并且该点的颜色与其周围8个相邻像素的颜色差充分大。
    TOL，是所求像素点与相邻点的颜色差阈值，*色差*超过TOL的点才被考虑。
    不要想当然， 要严格按照题目要求来做，不然的话， 你不错谁错？

    我判断了cnt==8 即满足“该点的颜色与其周围8个相邻像素的颜色差充分大”这一条件。 但是WA了。
    去掉就AC了。
    可以推出如果是边上的点，即一个点只有5个甚至更少的相邻元素，但是却满足其他条件的话，就可以。
    语文不好，还做啥题啊！！！
**********************/
#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int a[3] = {-1, 0, 1};
int data[1010][1010];
int m, n;
int k;
map<int, int>count;
bool IsOk(int x, int y)
{
//    int cnt = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == 1 && j == 1)
                continue;
            int x1 = x+a[i];
            int y1 = y+a[j];
            if(x1<0 || x1>=m || y1<0 || y1>=n) ///注意边界控制
                continue;

            int s1 = data[x][y];
            //cout << "(" << x1 << "," << y1 << ")" << endl;
            int s2 = data[x1][y1];
            if(abs(s1-s2)<=k){
                return false;
            }
//            if(abs(s1-s2)>k){
//                cnt++;
//            }     WA的罪魁祸首 所以可以推出如果是边上的点，即一个点只有5个甚至更少的相邻元素

        }
    }
//    if(cnt == 8){没必要
//        return true;
//    }
//    else{
//        return false;
//    }
    return true;

}

int main()
{
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> data[i][j];
            count[data[i][j]]++;
        }
    }

    int cnt = 0;
    int x = -1,y = -1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(count[data[i][j]] == 1 && IsOk(i, j)){
                x = i;
                y = j;
                cnt++;
                break;
            }
        }
    }
    if(cnt == 0){
        cout << "Not Exist";
    }
    else if(cnt > 1){
        cout << "Not Unique";
    }
    else{
        cout << "(" << y+1 << ", " << x+1 << "): " << data[x][y];
    }
    return 0;
}

/**
8 6 200

0 	      0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215

(5, 3): 16711680


4 5 2
0 0 0 0
0 5 0 0
0 0 8 0
0 5 0 0
0 0 0 0

4 5 2
0 0 0 0
0 0 0 0
0 0 0 0
5 0 0 0
0 0 0 0


**/
