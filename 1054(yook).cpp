#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char *num[105];
    int N,count=0;
    double average=0;
    cin>>N;
    for(int i=0;i<N;i++){
        bool isNumber=true;     //�ж��Ƿ�Ϊ�Ϸ�����
        int point=0;            //����С����ĸ���
        int point_=0;           //����С����֮���λ��
        num[i] = (char *)malloc(10*sizeof(char)); //����ռ�
        cin>>num[i];
        int len=strlen(num[i]);
        double temp=atof(num[i]);//���ַ���ת�������֣������÷����аٶ�
        if(temp<-1000||temp>1000)   isNumber=false;
        for(int j=0;j<len;j++){  //��ÿһ��Ԫ�صĸ����ַ������ж�
            if(point==1) point_++;
            if(num[i][j]=='-'&&j!=0){//�������-����-ֻ��һ�����ڵ�һλ
                isNumber=false;
                break;
            }
            if(num[i][j]!='.'){
                if((num[i][j]<'0'||num[i][j]>'9')&&(num[i][j]!='-')){
                    isNumber=false;
                    break;
                }
            }else {             //�����С����
                point++;
            }
            if(point_>2||point>1){//���С�������һ������С��λ������2
                isNumber=false;
                break;
            }
        }
        if(!isNumber)
            cout<<"ERROR: "<<num[i]<<" is not a legal number"<<endl;
        else {
            count++;
            average+=temp;
        }
    }
    if(count==1)
        printf("The average of 1 number is %.2f",average);
    else if(count==0)
        printf("The average of 0 numbers is Undefined");
    else
        printf("The average of %d numbers is %.2f",count,average/count);
    return 0;
}
