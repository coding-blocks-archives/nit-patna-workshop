#include <iostream>
using namespace std;

int dp[1000] = {0};
int calls = 0;

int ways(int n,int k){
    //Base Case
    calls++;
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    //Lookup if n is already computed or not! -->Dynamic Programming -> Optmize the recursive solution
    if(dp[n]!=0){
       return dp[n];
    }

    //Rec Case
    int ans = 0;
    for(int i=1;i<=k;i++){
        int subans = ways(n-i,k);
        ans += subans;
    }

    return dp[n] = ans;
}


int main() {
    int n=4,k=3;
    cout<<ways(n,k)<<endl;
    cout<<"Calls "<<calls<<endl;
}
