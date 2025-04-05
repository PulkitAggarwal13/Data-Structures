#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];  // Assuming all characters are lowercase.
    bool flag = false;
    bool containsChar(char ch)
    {
        return (links[ch-'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch-'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void setEnd()
    {
        flag = true;
    }
};

class Trie
{
private:
    Node *root;
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word) // T.C. - O(n)
    {
        Node *node = root;
        int n=word.length();
        for(int i=0;i<n;i++)
        {
            if(!(node->containsChar(word[i])))
            {
                Node *newNode = new Node();
                node->put(word[i],newNode);
            }

            // moves to new reference node
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word) // T.C. - O(n)
    {
        Node* node = root;
        int n=word.length();
        for(int i=0;i<n;i++)
        {
            if(!(node->containsChar(word[i])))
                return false;
            
            node = node->get(word[i]);
        }

        return (node->flag == true);
    }

    bool startsWith(string prefix) // T.C. - O(n)
    {
        Node* node = root;
        int n = prefix.length();
        for(int i=0;i<n;i++)
        {
            if(!(node->containsChar(prefix[i])))
                return false;
            
            node = node->get(prefix[i]);
        }
        return true;
    }
};