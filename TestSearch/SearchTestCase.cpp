//
//  SearchTestCase.cpp
//  TestSearch
//
//  Created by Allen Chan on 13/10/3.
//  Copyright (c) 2013年 Allen Chan. All rights reserved.
//

#include "SearchTestCase.h"

#define Asc_N_Items 5
#define Desc_N_Items 5

#define TestCaseNumber 30

//public test Data
int asc_items[Asc_N_Items] = {0, 2, 4, 6, 8};
int desc_items[Desc_N_Items] = {8, 6, 4, 2, 0};


struct TestDataStruct {
    int n_items; // items number
    int *items;  // items array
    int ascending; // ItemSorted,
    SearchType type;
    int key;
    
    SearchResult expectResult;
    int expectIndex;
};

int createTestDataStruct(TestDataStruct** _testStruct , const int n_items){
    *_testStruct = (TestDataStruct*)malloc(sizeof(TestDataStruct));
    memset(*_testStruct, 0, sizeof(TestDataStruct));
    ((TestDataStruct*)*_testStruct)->n_items = n_items;
    ((TestDataStruct*)*_testStruct)->items = (int*)malloc(sizeof(int)*n_items);
    return 1;
}
void deleteTestDataStruct(TestDataStruct** _testStruct)
{
    free(((TestDataStruct*)*_testStruct)->items);
    ((TestDataStruct*)*_testStruct)->items=0;
    free(*_testStruct);
    *_testStruct = 0;
}


//functional test data;
// if there expect SearchReult are NotFound, the expect index should be '-1';
struct TestDataStruct testStruct[TestCaseNumber] ={  // 30 cases now.
    // key == 0 , five types , Ascending array :
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::Equals,0,SearchResult::FoundExact,0},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::GreaterThanEquals,0,SearchResult::FoundExact,0},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::GreaterThan,0,SearchResult::FoundGreater,1},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::LessThanEquals,0,SearchResult::FoundExact,0},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::LessThan,0,SearchResult::NotFound,-1},
    
    // key == 0, five type, Desc array , result should be same , focus on index :
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::Equals,0,SearchResult::FoundExact,4},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::GreaterThanEquals,0,SearchResult::FoundExact,4},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::GreaterThan,0,SearchResult::FoundGreater,3},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::LessThanEquals,0,SearchResult::FoundExact,4},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::LessThan,0,SearchResult::NotFound,-1},
    
    // key number between the minimum and maximum (NOT EQUALS), five types , Ascending array:
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::Equals,5,SearchResult::NotFound,-1},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::GreaterThan,5,SearchResult::FoundGreater,3},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::GreaterThanEquals,5,SearchResult::FoundGreater,3},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::LessThan,5,SearchResult::FoundLess,2},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::LessThanEquals,5,SearchResult::FoundLess,2},
    
    // key number between the min and max (EQUALS) , five types, Desc array:
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::Equals,4,SearchResult::FoundExact,2},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::GreaterThanEquals,4,SearchResult::FoundExact,2},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::GreaterThan,4,SearchResult::FoundGreater,1},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::LessThanEquals,4,SearchResult::FoundExact,2},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::LessThan,4,SearchResult::FoundLess,3},
    
    // key number out of the range, five types, Ascending array:
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::Equals,10,SearchResult::NotFound,-1},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::GreaterThan,10,SearchResult::NotFound,-1},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::GreaterThanEquals,10,SearchResult::NotFound,-1},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::LessThan,10,SearchResult::FoundLess,4},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::LessThanEquals,10,SearchResult::FoundLess,4},
    
    // free test:
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::LessThan,3,SearchResult::FoundLess,1},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::GreaterThanEquals,8,SearchResult::FoundExact,0},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::GreaterThan,2,SearchResult::FoundGreater,2},
    {Desc_N_Items,desc_items,ItemSorted::Descending,SearchType::LessThanEquals,7,SearchResult::FoundLess,1},
    {Asc_N_Items,asc_items,ItemSorted::Ascending,SearchType::LessThanEquals,6,SearchResult::FoundExact,3}
};


void printSearchType(const SearchType type)
{
    switch (type) {
        case SearchType::Equals:
        {
            std::cout<<"searchType = [Equals] : \n";
        }break;
        case SearchType::LessThan:
        {
            std::cout<<"searchType = [LessThan] : \n";
        }break;
        case SearchType::LessThanEquals:
        {
            std::cout<<"searchType = [LessThanEquals] : \n";
        }break;
        case SearchType::GreaterThan:
        {
            std::cout<<"searchType = [GreaterThan] : \n";
        }break;
        case SearchType::GreaterThanEquals:
        {
            std::cout<<"searchType = [GreaterThanEquals] : \n";
        }break;
        default:
            break;
    }
}

