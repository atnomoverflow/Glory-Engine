#include <Glory.hpp>

class Sandbox : public Glory::Application
{
private:
    /* data */
public:
    Sandbox(/* args */);
    ~Sandbox();
};

Sandbox::Sandbox(/* args */)
{
}

Sandbox::~Sandbox()
{
}

Glory::Application *Glory::CreateApplication()
{
    return new Sandbox;
}
