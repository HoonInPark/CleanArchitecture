#pragma once

#include <iostream>

using namespace std;

class IService
{
public:
	virtual void Execute() = 0;
};

class ServiceImpl : public IService
{
public:
	virtual void Execute() override
	{
		cout << "Concrete Service Executed" << endl;
	}
};

class IFactory
{
public:
	virtual IService* MakeService() = 0;
};

class FactoryImpl : public IFactory
{
public:
	virtual IService* MakeService() override
	{
		return new ServiceImpl;
	}
};

class Application
{
public:
	Application(IFactory* _pInFac)
		: m_Factory(_pInFac)
	{
		m_Service = m_Factory->MakeService();
		m_Service->Execute();
	}

private:
	IFactory* m_Factory;
	IService* m_Service;
};
