#pragma once

#include <iostream>

using namespace std;

class CFO
{
};

class CEO
{
};

class CTO
{
};

class Employee
{
public:
	int CalPay()
	{
		cout << "CalPay() Called" << endl;
		RegularWorkingHours();
		return -1;
	}

	int ReportHours()
	{
		cout << "ReportHours() Called" << endl;
		RegularWorkingHours();
		return -1;
	}

private:
	int RegularWorkingHours()
	{
		cout << "RegularWorkingHours() Called" << endl;
		return -1;
	}
};

///////////////////////////////////////////////////////////////////////////
class EmployeeData
{
public:
    EmployeeData(int _InHoursWorked, int _InHourlyRate)
        : m_HoursWorked(_InHoursWorked)
        , m_HourlyRate(_InHourlyRate)
    {
    }

    int GetHoursWorked() const { return m_HoursWorked; }
    int GetHourlyRate() const { return m_HourlyRate; }

private:
    int m_HoursWorked;
    int m_HourlyRate;
};

class PayCalculator
{
public:
    int CalPay(const EmployeeData& _InData)
    {
        return _InData.GetHoursWorked() * _InData.GetHourlyRate();
    }
};

class HourReporter
{
public:
    int ReportHours(const EmployeeData& _InData)
    {
        return _InData.GetHourlyRate();
    }
};

class EmployeeFacade
{
public:
    EmployeeFacade()
        : m_PayCalculator(make_unique<PayCalculator>())
        , m_HourReporter(make_unique<HourReporter>())
    {
    }

    int CalPay(const EmployeeData& _InData)
    {
        // 위임!
        return m_PayCalculator->CalPay(_InData);
    }

    int ReportHours(const EmployeeData& _InData)
    {
        // 위임!
        return m_HourReporter->ReportHours(_InData);
    }

private:
    unique_ptr<PayCalculator> m_PayCalculator;
    unique_ptr<HourReporter> m_HourReporter;
};

/*
int main()
{
    EmployeeData emp(40, 25); // 40시간 근무, 시급 25달러
    EmployeeFacade facade;
    facade.ProcessEmployee(emp);
}
*/
