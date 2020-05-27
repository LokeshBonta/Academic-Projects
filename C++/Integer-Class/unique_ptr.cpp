#include"Integer.h"
#include <memory>

void Display(Integer *p)
{
    if(!p) return;
    std::cout << p->GetValue() << std::endl;
}

Integer *GetPointer(int value)
{
    Integer *p = new Integer(value);
    return p;
}

// void store(std::unique_ptr<Integer> p)
// {
//     std::cout << "writing to a file  " << p->GetValue() << std::endl;
// }

void store(std::unique_ptr<Integer> &p)
{
    std::cout << "writing to a file  " << p->GetValue() << std::endl;
}

void operate(int value)
{
    std::unique_ptr<Integer> p(GetPointer(value));
    if(p == nullptr)
        p.reset(new Integer);
    p->SetValue(value);
    Display(p.get());
    p.reset(new Integer());
    *p = __LINE__;
    Display(p.get());
    store(p); // Fine
   // store(std::move(p));// without move can't work
}

int main()
{
    operate(5);
    return 0;
}