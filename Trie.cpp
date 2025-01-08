#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    unordered_map<char,TrieNode*> children;
    int isEndOfWord;

    TrieNode(){
        isEndOfWord = 0;
    }

};
class Trie{
    public:

    TrieNode* root;

    Trie(){
        root = new TrieNode;
    }

    void insert(const string& word){
        TrieNode* node = root;
        for(auto ch : word){
            if(node->children.find(ch)==node->children.end()){
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord++;
    }

    int search(const string& word){
        TrieNode* node = root;
        for(auto ch : word){
            if(node->children.find(ch)==node->children.end()){
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const string& word){
        TrieNode* node = root;
        for(auto ch : word){
            if(node->children.find(ch)==node->children.end()){
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }

};
int main(){
    Trie t;
    t.insert("hello");
    t.insert("help");
    cout<<t.search("hello")<<endl;
    cout<<t.startsWith("hel")<<endl;
    cout<<t.search("hel")<<endl;

}