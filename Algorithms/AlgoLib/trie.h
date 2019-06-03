//
// Created by puneet on 02/10/16.
//

#ifndef ALGORITHMS_TRIE_H_H
#define ALGORITHMS_TRIE_H_H

#include <string>
#include <unordered_map>

namespace Trie {
    struct Node {
        Node() : isLeaf(false) { };
        std::unordered_map<char, Node *> children;
        bool isLeaf;
    };

    void insert(Node *root, const std::string &key) ;

    bool find(Node *root, const std::string &key) ;
    
    //@todo delete
    // bool delete(Node* root, const std::string& key);
}

#endif //ALGORITHMS_TRIE_H_H
