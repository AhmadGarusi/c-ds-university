#include<iostream>
using namespace std;




int main()
{
    int i, j, k, bs[7][3], bt[7][3];
 
    bt[0][0]=bs[0][1]; bt[0][1]=bs[0][0]; bt[0][2]=bs[0][2];
    k=1;
    
    for(i=0;i< bs[0][1];i++) 
        for(j=1; j< bs[0][2]; j++ ) 
            if(i==bs[j][1])
            {
                bt[k][0]=bs[j][1];
                bt[k][1]=bs[j][0]; 
                bt[k][2]=bs[j][2]; 
                k++; 
            } 
}