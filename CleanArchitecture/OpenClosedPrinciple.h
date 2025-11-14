#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;


// =====================
// === Interactor Layer ===
// =====================

// 1. Request / Response 모델
struct FinReportReq
{
    string ReportType;
    int Year;
};

struct FinReportResponse
{
    string ReportContent;
};

// 2. 인터페이스 정의 (Use Case)
class IFinReportRequester
{
public:
    virtual FinReportResponse Execute(const FinReportReq& request) = 0;
};

// 3. 실제 유스케이스 구현
// 책에서 Financial Report Requester와 Financial Report Generator에 해당하는 부분
class FinReportGenerator : public IFinReportRequester 
{
public:
    virtual FinReportResponse Execute(const FinReportReq& request) override
    {
        // === 핵심 비즈니스 로직 ===
        FinReportResponse response;
        response.ReportContent = "Financial Report (" + request.ReportType +
            ", " + to_string(request.Year) + ")";
        return response;
    }
};

// =====================
// === Controller Layer ===
// =====================

class IFinReportPresenter
{
public:
    virtual void Present(const FinReportResponse& _InResponse) = 0;
};

class FinReportCtrl
{
public:
    explicit FinReportCtrl(
        shared_ptr<IFinReportRequester> interactor,
        shared_ptr<IFinReportPresenter> presenter) 
        : m_Interactor(move(interactor))
        , m_Presenter(move(presenter))
    {
    }

    void OnHttpReq(const string& reportType, int year)
    {
        // 1. 입력 데이터 → 유스케이스 입력 모델로 변환
        FinReportReq request{ reportType, year };

        // 2. 유스케이스 호출
        FinReportResponse response = m_Interactor->Execute(request);

        // 3. 결과 출력 (Presenter가 있으면 여기서 넘김)
        cout << "[Controller] Result: " << response.ReportContent << endl;
    }

private:
    shared_ptr<IFinReportRequester> m_Interactor;
    shared_ptr<IFinReportPresenter> m_Presenter;
};
