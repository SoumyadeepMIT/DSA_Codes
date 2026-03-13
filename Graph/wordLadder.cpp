#include <bits/stdc++.h>
using namespace std;
bool poss(string word1, string word2){
    int diff = 0;
    for(int i=0; i<word1.length();i++){
        if(word1[i]!=word2[i]) diff++;
    }
    if(diff==1) return true;
    return false;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, bool> um;
    queue<pair<string, int>> qu;
    qu.push({beginWord, 1});
    um[beginWord]=true;
    while(!qu.empty()){
        string word = qu.front().first;
        int l = qu.front().second;
        qu.pop();
        if(word == endWord) return l;
        for(int i=0;i<wordList.size();i++){
            if(!um[wordList[i]] && poss(word, wordList[i])){
                um[wordList[i]] = true;
                qu.push({wordList[i], l+1});
            }
        }
    }
    return 0;
}
int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength(beginWord, endWord, wordList) << endl;
}