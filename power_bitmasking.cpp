#include <iostream>
using namespace std;

void f(int n){
    //Base Case
    if(n==0){
        return;
    }
    //Rec Case
    
    cout<<n<<" ";
    f(n-1);
}




int power(int a,int n){
    //base case
    if(n==0){
        return 1;
    }

    //rec case
    int subans = power(a,n/2);
    subans = subans*subans;
    if(n%2==1){
        return a*subans;
    }
    return subans;
}

int fastPower(int a,int n){
    //bitmasking
    int ans = 1;
    while(n!=0){
        int last_bit = (n&1);
        if(last_bit){
            ans = ans*a;
        }
        a = a*a;
        n = n>>1;
    }
    return ans;
}

int main() {
   cout<<fastPower(5,4);
}
