#include<iostream>
using namespace std;
void hollowrectangle(int row,int column){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(i==0||i==row-1||j==0||j==column-1){
             cout<<" *";
            }else{
                cout<<"  ";
            }

        }cout<<endl;
       
    }

}
int main(){
    hollowrectangle(5,5);

}