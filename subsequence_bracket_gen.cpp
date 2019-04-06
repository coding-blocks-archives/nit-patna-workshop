#include <iostream>
using namespace std;

void generate_subsequences(char *in,char *out,int i,int j){
    //base case
    if(in[i]=='\0'){
        out[j] = '\0';
        cout<<out<<" ";
        return;
    }

    //rec case
    //1. Include
    out[j] = in[i];
    generate_subsequences(in,out,i+1,j+1);
    //2. Exclude
    generate_subsequences(in,out,i+1,j);

}

void generate_brackets(char *output,int n,int idx,int open,int close){
    //base case
    if(idx==2*n){
        output[idx]='\0';
        cout<<output<<endl;
        return;
    }
    //open
    if(open<n){
        output[idx] = '(';
        generate_brackets(output,n,idx+1,open+1,close);
    }

    //closing
    if(close<open){
        output[idx] = ')';
        generate_brackets(output,n,idx+1,open,close+1);
    }


}

int main() {
    char in[100] = "abc";
    char output[100];
   // generate_subsequences(in,output,0,0);
    generate_brackets(output,3,0,0,0);
    return 0;
}
