//
// Created by alexey on 26.09.15.
//

#include "Block.h"

Block::Block(){
    //isFree = true;

    size = 0;

    startAddress = NULL;
}

Block::Block(unsigned int newSize, void *newStartAddress){
    //isFree = true;

    size = newSize;

    startAddress = newStartAddress;
}

Block::~Block(){
    //isFree = true;

    size = 0;

    startAddress = NULL;
}


Block* Block::Allocate(unsigned int sizeToAllocate){

    /*Розділення блоку можливе тільки, якщо цей блок вільний і не менший, ніж необхідно.*/
    if(/*!(IsFree() &&*/ !CanAllocate(sizeToAllocate)){
        return NULL;
    }

    /*
     * Якщо необхідний розмір співпадає із розміром блоку, то цей блок помічається як зайнятий.
     * Розділення блоку в такому випадку не відбувається.
     * */
    if(sizeToAllocate == size){

        //isFree = false;

        return this;
    }

    /*Якщо ж необхідний розмір менший за розмір блоку, то цей блок розділяється на дві частини.*/
    size -= sizeToAllocate;
    void* startAddressForNewBlock = startAddress + size;
    return new Block(sizeToAllocate, startAddressForNewBlock);

}
