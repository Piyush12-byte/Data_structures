class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isTerminal;

    TrieNode (char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
       isTerminal=false; 
    }
};

class Trie {
private:
TrieNode*root;   
public:
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insertutil(TrieNode*root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        int idx=word[0]-'a';
        TrieNode*child;

        if(root->children[idx]!=NULL){
            //present
            child=root->children[idx];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->children[idx]=child;
        }

        // recursion
        insertutil(child,word.substr(1));

    }
    void insert(string word) {
        insertutil(root,word);
    }

    bool searchutil(TrieNode*root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }

        int idx=word[0]-'a';
        TrieNode*child;

        if(root->children[idx]!=NULL){
            child=root->children[idx];
        }
        else{
            return false;
        }

        //recursion
        return searchutil(child,word.substr(1));
    }
    
    bool search(string word) {
        return searchutil(root,word);
    }

    bool startswithUtil(TrieNode*root,string prefix){
        if(prefix.length()==0){
            return true;
        }

        int idx=prefix[0]-'a';
        TrieNode*child;

        if(root->children[idx]!=NULL){
            child=root->children[idx];
        }
        else{
            return false;
        }

        return startswithUtil(child,prefix.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startswithUtil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
