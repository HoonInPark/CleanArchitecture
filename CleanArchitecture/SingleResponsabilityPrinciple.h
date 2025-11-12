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
    EmployeeData(int hoursWorked, int hourlyRate)
        : m_HoursWorked(hoursWorked), m_HourlyRate(hourlyRate) {
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
    int CalPay(const EmployeeData& data)
    {
        // 단순히 시급 × 근무시간 계산
        return data.GetHoursWorked() * data.GetHourlyRate();
    }
};

class HourReporter
{
public:
    void ReportHours(const EmployeeData& data)
    {
        cout << "Worked Hours: " << data.GetHoursWorked() << endl;
    }
};

class EmployeeFacade
{
public:
    EmployeeFacade()
        : m_PayCalculator(make_unique<PayCalculator>()),
        m_HourReporter(make_unique<HourReporter>())
    {
    }

    void ProcessEmployee(const EmployeeData& data)
    {
        // 복잡한 내부 처리를 파사드가 대신 처리
        m_HourReporter->ReportHours(data);
        int pay = m_PayCalculator->CalPay(data);
        cout << "Calculated Pay: $" << pay << endl;
    }

private:
    unique_ptr<PayCalculator> m_PayCalculator;
    unique_ptr<HourReporter> m_HourReporter;
};

int main()
{
    EmployeeData emp(40, 25); // 40시간 근무, 시급 25달러
    EmployeeFacade facade;
    facade.ProcessEmployee(emp);
}