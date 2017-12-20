// Implementation file for doublyLinkedList, a pointer-based by-position list of type
// specified in header.

#include "doublyLinkedList.h"     // header file
#include <cstddef>		// for NULL
#include <cassert>     // for assert()
#include <iostream>

doublyLinkedList::doublyLinkedList()	// Default Constructor
: size(0), head(NULL)
{
}


doublyLinkedList::~doublyLinkedList()	// Destructor
{
    bool success;
    
    while (!isEmpty())
    {
        success = deleteElement(1);  // Repeatedly delete item 1
    }
}


bool doublyLinkedList::isEmpty() const
{
    return (size == 0);
}


int doublyLinkedList::getLength() const
{
    return size;
}


// Copy Constructor
doublyLinkedList::doublyLinkedList(const doublyLinkedList& original)
: size(original.size)
{
    if (original.head == NULL)
        head = NULL;  // original list is empty
    
    else
    {
        // copy first node
        head = new listNode;
        assert(head != NULL);  // check allocation
        
        head->item = original.head->item;
        
        // copy rest of list
        listNode *newPtr = head;  // new list pointer
        
        
        // newPtr points to last node in new list
        // origPtr points to nodes in original list
        for (listNode *origPtr = original.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new listNode;
            assert(newPtr->next != NULL);
            
            newPtr = newPtr->next;
            
            newPtr->item = origPtr->item;
        }
        
        newPtr->next = NULL;
    }
    
}


// Locates a specified node in a linked list
// Parameters: the number of the desired node (starting at 1, an int)
// Returns: Returns a pointer to the desired node, or NULL if position out of range.
doublyLinkedList::listNode *doublyLinkedList::ptrTo(int position) const
{
    if ((position < 1) || (position > getLength()))
        return NULL;
    
    else  // count from the beginning of the list
    {
        listNode *cur = head;
        
        for (int skip = 1; skip < position; ++skip)
            cur = cur->next;
        
        return cur;
    }
}


bool doublyLinkedList::retrieveElement(int position, listItemType& dataItem) const
{
    bool success = ((position >= 1) && (position <= getLength()));
    
    if (success)
    {
        // get pointer to node, then data in node
        listNode *cur = ptrTo(position);
        
        dataItem = cur->item;
    }
    
    return success;
}



// Iterative doublyLinkedList Insert
void doublyLinkedList::insertElement(listItemType newItem)
{
    
    listNode *prev = NULL;
    listNode *cur = head;
    
    while ((cur != NULL) && (newItem > cur->item))
    {
        prev = cur;
        cur = cur->next;
    }
    
    listNode *newPtr = new listNode;
    newPtr->item = newItem;
    
    newPtr->next = cur;
    
    if (prev == NULL)
        head = newPtr;
    else
        prev->next = newPtr;
    
    size++;
}


void doublyLinkedList::locateElement(listItemType key, int& position)
{
    listNode *cur = head;
    
    position = 1;
    
    while (cur != NULL && cur->item != key)
    {
        cur = cur->next;
        position++;
    }
    
    if (cur == NULL)
        position = -1;
}


bool doublyLinkedList::deleteElement(int position)
{
    
    listNode *cur;
    
    bool success = ((position >= 1) && (position <= getLength()));
    
    if (success)
    {
        --size;
        
        if (position == 1)
        {
            // delete the first node from the list
            cur = head;  // save pointer to node
            head = head->next;
        }
        
        else
        {
            listNode *prev = ptrTo(position - 1);
            
            // delete the node after the node
            //    to which Prev points
            
            cur = prev->next;  // save pointer to node
            prev->next = cur->next;
        }
        
        // return node to system
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }
    
    return success;
}

void doublyLinkedList::reverse()
{
    
    listNode *next = head;
    listNode *prev = NULL;
    while (next != NULL) {
        listNode *temp = next->next;
        next->next = prev;
        head = next;
        prev = next;
        next = temp;
    }
    
}

void doublyLinkedList::printFront()
{
    listNode *ptr = head;
    
    while (ptr != NULL) {
        std::cout << ptr->item << " ";
        ptr = ptr->next;
    }
}

void doublyLinkedList::printBack()
{
    for (int i = size; i > 0; i--) {
        int data;
        retrieveElement(i, data);
        std::cout << data << " ";
    }
}

bool doublyLinkedList::operator== (const doublyLinkedList& right)
{
    //shortcut in case comparing same two doublyLinkedLists
    if (&right == this)
        return true;
    
    //check sizes are the same
    if (getLength() != right.getLength())
        return false;
    
    //temporary variables for comparison
    listItemType mine;
    listItemType theirs;
    
    //compare each element
    for (int i = 1; i <= getLength(); i++)
    {
        //use public methods to get each element
        retrieveElement(i, mine);
        right.retrieveElement(i, theirs);
        
        //return false after any mismatch
        if (mine != theirs)
            return false;
    }
    
    //if code gets here, all elements must be the same
    return true;
}

bool doublyLinkedList::operator!= (const doublyLinkedList& right)
{
    return !(*this == right);
    
}
