//
//  SearchTestCase.h
//  TestSearch
//
//  Created by Allen Chan on 13/10/3.
//  Copyright (c) 2013年 Allen Chan. All rights reserved.
//

#ifndef __TestSearch__SearchTestCase__
#define __TestSearch__SearchTestCase__

#include <iostream>

#include "Search.h"

typedef enum {
    FunctionalTest = 1,
    RandomFunctionalTest = 2,
} TestType;

typedef enum {
    TestSucceed = 1,
    TestFailed = 2
}TestResult;

TestResult goTest(TestType casetype);

#endif /* defined(__TestSearch__SearchTestCase__) */
