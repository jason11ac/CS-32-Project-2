#include "Sequence.h"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;


void testString()
{
 
    Sequence s;
    assert(s.insert(0, "lavash"));
 
 
    assert(s.insert(0, "tortilla"));
    assert(s.size() == 2);
    ItemType x = "injera";
    assert(s.get(0, x)  &&  x == "tortilla");
    assert(s.get(1, x)  &&  x == "lavash");
 
 
 
    Sequence e;                     //Final test for string array
    assert(e.insert(0, "lavash"));
    assert(e.insert(0, "tortilla"));
    assert(e.erase(0));

    assert(e.size() == 1);
    ItemType n = "injera";
    assert(e.get(0, x) && x == "lavash");
    cerr << "Passes all tests" << endl;
 
 
    Sequence t;                                //Test for string array
    assert(t.empty());
    assert(t.find("laobing") == -1);
    t.insert("laobing");
    assert(t.size() == 1  &&  t.find("laobing") == 0);
    cerr << "Passed all tests" << endl;
 
 
    Sequence r;
    r.insert(0, "a");
    r.insert(1, "b");
    r.insert(2, "c");
    r.insert(3, "c");
    r.insert(4, "b");
    r.insert(5, "e");
 
 
    r.insert("c");
    r.insert("z");

    assert(r.remove("b") == 2);
 
    assert(r.size() == 6);

    string y;
    assert(r.remove("z") == 1);

    assert(r.get(0, y)  &&  y == "a");
    assert(r.get(1, y)  &&  y == "c");
    assert(r.get(2, y)  &&  y == "c");
    assert(r.get(3, y)  &&  y == "c");
    assert(r.get(4, y)  &&  y == "e");
    cerr << "Passed all tests" << endl;
 
 
    Sequence s1;
    s1.insert(0, "paratha");
    s1.insert(0, "focaccia");
    Sequence s2;
    s2.insert(0, "roti");
    s1.swap(s2);
    assert(s1.size() == 1  &&  s1.find("roti") == 0  &&  s2.size() == 2  && s2.find("focaccia") == 0  &&  s2.find("paratha") == 1);
    cerr << "Passed all tests" << endl;
 
 
    Sequence l;
    l.insert(0, "dosa");
    l.insert(1, "pita");
    l.insert(2, " ");
    l.insert(3, "matzo");
    assert(l.find(" ") == 2);
    l.remove("dosa");
    assert(l.size() == 3  &&  l.find("pita") == 0  &&  l.find(" ") == 1  && l.find("matzo") == 2);
    cerr << "Passed all tests" << endl;
 
    r.dump();
 
    cerr << endl;
 
    l.dump();
 
    cerr << endl;
 
    r = l;
 
    cerr << r.size() << endl;
    cerr << l.size() << endl;
 
    r.dump();
 
    cerr << endl;
 
    e.dump();
 
    e.swap(s);
 
    cerr << endl;
 
    e.dump();
 
 
    Sequence u;
 
    assert(u.insert(0, "42"));
    assert(u.insert(1, "62"));
    assert(u.insert(2, "84"));
    assert(u.insert(3, "20"));
    assert(u.insert(4, "90"));
    assert(u.insert(5, "1"));
 
 
    Sequence result;
    assert(result.insert("15"));
    assert(result.insert("25"));
    assert(result.insert("35"));
 
 
    Sequence q;
 
    assert(q.insert(0, "42"));
    assert(q.insert(1, "63"));
    assert(q.insert(2, "84"));
 
    Sequence z;
    Sequence p;
    Sequence c;
 
    interleave(q, z, q);
 
    q.dump();
 
    Sequence result1;
 
 
    cerr << endl;
 
 
    interleave(z, q, result1);
    interleave(q, q, result1);
 
    result1.dump();
 
    interleave(u, q, result);
 
    u.dump();
 
    interleave(u, q, u);
 
    cerr << endl;
    u.dump();
 
    assert(result.insert("30"));
    assert(result.insert("30"));
    assert(result.insert("30"));
 
    assert(result.remove("84") == 2);
    assert(result.get(0, x) && x == "30");
 
    assert(result.set(2, "20"));
    assert(result.get(2, x) && x == "20");
 
 
    assert(u.insert("30"));
    assert(u.insert("30"));
    assert(u.insert("30"));
 
    assert(u.remove("84") == 2);
    assert(u.get(0, x) && x == "30");
 
    assert(u.set(2, "20"));
    assert(u.get(2, x) && x == "20");
 
    u.dump();
 
    result.dump();
 
 
    Sequence k;
    assert(k.insert(0, "20"));
    assert(k.insert(1, "90"));
    //assert(k.insert(2, 20));
 
    assert(subsequence(result, k) == 7);
 
    Sequence w;
    assert(subsequence(result, w) == -1);
 
 
}




