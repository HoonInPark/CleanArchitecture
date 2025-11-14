#pragma once

// 거대한 OPS 클래스
class OPS
{
public:
    void op1()
    {
        // ... 매우 큰 기능
    }

    void op2()
    {
        // ... 매우 다른 기능
    }

    void op3()
    {
        // ... 또 다른 기능
    }
};

// User1: op1만 필요하지만 OPS 전체에 의존
class User1 
{
public:
    User1(OPS& ops) : ops(ops) {}

    void DoWork()
    {
        ops.op1();   // 이것만 필요!
    }

private:
    OPS& ops;
};

// User2: op2만 필요
class User2
{
public:
    User2(OPS& ops) : ops(ops) {}

    void DoWork()
    {
        ops.op2();   // 이것만 필요!
    }

private:
    OPS& ops;
};

// User3: op3만 필요
class User3
{
public:
    User3(OPS& ops) : ops(ops) {}

    void DoWork()
    {
        ops.op3();  // 이것만 필요!
    }

private:
    OPS& ops;
};
