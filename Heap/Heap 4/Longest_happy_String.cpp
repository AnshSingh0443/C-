#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class node{
    public:
        char data;
        int count;
        node(char d,int c){
            data = d;
            count = c;
        }
};
class compare{
    public:
        bool operator()(node a,node b){
            return a.count < b.count;
        }
};

    string longestDiverseString(int a, int b, int c) {
        //1.create a max heap
        priority_queue<node,vector<node>,compare>maxheap;

        //2.push a , b and c with their count to max heap if their count > 0
        if(a>0){
            node temp('a',a);
            maxheap.push(temp);
        }
        if(b>0){
            node temp('b',b);
            maxheap.push(temp);
        }
        if(c>0){
            node temp('c',c);
            maxheap.push(temp);
        }
        string ans="";
        //3.jab tak maxheap.size>1-> we need two disntict to avoid repeatations
        while(maxheap.size()>1){
            //3.1->2 elements from the top
            node first = maxheap.top();
            maxheap.pop();
            node second = maxheap.top();
            maxheap.pop();

            //3.2 try to get 2 chars from the first 
            if(first.count>=2){
                //add twice to ans
                ans.push_back(first.data);
                ans.push_back(first.data);
                //update count
                first.count -=2;
            }else{
                //count is 1->add only once
                ans.push_back(first.data);
                //update count;
                first.count--;
            }

            //3.3 try to get w chars from second but only if second.count>first.count and seconnd.count>=2
            if(second.count>=2 && second.count>first.count){
                //add twice to ans
                ans.push_back(second.data);
                ans.push_back(second.data);
                //update count
                second.count -=2;
            }else{
                //count is one add only once
                ans.push_back(second.data);
                //update count
                second.count--;


            }

            //3.4 psuh them back to max heap if their count is !=0
            if(first.count!=0){
                maxheap.push(first);
            }
            if(second.count!=0){
                maxheap.push(second);
            }

        }

        //4->reaming ko add karo
        if(maxheap.size()==1){
            node temp=maxheap.top();
            if(temp.count>=2){
                //add twice
                ans.push_back(temp.data);
                ans.push_back(temp.data);
                //update count
                temp.count -=2;
            }else{
                //count is 1 add only once
                ans.push_back(temp.data);
                temp.data--;
            }
        }

        return ans;


    }


int main(){
//     A string s is called happy if it satisfies the following conditions:

// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.
    int a=1;
    int b=1;
    int c=7;

    cout<<longestDiverseString(a,b,c);
}