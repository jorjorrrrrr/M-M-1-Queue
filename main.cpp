#include <iostream>
#include "myDLL.h"


struct CSTYLE{
    char* str;
    int index;
    CSTYLE(char* str, int index) :str(str), index(index) {}
};

int main(){
    // Step A : Generate 20 c-style string and its index
    char story[20][30] = {
        "In", "recent", "years,", "Artificial", "Intelligence", "has", "rapidly", "advanced,", "transforming", "industries", 
        "with", "machine", "learning,", "natural", "language", "processing,", "and", "computer", "vision", "technologies."
    };
    
    CSTYLE cstring[20] = {
        CSTYLE(story[19], 100), CSTYLE(story[18], 99), CSTYLE(story[17], 98) , CSTYLE(story[16], 97),
        CSTYLE(story[15], 60), CSTYLE(story[14], 59) , CSTYLE(story[13], 58) , CSTYLE(story[12], 57),
        CSTYLE(story[11], 33), CSTYLE(story[10], 32) , CSTYLE(story[9], 30)  , CSTYLE(story[8], 29) ,
        CSTYLE(story[7], 10) ,  CSTYLE(story[6], 9)  , CSTYLE(story[5], 8)   , CSTYLE(story[4], 7)  ,
        CSTYLE(story[3], 0)  , CSTYLE(story[2], -1)  , CSTYLE(story[1], -3), CSTYLE(story[0], -100)
    };

    // Step B : Define dataList and dataListSorted
    myDLL dataList, dataListSorted;
    
    // Step C : Called function "insertDataAtTail" to put 20 c-style string 
    //          into dataList and print out the result through function "print"
    std::cout << ">>> Verify dataList <<<" << std::endl;
    for (int i = 0; i < 20; i++) {
        dataList.insertDataAtTail(cstring[i].str);
    }
    dataList.print();

    // Step D : Called function "insertSortData" to put 20 c-style string
    //          into dataListSorted and using function "dataListSorted" to
    //          output the data and print out with "cout"
    std::cout << "\n>>> Verify dataListSorted <<<" << std::endl;
    for (int i = 0; i < 20; i++) {
        dataListSorted.insertSortData(cstring[i].str, cstring[i].index);
    }
    for (int i = 0; i < 20; i++) {
        std::cout << dataListSorted.removeDataFromHead() << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
