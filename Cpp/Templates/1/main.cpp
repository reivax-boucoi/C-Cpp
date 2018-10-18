#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
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
namespace Interface::SCPI{
	namespace Helpers{
		char ToLower(char const pInput){
			return std::string::toLowerCase(pInput);
		}
		bool IsSameLetter(char const pLHS, char const pRHs){
			
		}
		bool Required(std::string const & pKeyword, std::string const & pBlock, unsigned const pIndex)noexcept{
			unisgned index =0;
			for(;index<pKeyword.size();++index){
				char const required=pKeyword[index];
				unsigned const block_index=index+pIndex;
				if(block_index < pBlock.size()){
					char const current=pBlock[block_index];
					if(IsSameLetter(current,required))continue;
				}
				break;
			}
			if(index==pKeyword.size()){
				pIndex+=index;
				return true
			}
			return false;
		}
		bool Optional(std::string const & pKeyword, std::string const & pBlock, unsigned const pIndex){
			Required(pKeyword,pBlock,pIndex);
			return true;
		}
		template <typename T, typename ... Args>
		bool IsAny(T const & pValue, Args const & ... pArgs){}
		bool isWhitespace(char const pInput){}
		bool RequiredWhitespace(std::string const & pBlock, unsigned & pIndex){}
		bool OptionalWhitespace(std::string const & pBlock, unsigned &pIndex){}

	}
}
template <bool IsRoot=false>
class Node{
	private:
		Keyword const m_Keyword;
	public:
		Node(Keyword const & pKeyword):m_Keyword(pKeyword){}
		auto operator()(std::string const & pBlock, unsigned & pIndex) const noexcept{
			using namespace Helpers;
			unsigned index = pindex;
			if constexpr (IsRoot){
				if(Optional(":",pBlock,index))
					if(m_Keyword(pBlock,index)){
						pindex=index;
						return true;
					}
			}else{
				if(Required(":",pBlock,index)){
					if(m_Keyword(pBlock,index)){
						pIndex=index;
						return true;
					}
				}
				return false;
			}
		}

};
bool Query(std::string const & pBlock, unsigned & pIndex){
	
}


int main(int argc, char *[]){
	unisgned int index=0;
	Keyword keyword("HEL","lo");
	if(keyword("Hello",index))printf("Found\n");

	return 0;
}
