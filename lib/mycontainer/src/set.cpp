#include "../inc/set.hpp"

namespace mycontainer{

    set::set(const std::string& str){
        this->add(str);
    }

    set::set(const set& obj){
        this->data = obj.data;
        this->containerSize = obj.containerSize;
    }

    set& set::operator=(const set& obj){
        this->data = obj.data;
        this->containerSize = obj.containerSize;
    }

    bool set::add(const std::string& str){
        auto result = data.add(str);
        if(false == result)
            ++containerSize;
        return result;
    }

    bool set::remove(const std::string& str){
        auto result = data.remove(str);
        if(true == result)
            --containerSize;
        return result;
    }

    bool set::contains(const std::string& str) const{
        return data.contains(str);
    }

    unsigned int set::size() const{
        return containerSize;
    }

}