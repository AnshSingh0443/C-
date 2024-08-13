#include<iostream>
#include<vector>
using namespace std;
//making an global vector of pairs containing int->no and there english word(string)
vector<pair<int,string>>mp{{1000000000,"Billion"},{1000000,"Million"},{1000,"Thousand"},{100,"Hundred"},{90,"Ninety"},{80,"Eighty"},
{70,"Seventy"},{60,"Sixty"},{50,"Fifty"},{40,"Forty"},{30,"Thirty"},{20,"Twenty"},{19,"Nineteen"},{18,"Eighteen"},{17,"Seventeen"},
{16,"Sixteen"},{15,"Fifteen"},{14,"Fourteen"},{13,"Thirteen"},{12,"Twelve"},{11,"Eleven"},{10,"Ten"},{9,"Nine"},{8,"Eight"},{7,"Seven"},
{6,"Six"},{5,"Fve"},{4,"Four"},{3,"Three"},{2,"Two"},{1,"One"}};
// to acesss this we can use mp[i].first for no and mp[i].second for string


string numberToWords(int num) {
    if(num==0){
        return "Zero";
    }
    for(auto it:mp){
        //1.iterate through the vector of pair to find a no which is just less than num
        // eg 123->123>100
        if(num>=it.first){
            string a=" ";
            // string a will be the number of hundreds,thousand,millon,billion acc to qn
            // will not be called for num less than a hundred
            if(num>=100){
                //a=123/100=1 so one 
                a=numberToWords(num/it.first);
            }
            //b->english word for current it{100,"hunderd"}
            string b=it.second;// in case of 123 ->b=hundered
            string c=" ";//->will run for last part 
            if(num%it.first!=0){
                //123%100=23 now R.R call for 23 will be stored in c
                //c=twenty three
                c=numberToWords(num%it.first);
            }
            //a=one+b=hunderd+c=twenty three
            return a+b+c;//->one hundred twenty three
        }
    }
    return "";//-when we do not enter for loop->will never happen just here as we have a string return type

}
int main(){
    cout<<numberToWords(1234567);

}