#include <iostream>
using namespace std;

bool findPath(char maze[][10],int i,int j,int m,int n){
    //base case
    if(i==m and j==n){
        return true;
    }
    //out of bounds
    if(i>m or j>n){
        return false;
    }
    //x cell
    if(maze[i][j]=='X'){
        return false;
    }

    //rec case
    //try right
    bool rastaMila = findPath(maze,i,j+1,m,n);
    if(rastaMila){
        return true;
    }
    //down
    return findPath(maze,i+1,j,m,n);
}
int  countPath(char maze[][10],int i,int j,int m,int n){
    //base case
    if(i==m and j==n){
        maze[i][j] = '#';
        //print the maze
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<maze[i][j]<<" ";
            }
            cout<<endl;
        }
        maze[i][j] = '0';
        cout<<endl;
        return 1;
    }
    //out of bounds
    if(i>m or j>n){
        return 0;
    }
    //x cell
    if(maze[i][j]=='X'){
        return 0;
    }

    //rec case
    maze[i][j] = '#';

    //try right
    int ans = 0;

    ans = countPath(maze,i,j+1,m,n) + countPath(maze,i+1,j,m,n);

    //backtracking
    maze[i][j] = '0';
    return ans;
}


int main() {

    char maze[][10] = {
        "000X",
        "0X00",
        "00X0",
        "0000",
        "0X00"
    };
    bool rastaMila = findPath(maze,0,0,4,3);
    if(rastaMila){
        cout<<"Path Found!"<<endl;
    }
    else{
        cout<<"Not found!"<<endl;
    }
    int ans =  countPath(maze,0,0,4,3);
    cout<<endl<<ans<<endl;

return 0;
}
