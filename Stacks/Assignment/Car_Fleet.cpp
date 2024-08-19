#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Car{
        public:
            int pos,speed;
            Car(int p ,int s):pos(p),speed(s) {};
    };
//custom compartor for sorting
static bool myComp(Car&a,Car&b){
        return a.pos<b.pos;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for(int i=0;i<position.size();i++){
            Car car(position[i],speed[i]);
            cars.push_back(car);
        }
        //sort cars
        sort(cars.begin(),cars.end(),myComp);
        stack<float>st;
        for(auto car:cars){
            //calu;late timme for each car
            float time=(target-car.pos)/((float) car.speed);
            //pop condition->for forming fleets fater meets slower and both tarvel slowly toghther(fleet)
            // ie poping fater time  and psuhing curret slower time to show that a fleet is travelig slower toward dest
            while(!st.empty() && time>=st.top()){
                st.pop();
            }
            st.push(time);
        }
        //stack size->no of fleets
        return st.size();
        
}
int main(){
    
}