void printResult(const SearchResult result,const int index)
{
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
}


TestResult functionalTest(const TestDataStruct testStruct)
{
    int index = -1;
    
    SearchResult result = SearchResult::NotFound;
    result = Search(testStruct.items,
                    testStruct.n_items,
                    testStruct.ascending,
                    testStruct.key,
                    testStruct.type,
                    &index);
    
    if(result == testStruct.expectResult && index == testStruct.expectIndex){
        std::cout<<"Test result is true : ";
        printResult(result,index);
    }else{
        std::cout<<"Error :: Test result is wrong: \n currentResult = "<<result<<" expectResult = "
        <<testStruct.expectResult<<"\n currentIndex = "<<index<<" - expectIndex = "<<testStruct.expectIndex<<"\n";
        
        return TestResult::TestFailed;
    }
    return TestResult::TestSucceed;
}


TestResult randomFunctionalTest(const TestDataStruct testStruct)
{
    int index = -1;
    
    SearchResult result = SearchResult::NotFound;
    result = Search(testStruct.items,
                    testStruct.n_items,
                    testStruct.ascending,
                    testStruct.key,
                    testStruct.type,
                    &index);
    
    std::printf("key = [%d] : ",testStruct.key);
    printSearchType(testStruct.type);
    printResult(result,index);
    
    return TestResult::TestSucceed;
}

// init the items array data from random number;
TestResult initItems(int _items[],const int items_count,const int ascending)
{
    switch (ascending) {
        case ItemSorted::Ascending:
        {
            int item_value = 0;
            // get the Ascending & Unique random number to items.
            std::cout<<"items = [";
            srand((unsigned)rand());
            for (int i=0; i<items_count; ++i) {
                item_value += rand()%100;//acs
                _items[i] = item_value;
                std::cout<<item_value<<",";
            }
            std::cout<<"]\n";
            
        }break;
        case ItemSorted::Descending:
        {
            int item_value = 100;
            int temp_value = 0;
            
            // get the Descending & Unique random number to items.
            std::cout<<"items = [";
            srand((unsigned)rand());
            for(int i = 0;i<items_count;++i){
                
                if(item_value == 0)
                    item_value++;
                
                temp_value = rand()%item_value+10;
                item_value-=(temp_value/2+1);
                _items[i] = item_value;
                std::cout<<item_value<<",";
            }
            std::cout<<"]\n";
            
        }break;
        default:
            return TestResult::TestFailed;
            break;
    }
    return TestResult::TestSucceed;
}


//initialization random value for items, key, searchtype, sorted,etc...
TestResult initRandomTestData(TestDataStruct** _testStruct)
{
    ((TestDataStruct*)*_testStruct)->ascending = rand()%2+1;
    
    TestResult result = initItems(((TestDataStruct*)*_testStruct)->items,
                                  ((TestDataStruct*)*_testStruct)->n_items,
                                  ((TestDataStruct*)*_testStruct)->ascending);
    if(result==TestResult::TestFailed)
        return result;
    
    ((TestDataStruct*)*_testStruct)->key = rand()%300-150;//rand()%RAND_MAX-RAND_MAX/2;
    ((TestDataStruct*)*_testStruct)->type = (SearchType)(rand()%SearchType::GreaterThan);
    
    return TestResult::TestSucceed;
}


TestResult goTest(TestType _testType)
{
    switch (_testType) {
        case TestType::FunctionalTest:
        {
            // is also can be load file for test case.
            std::cout<<"------------ Function Test ------------\n";
            for (int i=0; i<TestCaseNumber; ++i) {
                std::cout<<i+1<<" - ";
                if(functionalTest(testStruct[i]) == TestResult::TestFailed){
                    return TestResult::TestFailed;
                }
            }
        }break;
        case TestType::RandomFunctionalTest:
        {
            TestDataStruct* testData =0;
            std::cout<<"------------ Random Function Test ------------\n";
            
            for (int i=0; i<TestCaseNumber; ++i) {
                srand((unsigned)rand());
                std::cout<<"\n"<<i+1<<" - \n";
                createTestDataStruct(&testData, (rand()%10+5)); //between 5-14
                
                if(initRandomTestData(&testData)== TestResult::TestSucceed){
                    if(randomFunctionalTest(*testData) == TestResult::TestFailed){
                        deleteTestDataStruct(&testData);
                        return TestResult::TestFailed;
                    }
                }
                
                deleteTestDataStruct(&testData);
            }
            
        }break;
        default:
            break;
    }
    
    return TestResult::TestSucceed;
}
