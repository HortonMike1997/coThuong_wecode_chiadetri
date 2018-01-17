#include <iostream>
#include <cstdlib>

using namespace std;
const int maxptu=1000;
int n;
int a[maxptu],m[maxptu][maxptu];
//int m1[maxptu][maxptu];
int  burst_balloon()
{
    int j,s1,l,r,l1,r1,s,k1;
    for (int len=0; len<=n-1; len++)
        for (int i=1; i<=n-len; i++)
            //if (i+len<=n)
            {
                j=i+len;
                s1=m[i][j];
                for (int k=i; k<=j; k++)
                {
                    if (k-1<i) l=0; else l=m[i][k-1];
                    if (k+1>j) r=0; else r=m[k+1][j];
                    if (i-1<1) l1=1; else l1=a[i-1];
                    if (j+1>n) r1=1; else r1=a[j+1];
                    s=l+r+l1*a[k]*r1;
                    if (s>s1) {s1=s; k1=k;}
                }
                m[i][j]=s1;
                //m1[i][j]=k1;
            }
}

int main()
{

    //cout <<rand()%100<<" "<<rand()%100;
    //n=19000;
    //for (int i=1; i<=n; i++)
        //a[i]=rand()%10 +1;
       // a[i]=1;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    //cout <<0;
    burst_balloon();
    cout <<m[1][n];

//    for (int i=1; i<n; i++)
//        cout <<a[i]<<" ";
//    for (int i=1; i<=n; i++)
//    {
//        for (int j=1; j<=n; j++)
//            cout <<m[i][j]<<'\t';
//        cout <<endl;
//    }

}
