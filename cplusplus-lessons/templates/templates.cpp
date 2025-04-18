#include <iostream>
#include <string>

// Шаблон - идея
// У вас может быть много функций, которые делают одно и тоже - например max
// И делала бы она одно и тоже, но тип был бы каждый раз разный
// Фактически для любого квантора, где T - это для компилятора понятно что - метапеременная
// Узнает реально, когда будет вызов этой функции.
// Два этапа компиляции -  когда T - неизвестная  и проверяет синтаксичекую корректность, независмую от типа
// И на втором - когда вызов - корректность 

// При этом адресса для этих функций, при разных вызовах имеют свой адресс при каждом вызове
// Компилятор сгенерирует столько функций - сколько будет версий типов, который будет вызывать это 

// template<typename T> - вы должны обязательно быть объявлены, и не могут быть объявить внутри функции - то есть локально 
// Внутри класса можно сделать свои шаблоные типы, методы

template <typename T>
T mymax(T a, T b)
{
    return a > b ? a : b;
}

template<typename T> //  В пределеах класса/структуры/функции - T - шаблонный параматер будет действать пока находимся в этих пределах
struct Sa{

};

// Для алиасов  - псевдонимов, которые через typedef, using
// template<typename T>
// using umap = std::unordered_map<T, T>

// Для шаблонных переменных 
template <typename T>
T pi = 3.14;

// int max(int a, int b)
// {
//     return a > b ? a : b;
// }

// double max(double a, double b)
// {
//     return a > b ? a : b;
// }

// std::string max(std::string a, std::string b){
//     return a > b ? a : b;
// }

template<typename U>
struct S{
    U X;

    template<typename F>
    void f(U a, F b);
};

// Как определеить f
// Нельзя написать template<typename U, typename F> так как это относится к разным определениям
template<typename U>
template<typename F>
void S<U>::f(U a, F b){

}

int main(){
    //umap<int> um;

    int(*pfi)(int, int) = &mymax<int>;
    double(*pfd)(double, double) = &mymax<double>;

    S<int> s;
    // ДЛя функции шаблонный параметр определяется автоматически, а не определять для <>
    s.f(0, 1);
    s.f<int>(0, 1);

    std::cout<< (int*)pfi << "  " << (int*)pfd << std::endl; // Через реинтерпрет касты, видно, что разные адреса, причем не идут друг за другом
    mymax(1, 3);
    mymax(std::string("aaa"), std::string("aa"));
    // max(std::cout, std::cout); - не будет работать, так как для этого не определено max
}