#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string intToRoman(int num) {
    vector<string>romansymbols{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int>value{1000,900,500,400,100,90,50,40,10,9,5,4,1};//values correspomding to  respective roman symbols
    string ans="";
    for(int i=0;i<13;i++){
        // eg 58
        while(num>=value[i]){
            //1.num=58 i=6 value[6]=50     //2.num=8 i=10 values[10]=5    //3.num=3 i=12 values[12]=1
            //58>=50                       //8>=5                         //3>=1->add I 3 times
            ans=ans+romansymbols[i];//romansymbol[6]=L so, add L to ans,ans=L now romansymbol[10]=V, so add V to ans,ans=LV
            num=num-value[i];//sinCE L is added remove it from existing num s 58-50=8,since V is added remove it from num 8-5=3
            //1.8 is the new num   //2.new num is now 3  //3.new will become -1 after adding ADDING I 3 times in ans ans reomve 3 from num->break out og the loop
        }
    }
    return ans;
        
}
int main(){
    // Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

    // Symbol       Value
    // I             1
    // IV            4 (speical case->V(5)-I(1)=4)
    // V             5
    // IX            9 (special case->X(10)-I(1)=9)
    // X             10
    // XL            40 (special case->L(50)-X(10)=40)
    // L             50
    // XC            90 (special case->C(100)-X(10)=90)
    // C             100
    // CD            400 (special case->D(500)-C(100)=400)   
    // D             500
    // CM            900 (special case->M(1000)-C(100)=900)
    // M             1000

    // Example 1:
    // Input: num = 3
    // Output: "III"
    // Explanation: 3 is represented as 3 ones.

    // Example 2:
    // Input: num = 58
    // Output: "LVIII"
    // Explanation: L = 50, V = 5, III = 3.

    // Example 3:
    // Input: num = 1994
    // Output: "MCMXCIV"
    // Explanation: M = 1000, CM = 900, XC = 90 and IV = 4
    int num=58;
    cout<<intToRoman(num);
}