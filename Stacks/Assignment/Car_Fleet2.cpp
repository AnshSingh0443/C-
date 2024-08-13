#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>answer(cars.size(),-1);
        stack<int> st;
        for(int i=cars.size()-1;i>=0;i--){
            //check if car ahead if curr car is faster
            while(!st.empty() && cars[st.top()][1]>=cars[i][1]){
                st.pop();
            }

            while(!st.empty()){
                //pos[i+1]-pos[i]/speed[i]-speed[i+1] i+1 denotes->car ahead ie car at the top of the stack
                double CurColTime=(double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(answer[st.top()]==-1 || CurColTime<=answer[st.top()]){
                    answer[i]=CurColTime;
                    break;
                }
                st.pop();
            }
            st.push(i);

        }
        return answer;
        
}

int main(){

}