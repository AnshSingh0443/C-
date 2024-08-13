#include<iostream>
using namespace std;
void inverted_half_pyramid(int rows){
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows-i;j++){
            cout<<" *";
        }cout<<endl;
    }

}
int main(){
    inverted_half_pyramid(5);
}