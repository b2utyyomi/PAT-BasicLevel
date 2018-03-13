#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a, int b)
{
    if(a%b == 0)
        return b;
    return gcd(b, a%b);
}

int main() {
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);

    if(n1 * m2 > n2 * m1) {
        swap(n1, n2);
        swap(m1, m2);
    }
    int num = 1;
    int cnt = 0;
    for (int i=)
    while(n1 * k >= m1 * num) num++;
    while(n1 * k < m1 * num && m2 * num < n2 * k) {
        if(gcd(num, k) == 1) {
            if(cnt)
                cout << ' ';
            printf("%d/%d", num, k);
            cnt++;
        }
        num++;
    }
    return 0;
}
