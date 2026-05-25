#include <iostream> 
#include <vector> 
#include <map> 

template <typename KEY_TYPE, typename VALUE_TYPE> 
class cpa_map 
{
	private: 
		std::vector<std::pair<KEY_TYPE, VALUE_TYPE>> vec; 

	public: 
		std::pair<typename std::vector<std::pair<KEY_TYPE, VALUE_TYPE>>::iterator, bool> insert(std::pair<KEY_TYPE, VALUE_TYPE>& ref)
		{
			vec.push_back(ref); 
			std::vector<std::pair<KEY_TYPE, VALUE_TYPE>>::iterator iter = vec.end() - 1; 
			std::pair<std::vector<std::pair<KEY_TYPE, VALUE_TYPE>>::iterator, bool> ret_val {iter, true}; 
			return ret_val; 
		}
}; 

int main() 
{
    return 0; 
}