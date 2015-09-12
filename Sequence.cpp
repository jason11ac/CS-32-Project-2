#include "Sequence.h"


Sequence::Sequence()
: m_size(0)
{
    head = new Node;          //Dummy node. Creating a circularly double linked list
    head->m_next = head;
    head->m_prev = head;
}


Sequence::~Sequence()
{
    int i = 0;
    
    for (Node* temp = head->m_prev; i != (m_size + 1); i++)       //m_size plus one to account for the dummy Node
    {
        Node* tempDel = temp;   //Makes a temp pointer for the Node that needs to be deleted
        
        temp = temp->m_prev;    //Move to the next Node
        
        delete tempDel;         //Delete the previous Node
    }
}


Sequence::Sequence(const Sequence& other)       //Copy Constructor
:m_size(other.m_size)
{
    
    head = new Node;        //Make a dummy Node
    
    head->m_next = head;   //Set pointers to itself
    
    head->m_prev = head;
    
    for (Node* temp = other.head->m_next ; temp != other.head; temp = temp->m_next)
    {
        Node* newNode = new Node;
        
        newNode->m_data = temp->m_data;     //Set value
        
        newNode->m_prev = head->m_prev;     //Set previous pointer of new Node
        
        head->m_prev = newNode;          //Set previous pointer of head to the new Node
        
        newNode->m_prev->m_next = newNode;  //Set next pointer of previous node to new Node
    }
    
    head->m_prev->m_next = head;       //At the end make newest Node's next pointer point to the head/dummy Node
}



Sequence& Sequence::operator=(const Sequence& rhs)      //Assignment Operator
{
    if (this != &rhs)       //Same setup as for the original Sequence in hw 1. Modern verison of A.O.
    {
        Sequence temp(rhs);
        swap(temp);
    }
    return *this;
}


void Sequence::dump() const           //Displays the linked list to output
{
    for (Node* t = head->m_next; t != head; t = t->m_next)
        std::cerr << t->m_data << std::endl;
}



bool Sequence::insert(int pos, const ItemType &value)   //Inserts value as a new node into pos
{
    if (pos < 0 || pos > m_size)
        return false;
    
    
    //If the Sequence is an empty list:
    
    if (m_size == 0)
    {
        Node* newNode = new Node;
        newNode->m_data = value;
        newNode->m_next = head;
        newNode->m_prev = head;
        head->m_prev = newNode;
        head->m_next = newNode;
        m_size++;
        return true;
    }
    
    //If the Sequence is not an empty list:
    
    int i = 0;
    Node* temp;
    for (temp = head->m_next; i != pos; temp = temp->m_next)    //Makes a pointer to the node before the node at pos
        i++;
    
    
    Node* newNode = new Node;
    newNode->m_data = value;
    newNode->m_next = temp;
    newNode->m_prev = temp->m_prev;
    temp->m_prev = newNode;
    newNode->m_prev->m_next = newNode;
    m_size++;
    return true;
    
}

bool Sequence::insert(const ItemType &value)        //Inserts value as a new node before the first node that is >= value. If none exist, pos == m_size
{
    
    //If the Sequence is an empty list:
    
    if (m_size == 0)
    {
        insert(0, value);
        return true;
    }
    
    //If the Sequence is not an empty list:
    
    int p = 0;
    int count = 0;
    
    for (Node* temp = head->m_next; temp != head; temp = temp->m_next)
    {
        if (value <= temp->m_data)
        {
            p = count;
            insert(p, value);
            return true;
            
        }
        count++;
    }
    p = count;
    insert(p, value);
    return true;
    
}

bool Sequence::erase(int pos)       //Delete the node at pos
{
    
    //Works for all cases of valid pos. Can not delete the dummy Node
    
    if (pos < 0 || pos >= m_size)
        return false;
    
    int i = 0;
    Node* temp;
    for (temp = head->m_next; i != pos; temp = temp->m_next)
        i++;
    
    
    temp->m_prev->m_next = temp->m_next;
    temp->m_next->m_prev = temp->m_prev;
    delete temp;
    m_size--;
    return true;
}



int Sequence::remove(const ItemType &value)     //Delete all cases of value in linked list
{
    
    //Works for all cases. Also can not delete dummy Node
    
    int count = 0;
    int i = m_size;
    while (i != 0)
    {
        int k = find(value);
        
        if (k != -1)
        {
            erase(k);
            count++;
        }
        i--;
    }
    return count;
}


bool Sequence::get(int pos, ItemType &value) const      //Gets m_data of node at pos and makes value equal it
{
    
    //Works for all cases of valid pos
    
    if (pos < 0 || pos >= m_size)
        return false;
    
    Node* temp;
    int k = 0;
    for (temp = head->m_next; k != pos; temp = temp->m_next)
        k++;
    
    value = temp->m_data;
    return true;
    
}


bool Sequence::set(int pos, const ItemType &value)      //Sets m_data of a node at pos to value
{
    //Works for all cases of value pos
    
    if (pos < 0 || pos >= m_size)
        return false;
    
    Node* temp;
    int k = 0;
    for (temp = head->m_next; k != pos; temp = temp->m_next)
        k++;
    
    temp->m_data = value;
    return true;
}


int Sequence::find(const ItemType &value) const     //Searches the linked list for value
{
    int k = 0;
    Node* temp;
    for (temp = head->m_next; temp != head; temp = temp->m_next)
    {
        if (temp->m_data == value)
            return k;
        k++;
    }
    return -1;
}


void Sequence::swap(Sequence &other)        //Swap two listed and their lengths
{
    
    //Swap the lengths of the linked lists
    
    int tempSize = m_size;
    
    m_size = other.m_size;
    
    other.m_size = tempSize;
    
    
    
    //Swap linked list pointers
    
    Node* tempList = head;         //tempArr points to head
    
    head = other.head;          //head becomes other head
    
    other.head = tempList;       //other head becomes what tempArr points to
    
}



int subsequence(const Sequence& seq1, const Sequence& seq2)     //Looks for a subsequence in seq1 that matches seq2
{
    ItemType x;
    
    ItemType y;
    
    int count = 0;
    
    //if seq2 is empty the function returns -1
    
    if (seq2.size() == 0)
        return -1;
    
    seq2.get(0, y);
    
    for (int i = 0; i < seq1.size(); i++)
    {
        seq1.get(i, x);
        if (x == y)
        {
            for (int k = 0; k < seq2.size(); k++)
            {
                ItemType a;
                ItemType b;
                seq1.get((i + k), a);
                seq2.get(k, b);
                if (a == b)
                    count++;
            }
        }
        if (count == seq2.size())
            return i;
        count = 0;
    }
    
    
    return -1;
}


void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)       //Interleaves two linked lists into one listed list, result
{
    
    //If seq1 is an empty linked list. If seq2 is empty linked list, seq1 will copy to result automatically
    
    if (seq1.empty())
    {
        result = seq2;
        return;
    }
    
    
    //No alias Sequences
    
    Sequence temp(seq1);
    int i = 1;
    int count = 0;
    for (int k = 0; k < seq2.size(); k++)
    {
        ItemType z;
        
        seq2.get(k, z);
        
        temp.insert(i, z);
        count++;
        
        if (count < (seq1.size()))
            i += 2;
        else
            i++;
    }
    result.swap(temp);
    
}
