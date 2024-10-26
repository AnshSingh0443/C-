#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders_Brute(vector<string>& folder) {
        unordered_set<string>st(folder.begin(),folder.end());//( /a..... /a/b/c...../a/b/d)
        vector<string>result;

        for(auto  &currFolder:folder){
            bool  isSubfolder=false;
            string tempFolder=currFolder;
            while(!currFolder.empty()){
                //har ek folder ka last / find kar karo 
                // 0 to that position will be the parent folder par and if it present in the set then current folder is a subfolder and should be removed
                //currFolder= /a/b/c-> /a/b is not in set but /a is which makes /a/b/c is sub folder
                auto pos=currFolder.find_last_of('/');
                //update the curr folder->/a/b  in next it-> /a
                currFolder=currFolder.substr(0,pos);
                // /a/b not in set  in net it  /a is present in set
                if(st.find(currFolder)!=st.end()){
                    //means it is a sub folder
                    isSubfolder=true;
                    break;
                }
                //after /a =>next it currFolder will be null string thus exit the whhile loop


            }
            //only include those whoo are not sub folder
            if(!isSubfolder){
                result.push_back(tempFolder);
            }

        }

        return result;
        
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;

        result.push_back(folder[0]); //sorted hai islie folder[0] ka koi parent nahi hoga
        //so it can never be a sub-folder

        for(int i = 1; i < folder.size(); i++) {
            
            string currFolder = folder[i];
            string lastFolder = result.back();
            lastFolder += '/';
            cout<<"prev  Folder :"<<lastFolder<<endl;
            cout<<"curr  Folder :"<<currFolder<<endl;
            if(currFolder.find(lastFolder) != 0) {
                //not presnt
                result.push_back(currFolder);
            }
        }

        return result;

        
    }
};


int main(){
    
}