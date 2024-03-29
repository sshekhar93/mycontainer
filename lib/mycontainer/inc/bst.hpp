#pragma once

#include <string>
#include <memory>
namespace mycontainer{

class Bst{
    public:
        // Ctor
        Bst();
        Bst(const std::string& str);

        /* PUBLIC INTERFACES*/
        bool add(const std::string& str);
        bool remove(const std::string& str);
        bool contains(const std::string& str) const;

        /* OPERATORS */
        mycontainer::Bst& operator=(const mycontainer::Bst& obj);
    
    private:
        struct bstNode{
            std::string value;
            std::shared_ptr<bstNode> left;
            std::shared_ptr<bstNode> right;
            std::shared_ptr<bstNode> parent;

            bstNode() = delete;
            bstNode(const std::string& str);
            bstNode(const std::string& str, std::shared_ptr<bstNode> parent_ptr);
        };

        // Helper functions
        bool dfsAdd(std::shared_ptr<bstNode> root, const std::string& str);
        std::shared_ptr<bstNode> dfsSearch(std::shared_ptr<bstNode> root, const std::string& str) const;
        std::shared_ptr<bstNode> dfsDelete(std::shared_ptr<bstNode> root, const std::string& str, bool& removed);
        std::shared_ptr<bstNode> dfsDeepCopy(const std::shared_ptr<bstNode> obj);

        std::shared_ptr<bstNode> root;
        unsigned int size;


};
}