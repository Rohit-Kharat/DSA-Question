#include<iostream>

using namespace std;
void printPermu(string&str,int i){

    if(i >= str.length()){
        cout<<str <<endl;
        return;
    }
    for(int j = i;j<str.length();j++){
        swap(str[i],str[j]);
        printPermu(str,i+1);
        swap(str[i],str[j]);
    }
}
int main() {
    string str = "abc";
    int i = 0;
    printPermu(str,i);
    return 0;
}