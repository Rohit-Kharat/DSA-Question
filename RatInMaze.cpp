#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx,int newy,vector<vector<int>>&m,vector<vector<bool>>&visited,int n){
    if(newx < 0 || newy < 0 || newx >= n || newy >= n){

        //out of bound
        return false;
    }

    if(visited[newx][newy]){
        //already visited
        return false;
    }
    if(m[newx][newy] == 0){
        //block space 
        return false;
    }
    return true;
}
void solve(vector<vector<int>>&m,vector<vector<bool>>&visited,int n,vector<string>&ans,int curr_x,int curr_y,int dest_x,int dest_y,string output){
    //base case
    if(curr_x == dest_x && curr_y == dest_y){
        //rat reached destination
        //store output
        ans.push_back(output);
        return;
    }
    int dx[] ={-1,1,0,0}; 
    int dy[] ={0,0,-1,1}; 
    char move[] ={'U','D','L','R'};
    
    
    for(int i=0;i<4;i++){
        int newx = curr_x + dx[i];
        int newy = curr_y +  dy[i];
        char movement = move[i];
    

    if(isSafe(newx,newy,m,visited,n)){
        visited[newx][newy] = true;
        output.push_back(movement);
        solve(m,visited,n,ans,newx,newy,dest_x,dest_y,output);

        output.pop_back();
        visited[newx][newy] = false;
    }
    
    // //UP (i-1,j)

    // // newx = curr_x - 1;
    // // newy = curr_y;
    // if(isSafe(newx,newy,m,visited,n)){
    //     visited[newx][newy] = true;
    //     output.push_back('U');
    //     solve(m,visited,n,ans,newx,newy,dest_x,dest_y,output);

    //     output.pop_back();
    //     visited[newx][newy] = false;
    // }
    // // DOWN(i+1,j)
    // // newx = curr_x + 1;
    // // newy = curr_y;

    // if(isSafe(newx,newy,m,visited,n)){
    //     visited[newx][newy] = true;
    //     output.push_back(movement);
    //     solve(m,visited,n,ans,newx,newy,dest_x,dest_y,output+"D");

    //     output.pop_back();
    //     visited[newx][newy] = false;
    // }

    // // Left (i,j-1)
    // // newx = curr_x;
    // // newy = curr_y - 1;
    // if(isSafe(newx,newy,m,visited,n)){
    //     visited[newx][newy] = true;
    //     output.push_back(movement);
    //     solve(m,visited,n,ans,newx,newy,dest_x,dest_y,output+"L");

    //     output.pop_back();
    //     visited[newx][newy] = false;
    // }

    // //Right (i,j+1);
    // // newx = curr_x;
    // // newy = curr_y + 1;
    //   if(isSafe(newx,newy,m,visited,n)){
    //     visited[newx][newy] = true;
    //     output.push_back(movement);
    //     solve(m,visited,n,ans,newx,newy,dest_x,dest_y,output+"R");

    //     output.pop_back();
    //     visited[newx][newy] = false;
    // }
    }
}
vector<string>findPath(vector<vector<int>>&m,int n){
    vector<string>ans;

    vector<vector<bool>>visited(n,vector<bool>(n,0));

    int curr_x = 0;
    int curr_y = 0;

    visited[0][0]= true;

    int dest_x = n - 1;
    int dest_y = n - 1;
    string output = "";
    if(m[0][0] == 0){
        return ans;
    }
    solve(m,visited,n,ans,curr_x,curr_y,dest_x,dest_y,output);
    return ans;

}
int main() {
    int n ;
    cout<<"Enter size of Matrix : ";
    cin>>n;

    vector<vector<int>>m(n,vector<int>(n));

    cout<<"Enter matrix element(0/1):\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }

    vector<string>ans = findPath(m,n);

    if(ans.size() == 0){
        cout<<"Not found";
    }else{
        cout<<"Possible path :\n";

        for(string path : ans){
            cout<<path<<endl;
        }
    }
    return 0;
}