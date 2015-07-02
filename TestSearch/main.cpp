//
//  main.cpp
//  TestSearch
//
//  Created by Allen Chan on 13/10/1.
//  Copyright (c) 2013年 Allen Chan. All rights reserved.
//

#include <iostream>
#include "Search.h"
#include "SearchTestCase.h"

#define TEST_MODE 1


/*
 * Assumptions
 * -----------
 *  The items are sorted
 *  Items will be non-NULL
 *  There are no duplicate items
 *  n_items will be > 0
 */

int main(int argc, const char * argv[])
{
#if TEST_MODE == 1
    //test
    goTest(TestType::FunctionalTest);
    goTest(TestType::RandomFunctionalTest);
#else
    /*
    const int n_items = 5;
    const int items[] = {0, 2, 4, 6, 8};
    const int ascending = ItemSorted::Ascending;
    SearchType type = SearchType::LessThan;
    int key = 6;
    */
    
    const int n_items = 5;
    const int items[] = {8, 6, 4, 2, 0};
    const int ascending = ItemSorted::Descending;
    SearchType type = SearchType::LessThanEquals;
    int key = 3;
    
    int index = -1;
    
    SearchResult result = SearchResult::NotFound;
    
    result = Search(
           items,
           n_items,
           ascending,
           key,
           type,
           &index);
    
    switch (result) {
        case SearchResult::NotFound:
            std::cout<<"Result is NOT FOUND\n";
            break;
        case SearchResult::FoundLess:
            std::cout<<"Result is FOUND LESS - index = "<<index<<"\n";;
            break;
        case SearchResult::FoundGreater:
            std::cout<<"Result is FOUND GREATER - index = "<<index<<"\n";;
            break;
        case SearchResult::FoundExact:
            std::cout<<"Result is FOUND EXACT - index = "<<index<<"\n";
            break;
        case SearchResult::WrongType:
            std::cout<<"the Search Type is Wrong. \n";
            break;
        default:
            break;
    }
#endif
    return 0;
}

