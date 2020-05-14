class Trie {
    
    struct Trienode {
        char val;
        int eos;
        Trienode *child[26];
    };
    
    
    Trienode *getnode(char value)
    {
        Trienode *newnode = new Trienode;
        newnode->val=value;
        newnode->eos=0;
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
    
    
public:
    /** Initialize your data structure here. */
   
      Trienode *root = getnode('/');
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode *curr=root;
        for(int i=0;word[i]!='\0';++i)
        {
            int index=word[i]-97;
            if(curr->child[index]==NULL)
                curr->child[index] = getnode(word[i]);
            curr = curr->child[index];            
        }
        curr->eos +=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       Trienode *curr=root;
        for(int i=0;word[i]!='\0';++i)
        {
            int index = word[i]-97;
            if(curr->child[index]==NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->eos > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *curr = root;
        for(int i=0;prefix[i]!='\0';++i)
        {
            int index = prefix[i]-97;
            if(curr->child[index]==NULL)
                return false;
            curr = curr->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
