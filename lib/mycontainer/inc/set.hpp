#ifndef _HEADER_GUARD_SET_HPP_
#define _HEADER_GUARD_SET_HPP_

#include <string>
#include "trie.hpp"
#include "bst.hpp"

namespace mycontainer{

class set{
    public:
        // ctor
        set() = default;
        set(const std::string& str);

        //copy ctor
        set(const set& obj);

        // copy assignment
        set& operator=(const set& obj);

        /*  PUBLIC INTERFACES  */

        //Adds string to set
        /*
         * in param
         * str: string to be added
         * 
         * out param
         * bool: true if string already present otherwise false 
         * */
        bool add(const std::string& str);

        //Checks if giveb string is already in the set
        /*
         * in param
         * str: string to be searched
         * 
         * out param
         * bool: true if string is found otherwise false 
         * */
        bool contains(const std::string& str) const;

        //Removes string from the set if it is present
        /*
         * in param
         * str: string to be removed
         * 
         * out param
         * bool: true if string is present otherwise false 
         * */
        bool remove(const std::string& str);

        // utility
        unsigned int size() const;
    
    private:
        Bst data;
        unsigned int  containerSize = 0;
};

}

#endif  // _HEADER_GUARD_SET_HPP_