#include <iostream>

struct Granny
{
    int g;
    virtual void foo() {std::cout << "Granny";}; // - благодаря этому все типы полиморфные  -  поддержка RTTI
};

struct Mom : public Granny
{
    int m;
    void foo() {std::cout << "Mom";}; 
};

struct Dad : public Granny
{
    int f;
    void foo() {std::cout << "Dad";}; 
};

struct Son : public Mom, public Dad
{
    int s;
};

int main()
{
    Son s;
    Mom *pm = &s;
    Granny *pg = pm;

    // Son * ps = pm; // в низ неявный каст не работает
    // Если я хочу Son прикоставать к Mom, а потом Mom прикастовать к Dad.
    // Mom и Dad не лежат в одной цепи наследование, поэтому static_cast не будет работать

    // Однако тип Son - полиморфный, и сейсас реально лежит Son, то есть в нем лежит реальный тип, и мы хотим прикастова
    // и pm  -  указатель на Son, хоть и Mom. И для этого используют dynamic_cast
    // dynamic_cast - операция, которая использует RTTI что бы понять можно ли применить cats
    // Оператор, который идет в указатель, и ищет поле RTTI , и понимает какой объект на самом деле у объекта, и какой
    // сдвиг должен быть, чтобы прикастовать

    Dad *pd = dynamic_cast<Dad*>(pm); // Если каст не произошел в runtime, то не кидается ошибка, а просто возвращается
    //null_ptr
    // static_cast тут не используется
    pd->foo();

    // dynamic_cast работает с ссылками и указателями и для полиморфных типов
    // То есть если у нас есть объект,  который наследуется от нескольких классов, то можно обратиться к одному из параллельних классов
    // то можно от одного класса скастоваться к наследнику
    Mom & m = s;
    Dad & f = dynamic_cast<Dad&>(m);

    f.foo();

    Mom m1; // Тут не работает так
    Dad & f1 = dynamic_cast<Dad&>(m1); // Aborted (core dumped) - runtimeError
// terminate called after throwing an instance of 'std::bad_cast'
//  what():  std::bad_cast - ошибка которая ловиться через try - catch

    Mom m2; // Тут не работает так, 
    Dad* f2 = dynamic_cast<Dad*>(&m2); // Aborted (core dumped) 
    f2->foo(); // так как тут f2 - nullptr -  Segmentation fault (core dumped)
}