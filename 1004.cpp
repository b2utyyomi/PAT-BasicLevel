/**********************
author: yomi
date: 18.1.6
ps:
**********************/

#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct stu
{
    string name;
    string number;
    int grade;
}student[1000];
int cmp(const void *a, const void *b)
{
    struct stu *aa=(stu *)a;
     struct stu *bb=(stu *)b;

     if(aa->grade!=bb->grade)
         return(((aa->grade)>(bb->grade))?1:-1);

}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> student[i].name >> student[i].number >> student[i].grade;
    }
    qsort(student, n, sizeof(student[0]), cmp);
    cout << student[n-1].name << ' ' << student[n-1].number << endl;;
    cout << student[0].name << ' ' << student[0].number;

    return 0;

}


/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
     double date1;
     int no;
} s[100];

int i,n;

int cmp(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;

     if(aa->date1!=bb->date1)
         return(((aa->date1)>(bb->date1))?1:-1);

//    if(((node*)a)->date1!=((node*)b)->date1)
//         return(((((node*)a)->date1)>(((node*)b)->date1))?1:-1);
//     else
//         return((((node*)a)->no)-(((node*)b)->no));
}

int main()
{
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         s[i].no=i+1;
         scanf("%lf",&s[i].date1);
     }
     qsort(s,n,sizeof(s[0]),cmp);

     for(i=0;i<n;i++) printf("%d   %lf\n",s[i].no,s[i].date1);

     return(0);
}
*/
