#include <iostream>

struct A{};

struct B{
    virtual void f() {};
};

struct Base{
    virtual void f() {};
};

struct Derived: public Base{
    void f() override {};
};


struct Granny{
    void f() {}
};

struct Mom: public Granny{
    virtual void f(){};
};

struct Son: public Mom{
    void f() {};
};

// Чему будет равен размер Derived

int main(){
    A a;
    B b;
    std::cout << sizeof(a) << std::endl; // 1 
    std::cout << sizeof(b) << std::endl; // 8 - так как B -  полиморфная структура, в которой есть RTTI - указатель, где
    // храниться информация о vtable - область в статической памяти

    std::cout << sizeof(Derived) << std::endl; // Тоже размер будет равен 8 
}