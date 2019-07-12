#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <vector>

using namespace emscripten;

class MyClass {
private:
    std::vector<double> d_vector;

public:
    MyClass() 
    {
        d_vector.reserve(10000);
    }
    void fill() 
    {
        for (int i = 0; i < 10000; i++){
            d_vector.push_back(i);
        }
    }
    void insertItem(double item) 
    {
        d_vector.insert(d_vector.begin(), 1, item);
    }

    double getItem(int index)
    {
        return d_vector[index];
    }
};

EMSCRIPTEN_BINDINGS(my_module) {
    class_<MyClass>("MyClass")
        .constructor<>()
        .function("fill", &MyClass::fill)
        .function("insertItem", &MyClass::insertItem)
        .function("getItem", &MyClass::getItem);
}

