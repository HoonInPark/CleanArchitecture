#pragma once

#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <string>
#include <memory>

// =====================
// === Interactor Layer ===
// =====================

// 1. Request / Response 모델
struct FinancialReportRequest
{
    string ReportType;
    int Year;
};

struct FinancialReportResponse
{
    string ReportContent;
};

// 2. 인터페이스 정의 (Use Case)
class IFinancialReportUseCase
{
public:
    virtual ~IFinancialReportUseCase() = default;
    virtual FinancialReportResponse Execute(const FinancialReportRequest& request) = 0;
};

// 3. 실제 유스케이스 구현
class FinancialReportInteractor : public IFinancialReportUseCase
{
public:
    FinancialReportResponse Execute(const FinancialReportRequest& request) override
    {
        // === 핵심 비즈니스 로직 ===
        FinancialReportResponse response;
        response.ReportContent = "Financial Report (" + request.ReportType +
            ", " + to_string(request.Year) + ")";
        return response;
    }
};

// =====================
// === Controller Layer ===
// =====================

class FinancialReportController
{
public:
    explicit FinancialReportController(shared_ptr<IFinancialReportUseCase> interactor)
        : m_Interactor(move(interactor))
    {
    }

    void OnHttpRequest(const string& reportType, int year)
    {
        // 1. 입력 데이터 → 유스케이스 입력 모델로 변환
        FinancialReportRequest request{ reportType, year };

        // 2. 유스케이스 호출
        FinancialReportResponse response = m_Interactor->Execute(request);

        // 3. 결과 출력 (Presenter가 있으면 여기서 넘김)
        cout << "[Controller] Result: " << response.ReportContent << endl;
    }

private:
    shared_ptr<IFinancialReportUseCase> m_Interactor;
};
