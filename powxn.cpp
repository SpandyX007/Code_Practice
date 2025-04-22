#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    double x=2.00000;
    int n=-2;
	double pow=1;
    long binform=n;
        if (n<0)
        {
            x=1/x;
            binform=-binform;
        }

        double ans=1;
        while (binform>0)
        {
            if(binform%2==1)
            {
                ans=ans*x;
            }
            x*=x;
            binform=binform/2;
        }

        cout<< ans;

    return 0;

}