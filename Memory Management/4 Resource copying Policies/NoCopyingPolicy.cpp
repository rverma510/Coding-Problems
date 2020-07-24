/*
The simplest policy of all is to forbid copying and assigning class instances all together. 
This can be achieved by declaring, but not defining a private copy constructor and assignment operator 
(see NoCopyClass1 below) or alternatively by making both public and assigning the delete operator 
(see NoCopyClass2 below). The second choice is more explicit and makes it clearer to the programmer 
that copying has been actively forbidden.
*/
class NoCopyClass1 {
  private:
    NoCopyClass1(const NoCopyClass1 &);
    NoCopyClass1 &operator =(const NoCopyClass1 &);
  public:
    NoCopyClass1() {}
};

class NoCopyClass2 {
  public:
    NoCopyClass2() {}
    NoCopyClass2(const NoCopyClass2 &) = delete; 
    NoCopyClass2 &operator =(const NoCopyClass2 &) = delete;
};

int main() {
    NoCopyClass1 obj1;
    NoCopyClass1 a1(obj1);  // copy constructor
    NoCopyClass1 b1 = obj1; // assignment operator  

    NoCopyClass2 obj2;
    NoCopyClass2 a2(obj2);  // copy constructor
    NoCopyClass2 b2 = obj2; // assignment operator  

    return 0;  
}