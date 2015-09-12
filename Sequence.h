#ifndef __CS_32_Project_2_New__Sequence__
#define __CS_32_Project_2_New__Sequence__

#include <iostream>
#include <string>

typedef unsigned long ItemType;

class Sequence
{
public:
    Sequence();
    
    ~Sequence();    //Destructor
    
    Sequence(const Sequence& other);        //Copy Constructor
    
    Sequence& operator=(const Sequence& rhs);       //Assignment Operator
    
    bool empty() const;
    
    int size() const;
    
    void dump() const;      //Added to display to output
    
    bool insert(int pos, const ItemType& value);
    
    bool insert(const ItemType& value);
    
    bool erase(int pos);
    
    int remove(const ItemType& value);
    
    bool get(int pos, ItemType& value) const;
    
    bool set(int pos, const ItemType& value);
    
    int find(const ItemType& value) const;
    
    void swap(Sequence& other);
    
private:
    
    struct Node
    {
        ItemType m_data;
        Node* m_next;
        Node* m_prev;
    };
    
    Node* head;
    int m_size;
};


int subsequence(const Sequence& seq1, const Sequence& seq2);

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);


//Inline Functions

inline
bool Sequence::empty() const
{
    return (m_size == 0);
}

inline
int Sequence::size() const
{
    return m_size;
}


#endif /* defined(__CS_32_Project_2_New__Sequence__) */
