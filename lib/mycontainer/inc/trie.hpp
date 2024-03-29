#pragma once

#include "constants.hpp"
#include <string>
#include <memory>

namespace mycontainer{

    class Trie{
        public:
            Trie();
            ~Trie();
            bool contains(const std::string& str) const;
            bool add(const std::string& str);
            bool remove(const std::string& str);

            void print() const;
        private:
            struct TrieNode{
                std::shared_ptr<TrieNode> children[myconstants::NUM_OF_ASCII_CHARACTERS] = {nullptr};
                bool isWord = false;

                TrieNode() = default;
                TrieNode(const TrieNode& data) = delete;
                void operator=(const TrieNode& data) = delete;
            };

            std::shared_ptr<Trie::TrieNode> getStringNode(const std::string& str) const;
            std::shared_ptr<Trie::TrieNode> root;
    };
}