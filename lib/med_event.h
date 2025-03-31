#ifndef MED_EVENT_H
#define MED_EVENT_H

#include <string>
#include "exam_results.h"
#include "com.pb.h"
#include "com.grpc.pb.h"

#include <regex>

class med_event
{
    protected:
    size_t id;
    std::string describtion, when_prescribed, where_prescribed;
    public:
    void SetDescribtion(const std::string& text);
    void SetWhenPrescribed(const std::string& text);
    void SetWherePrescribed(const std::string& text);
    void SetId(const size_t i) { id = i;};
    size_t GetId() const { return id;};

    std::string GetDescribtion() const;

    std::string GetWhenPrescribed() const;

    std::string GetWherePrescribed() const;
    account_message who_prescribed;
    patient_message patient;
    med_event();
    med_event(const med_event& me);
    med_event(const med_event_message& mem);
    med_event& operator=(const med_event& me);
    med_event& operator=(const med_event_message& mem);
    virtual ~med_event() = default;
};

class examination : public med_event
{
    std::string when_performed, where_performed;
    exam_results results;
    public:
    void SetWhenPerformed(const std::string& text);
    void SetWherePerformed(const std::string& text);
    void SetExamResults(const exam_results& er);
    const std::string& GetWhenPerformed();
    const std::string& GetWherePerformed();
    const exam_results& GetExamResults();
    account_message who_performs;
    examination() : med_event() {};
    examination(const examination& ex) : med_event(ex)
    {
        when_performed = ex.when_performed;
        where_performed = ex.where_performed;
        results = ex.results;
        who_performs = ex.who_performs;
    };
    examination(const exam_message& em) : med_event(em.event())
    {
        when_performed = em.when();
        where_performed = em.room();
        who_performs = em.who_performs();
    }
    examination& operator=(const examination& ex);
    examination& operator=(const exam_message& em);
};

class prescribtion : public med_event
{
    std::string medicine, dose, exp_date;
    public:
    void SetMedicine(const std::string& text);
    void SetDose(const std::string& text);
    void SetExpDate(const std::string& text);
    const std::string& GetMedicine();
    const std::string& GetDose();
    const std::string& GetExpDate();
    prescribtion() : med_event() {};
    prescribtion(const prescribtion& pr) : med_event(pr)
    {
        medicine = pr.medicine;
        dose = pr.dose;
        exp_date = pr.exp_date;
    };
    prescribtion(const prescribtion_message& prm) : med_event(prm.event())
    {
        medicine = prm.medicine();
        dose = prm.dose();
        exp_date = prm.exp_date();
    }
    prescribtion& operator=(const prescribtion& pr);
    prescribtion& operator=(const prescribtion_message& prm);
};

class procedure : public med_event
{
    std::string when_performed, where_performed;
    public:
    account_message who_performs;
    void SetWhenPerformed(const std::string& text);
    void SetWherePerformed(const std::string& text);
    const std::string& GetWhenPerformed();
    const std::string& GetWherePerformed();
    procedure() : med_event() {};
    procedure(const procedure& proc) : med_event(proc)
    {
        when_performed = proc.when_performed;
        where_performed = proc.where_performed;
        who_performs = proc.who_performs;
    };
    procedure(const procedure_message& prcm) : med_event(prcm.event())
    {
        when_performed = prcm.when();
        where_performed = prcm.room();
        who_performs = prcm.who_performs();
    };
    procedure& operator=(const procedure& proc);
    procedure& operator=(const procedure_message& prcm);
};

#endif
