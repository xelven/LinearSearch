//
//  Search.cpp
//  TestSearch
//
//  Created by Allen Chan on 13/10/1.
//  Copyright (c) 2013年 Allen Chan. All rights reserved.
//

#include "Search.h"

//functional interface
typedef SearchResult(*PtFunction)(const int item,const int key);


// there are 5 functional methods
SearchResult equals(const int item, const int key)
{
    if (item == key){
        return SearchResult::FoundExact;
    }
    return SearchResult::NotFound;;
}

SearchResult greaterThan(const int item, const int key)
{
    if(item > key){
        return SearchResult::FoundGreater;
    }
    return SearchResult::NotFound;
}

SearchResult greaterThanEquals(const int item, const int key)
{
    SearchResult status = equals(item,key);
    if(status == SearchResult::FoundExact){
        return status;
    }else{
        status = greaterThan(item,key);
    }
    return status;
}

SearchResult lessThan(const int item, const int key)
{
    if(item < key){
        return SearchResult::FoundLess;
    }
    return SearchResult::NotFound;
}

SearchResult lessThanEquals(const int item, const int key)
{
    SearchResult status = equals(item,key);
    if(status == SearchResult::FoundExact){
        return status;
    }else{
        status = lessThan(item,key);
    }
    return status;
}



SearchResult Search(
                    const int * const items,
                    const int n_items,
                    const int ascending,
                    const int key,
                    const SearchType type,
                    int* const index)
{
    // init 
    int currentIndex = 0;
    int endIndex = n_items-1;
    bool ascLoop = true;
    bool isLoop = true;
    
    PtFunction ComparePtr = 0;
//////////
/* also can add the method like 
 'int getSearchTypeFunction(const int type,PtFunction* comparePtr, bool *ascLoop);' 
 to get the function pointer; */
    switch (type) {
        case SearchType::Equals:{
            ComparePtr = &equals;
        }break;
        case SearchType::GreaterThan:{
            if(ascending == ItemSorted::Descending){
                ascLoop = false;
            }
            ComparePtr = &greaterThan;
        }break;
        case SearchType::GreaterThanEquals:{
            if(ascending == ItemSorted::Descending){
                ascLoop = false;
            }
            ComparePtr = &greaterThanEquals;
        }break;
        case SearchType::LessThan:{
            if(ascending == ItemSorted::Ascending){
                ascLoop = false;
            }
            ComparePtr = &lessThan;
        }break;
        case SearchType::LessThanEquals:{
            if(ascending == ItemSorted::Ascending){
                ascLoop = false;
            }
            ComparePtr = &lessThanEquals;
        }break;
        default:
            // wrong type
            return SearchResult::WrongType;
            break;
    }
///////////////////
    
    //check the loop method
    if(ascLoop==true){
        currentIndex = 0;
        endIndex = n_items-1;
    }else{
        currentIndex = n_items-1;
        endIndex = 0;
    }
    
    //loop each one
    while (isLoop) {
        SearchResult result= ComparePtr(items[currentIndex],key);
        if(result != SearchResult::NotFound)
        {
            *index = currentIndex;
            return result;
        }
        
        if(ascLoop==true){
            ++currentIndex;
            if(currentIndex > endIndex)
                isLoop = false;
        }else{
            --currentIndex;
            if(currentIndex < endIndex)
                isLoop = false;
        }
    }
    
    return SearchResult::NotFound;
}
