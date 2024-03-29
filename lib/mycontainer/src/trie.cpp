#include "../inc/trie.hpp"

namespace mycontainer{
    
// Ctor
Trie::Trie():
root(std::make_shared<TrieNode>()){
    root->isWord = false;
}

// Distructor
Trie::~Trie(){
}

// Pulic Interfaces
bool Trie::add(const std::string& str){
    auto temp = root;
    bool result = false;
    for(auto ch: str){
        if(nullptr == temp->children[ch])
            temp->children[ch] = std::make_shared<TrieNode>();
        temp = temp->children[ch];
    }
    result = temp->isWord;
    temp->isWord = true;
    return result;
}

bool Trie::remove(const std::string& str){
    bool result = false;
    auto temp = getStringNode(str);
    
    if(nullptr == temp)
        return false;

    result = temp->isWord;
    temp->isWord = false;
    return result;
}

bool Trie::contains(const std::string& str) const{
    bool result = false;
    auto temp = getStringNode(str);
    if(nullptr != temp)
        result = temp->isWord;
    return result;
}

std::shared_ptr<Trie::TrieNode> Trie::getStringNode(const std::string& str) const{
    auto temp = root;
    for(auto ch: str){
        if(nullptr != temp->children[ch])
            temp = temp->children[ch];
        else
            return nullptr;
    }
    return temp;
}

void Trie::print() const{
    // auto* temp = root;

    // for(auto )
}

}