//
//  Global.h
//  MiniSQL
//
//  Created by fan wu on 10/16/15.
//  Copyright © 2015 Fan Wu. All rights reserved.
//

#ifndef Global_h
#define Global_h

#include "assert.h"

typedef int PageIndexType;
const int MAXPATHDEEPTH = 100;
const int PAGESIZE = 4096 * sizeof(char);
const int ROOTPAGE = 1;
const PageIndexType UNDEFINEED_PAGE_NUM = -1;

#endif