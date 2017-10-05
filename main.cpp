#include <iostream>

class Test
{
public:
    Test(int id = 0) :
            _id(id)
    {
        std::cout << "Test Constructor " << std::string(*this) << std::endl;
    }

    Test(const Test& copy) :
        _id(copy._id)
    {
        std::cout << "Test Copy Constructor " << std::string(*this) << std::endl;
    }

    Test(Test&& moveObj) :
        _id(moveObj._id)
    {
        moveObj._id = -1;
        std::cout << "Test Move Constructor " << std::string(*this) << std::endl;
    }

    operator std::string() const
    {
        return std::to_string(long(this)) + "_" + std::to_string(_id);
    }

    ~Test()
    {
        std::cout << "Test Destructor " << std::string(*this) << std::endl;
    }

private:
    int _id;
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    Test&& valueOne = Test(1);

    Test valueTwo = valueOne;

    Test valueThree = std::move(valueOne);

    std::cout << "valueOne: " << std::string(valueOne) << std::endl;
    std::cout << "valueTwo: " << std::string(valueTwo) << std::endl;
    std::cout << "valueThree: " << std::string(valueThree) << std::endl;

    return 0;
}