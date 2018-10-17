#include <stdio.h>
class Keyword{
private:
    std::string const m_Required;
    std::string const m_Optional;
public:
    Keyword(std::string const & pRequired, std::string const &  pOptional="") const noexcept:
        m_Required(pRequired),
        m_Optional(pOptional)
        {}
    auto operator()(std::string const & pBlock, unsigned & pIndex) const noexcept{
        using namespace Helpers;
        if(Required(m_Required,pBlock,pIndex))
            if(Optional(m_Optional,pBlock,pIndex))
                return true;
        return false;

    }
};

template <bool IsRoot=false>
class Node{};
bool Query(std::string const & pBlock, unsigned & pIndex){}


int main(int argc, char *[]){
    return 0;
}