void testLong()
{
    
    Sequence s;
    assert(s.find(5) == -1);
    assert(s.remove(6) == 0);
    unsigned long z = 0;
    assert(s.get(1, z) == false);
    assert(s.set(4, 5) == false);
    assert(s.empty() == true);
    assert(s.insert(0, 10));
    assert(s.insert(0, 20));
    assert(s.insert(30));
    
    s.dump();
    
    assert(s.size() == 3);
    ItemType x = 999;
    assert(s.get(0, x) && x == 20);
    assert(s.get(1, x) && x == 10);
    assert(s.get(2, x) && x == 30);
    assert(s.erase(1));
    assert(s.find(30) == 1);
    assert(s.find(5) == -1);
    
    assert(s.insert(30));
    assert(s.insert(30));
    assert(s.insert(30));
    
    assert(s.remove(20));
    assert(s.get(0, x) && x == 30);
    
    assert(s.set(2, 20));
    assert(s.get(2, x) && x == 20);
    
    
    Sequence t;
    assert(t.insert(0, 5));
    assert(t.insert(0, 15));
    assert(t.size() == 2);
    ItemType y = 999;
    assert(t.get(0, y) && y == 15);
    assert(t.get(1, y) && y == 5);
    cerr << "Passed all tests" << endl;
    
    Sequence u;
    
    assert(u.insert(0, 42));
    assert(u.insert(1, 62));
    assert(u.insert(2, 84));
    assert(u.insert(3, 20));
    assert(u.insert(4, 90));
    assert(u.insert(5, 1));
    
    
    Sequence result;
    assert(result.insert(15));
    assert(result.insert(25));
    assert(result.insert(35));
    
    
    Sequence q;
    
    assert(q.insert(0, 42));
    assert(q.insert(1, 63));
    assert(q.insert(2, 84));
    
    
    
    cerr << endl;
    
    interleave(u, q, result);
    
    result.dump();
    
    assert(result.insert(30));
    assert(result.insert(30));
    assert(result.insert(30));
    
    assert(result.remove(84) == 2);
    assert(result.get(0, x) && x == 30);
    
    assert(result.set(2, 20));
    assert(result.get(2, x) && x == 20);
    
    result.dump();
    
    
    Sequence k;
    assert(k.insert(0, 20));
    assert(k.insert(1, 90));
    //assert(k.insert(2, 20));
    
    assert(subsequence(result, k) == 7);
    
    Sequence w;
    assert(subsequence(result, w) == -1);
    
}



#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }

void thisFunctionWillNeverBeCalled()
{
    Sequence();
    (Sequence(Sequence()));
    CHECKTYPE(&Sequence::operator=,  Sequence& (Sequence::*)(const ItemType&));
    CHECKTYPE(&Sequence::empty,      bool (Sequence::*)() const);
    CHECKTYPE(&Sequence::size,       int  (Sequence::*)() const);
    CHECKTYPE(&Sequence::insert,     bool (Sequence::*)(int, const ItemType&));
    CHECKTYPE(&Sequence::insert,     bool (Sequence::*)(const ItemType&));
    CHECKTYPE(&Sequence::erase,      bool (Sequence::*)(int));
    CHECKTYPE(&Sequence::remove,     int  (Sequence::*)(const ItemType&));
    CHECKTYPE(&Sequence::get,	 bool (Sequence::*)(int, ItemType&) const);
    CHECKTYPE(&Sequence::set,	 bool (Sequence::*)(int, const ItemType&));
    CHECKTYPE(&Sequence::find,       int  (Sequence::*)(const ItemType&) const);
    CHECKTYPE(&Sequence::swap,       void (Sequence::*)(Sequence&));
    CHECKTYPE(subsequence, int  (*)(const Sequence&, const Sequence&));
    CHECKTYPE(interleave,  void (*)(const Sequence&, const Sequence&, Sequence&));
}





int main()
{
    //testString();
    testLong();
    
    cout << "Passed all tests" << endl;
}
