#include "../inc/bst.hpp"

//Ctor
mycontainer::Bst::bstNode::bstNode(const std::string& str):
    value(str),
    left(nullptr),
    right(nullptr),
    parent(nullptr){}

mycontainer::Bst::bstNode::bstNode(const std::string& str, std::shared_ptr<bstNode> parent_ptr):
    value(str),
    left(nullptr),
    right(nullptr),
    parent(parent_ptr){}

mycontainer::Bst::Bst():
    root(nullptr),
    size(0){}

mycontainer::Bst::Bst(const std::string& str):
    root(std::make_shared<bstNode>(str)),
    size(1){}

//Copyt ctor
 mycontainer::Bst& mycontainer::Bst::operator=(const mycontainer::Bst& obj){
    if(this->root == obj.root)
        return *this;
    
    this->root = dfsDeepCopy(obj.root);
    return *this;
}

// Public Interfaces
bool mycontainer::Bst::add(const std::string& str){
    bool result = false;
    if(0 == size || nullptr == root){
        root = std::make_shared<bstNode>(bstNode(str));
        ++size;
        return result;
    }
    result = dfsAdd(root, str);
    if(false == result)
        ++size;
    return result;
}

bool mycontainer::Bst::contains(const std::string& str) const{
    bool str_found = false;
    if(nullptr != dfsSearch(root, str))
        str_found = true;
    return str_found;
}

bool mycontainer::Bst::remove(const std::string& str){
    bool str_removed = false;
    auto str_node = dfsSearch(root, str);
    dfsDelete(root, str, str_removed);

    return str_removed;
}

// Helper functions
bool mycontainer::Bst::dfsAdd(std::shared_ptr<bstNode> root, const std::string& str){
    if(root->value == str)
        return true;
    else if(root->value < str){
        if(nullptr == root->right){
            root->right = std::make_shared<bstNode>(bstNode(str, root));
            ++size;
            return false;
        }
        else{
            return dfsAdd(root->right, str);
        }
    }
    else if(root->value > str){
        if(nullptr == root->left){
            root->left = std::make_shared<bstNode>(bstNode(str, root));
            ++size;
            return false;
        }
        else{
            return dfsAdd(root->left, str);
        }
    }
    return true;
}

std::shared_ptr<mycontainer::Bst::bstNode> mycontainer::Bst::dfsSearch(std::shared_ptr<bstNode> root, const std::string& str) const{
    if(nullptr == root)
        return nullptr;
    else if(root->value == str)
        return root;
    else if(root->value < str)
        return dfsSearch(root->right, str);
    else if(root->value > str)
        return dfsSearch(root->left, str);
}

std::shared_ptr<mycontainer::Bst::bstNode> mycontainer::Bst::dfsDelete(std::shared_ptr<bstNode> root, const std::string& str, bool& removed){
    if(nullptr == root){
        removed = false;
        return root;
    }
    
    if(str < root->value){
        root->left = dfsDelete(root->left, str, removed);
        return root;
    }
    else if(str > root->value){
        root->right = dfsDelete(root->right, str, removed);
        return root;
    }

    removed = true;
    if(root->left == nullptr){
        auto right_child = root->right;
        if(right_child)
            right_child->parent = root->parent;
        root.reset();
        return right_child;
    }
    else if(root->right == nullptr){
        auto left_child = root->left;
        if(left_child)
            left_child->parent = root->parent;
        root.reset();
        return left_child;
    }
    else{

        auto swap_node = root->right;

        while(nullptr != swap_node->left){
            swap_node = swap_node->left;
        }


        if(nullptr != swap_node->right)
            swap_node->right->parent = swap_node->parent;

        if(swap_node->parent == root)
            swap_node->parent->right = swap_node->right;
        else
            swap_node->parent->left = swap_node->right;

        root->value = swap_node->value;
        swap_node.reset();
    }
    return root;
}

std::shared_ptr<mycontainer::Bst::bstNode> mycontainer::Bst::dfsDeepCopy(const std::shared_ptr<bstNode> obj){
    if(nullptr == obj)
        return nullptr;

    auto root = std::make_shared<mycontainer::Bst::bstNode>(obj->value);
    if(nullptr != obj->left)
        root->left = dfsDeepCopy(obj->left);
    if(nullptr != obj->right)
        root->right = dfsDeepCopy(obj->right);
    return root;
}
