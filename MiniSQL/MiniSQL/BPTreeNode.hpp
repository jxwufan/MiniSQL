//
//  BPTreeNode.hpp
//  MiniSQL
//
//  Created by fan wu on 10/26/15.
//  Copyright © 2015 Fan Wu. All rights reserved.
//

#ifndef BPTreeNode_hpp
#define BPTreeNode_hpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "Global.h"
#include "BPTreeKey.hpp"
#include "BPTreeEntry.hpp"
#include "Page.hpp"
#include "BufferManager.hpp"

using namespace std;

enum class BPTreeNodeType {
    BPTreeUndefinedNode,
    BPTreeRootNode,
    BPTreeInternalNode,
    BPTreeLeafNode
};

class BPTreeNode {
    BPTreeNode() {
        entryNumber            = 1; //第一个entry只会用指针部分
        keyDataLength          = 0;
        keyType                = BPTreeKeyType::UNDEFINED;
        parentNodePagePointer  = UNDEFINEED_PAGE_NUM;
        siblingNodePagePointer = UNDEFINEED_PAGE_NUM;
        nodeType               = BPTreeNodeType::BPTreeUndefinedNode;
        memset(nodePath, 0, MAXPATHDEEPTH * sizeof(PageIndexType));
    }

    BPTreeNode(const BPTreeNode &node) {
        entryNumber            = node.entryNumber;
        keyDataLength          = node.keyDataLength;
        keyType                = node.keyType;
        parentNodePagePointer  = node.parentNodePagePointer;
        siblingNodePagePointer = node.siblingNodePagePointer;
        nodePage               = node.nodePage;
        nodeType               = node.nodeType;
        memcpy(nodePath, node.nodePath, MAXPATHDEEPTH * sizeof(PageIndexType));
    }
    ~BPTreeNode() {}

    void            readNodeRawData();
    void            writeNodeRawData();

    void            convertToRawData();
    void            parseFromRawData();

    bool            isOverflow();
    bool            isRoot();
    bool            isLeaf();

    bool            insertEntry(BPTreeEntry entry);
    bool            deleteEntry(BPTreeEntry entry);

    bool            insertEntryAtIndex(BPTreeEntry entry, int index);
    bool            deleteEntryAtIndex(int index);

    int             getNodeRawDataLength();

    BPTreeEntry     nodeEntries[1024];
    int             entryNumber;
    int             keyDataLength;
    BPTreeKeyType   keyType;
    PageIndexType   parentNodePagePointer;
    PageIndexType   siblingNodePagePointer;
    Page            nodePage;
    PageIndexType   nodePath[MAXPATHDEEPTH];
    BPTreeNodeType  nodeType;
};

#endif /* BPTreeNode_hpp */
