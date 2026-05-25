#include <cstdlib>
#include "IList.hpp"

#pragma comment(lib, "list.lib")
 
int main(void){
    data_t data; 

    IList* pIList = IList::get_instance(); 
    for(data = 10; data <= 50; data += 10)
        pIList->insert_end(data); 

    pIList->show("Showing list after inserting 10 to 50 at end:"); 

    IList::release_instance(pIList); 
    pIList = 0; 

    return EXIT_SUCCESS; 
}