#pragma once

#include <iostream>

using namespace std;

class IU1Ops
{
public:
    virtual void op1() = 0;
};

class IU2Ops
{
public:
    virtual void op2() = 0;
};

class OPS : public IU1Ops, public IU2Ops
{
public:
    virtual void op1() override
    {
        cout << "op1 Called" << endl;
    }

    virtual void op2() override
    {
        cout << "op2 Called" << endl;
    }
};

class User1
{
public:
    User1(IU1Ops& ops) : ops(ops) {}

    void DoWork()
    {
        ops.op1();
    }

private:
    IU1Ops& ops;
};

class User2
{
public:
    User2(IU2Ops& ops) : ops(ops) {}

    void DoWork()
    {
        ops.op2();
    }

private:
    IU2Ops& ops;
};
