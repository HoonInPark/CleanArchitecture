#pragma once

#include <iostream>
using namespace std;

class ILowLvMod
{
public:
	virtual void LowLvFunc() = 0;
};

class LowLvMod : public ILowLvMod
{
public:
	virtual void LowLvFunc() override
	{
		cout << "this is Low Level Function Called" << endl;
	}
};

class HighLvMod
{
public:
	HighLvMod(unique_ptr<ILowLvMod> _InLowLvMod = make_unique<ILowLvMod>())
	{
		m_pLowLvMod = move(_InLowLvMod);
	}

	void HighLvFunc()
	{
		cout << "this is High Level Function Called" << endl;
		m_pLowLvMod->LowLvFunc();
	}

private:
	unique_ptr<ILowLvMod> m_pLowLvMod;
};
