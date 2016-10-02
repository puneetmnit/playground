/**@file	/Users/puneet/Documents/technical/projects/playground/Algorithms/lib/trie.cpp
 * @author	puneet
 * @version	704
 * @date
 * 	Created:	Sun Oct  2 16:37:07 2016 \n
 * 	Last Update:	Sun Oct  2 16:37:07 2016
 */

#include "trie.h"

namespace Trie {
    void insert(Node *root, const std::string &key) {
        if (!root) {
            root = new Node();
        }
        Node *p = root;
        for (const auto c : key) {
            if (p->children.find(c) == p->children.end()) {
                // not exists;
                Node *n = new Node();
                p->children[c] = n;
            }
            p = p->children[c];
        }
        p->isLeaf = true;
    }

    bool find(Node *root, const std::string &key) {
        Node *p = root;
        for (const auto c: key) {
            if (!p) return false;
            auto found = p->children.find(c);
            if (found == p->children.end()) return false;
            p = found->second;
        }
        return (p && p->isLeaf);
    }
}
