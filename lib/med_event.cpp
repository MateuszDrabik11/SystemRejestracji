#include "med_event.h"

void med_event::SetDescribtion(const std::string &text)
{
    describtion = text;
}
void med_event::SetWhenPrescribed(const std::string &text)
{
    std::regex reg("[0-9]{4}-([0-9]{2})-([0-9]{2})\\s([0-9]{2}):([0-9]{2}):([0-9]{2})");
    std::smatch match;
    if (std::regex_search(text, match, reg))
    {
        if (std::stoi(match[1]) > 0 && std::stoi(match[1]) <= 12 && std::stoi(match[2]) > 0 && std::stoi(match[2]) <= 31 &&
            std::stoi(match[3]) >= 0 && std::stoi(match[3]) < 24 && std::stoi(match[4]) >= 0 && std::stoi(match[4]) < 60)
        {
            when_prescribed = text;
        }
    }
}
void med_event::SetWherePrescribed(const std::string &text)
{
    where_prescribed = text;
}

std::string med_event::GetDescribtion() const {
    return describtion;
}

std::string med_event::GetWhenPrescribed() const {
    return when_prescribed;
}

std::string med_event::GetWherePrescribed() const {
    return where_prescribed;
}

void examination::SetWhenPerformed(const std::string &text)
{
    std::regex reg("[0-9]{4}-([0-9]{2})-([0-9]{2})\\s([0-9]{2}):([0-9]{2}):([0-9]{2})");
    std::smatch match;
    if (std::regex_search(text, match, reg))
    {
        if (std::stoi(match[1]) > 0 && std::stoi(match[1]) <= 12 && std::stoi(match[2]) > 0 && std::stoi(match[2]) <= 31 &&
            std::stoi(match[3]) >= 0 && std::stoi(match[3]) < 24 && std::stoi(match[4]) >= 0 && std::stoi(match[4]) < 60)
        {
            when_performed = text;
        }
    }
}
void examination::SetWherePerformed(const std::string &text)
{
    where_performed = text;
}
void examination::SetExamResults(const exam_results &er)
{
    results = er;
}
const std::string &examination::GetWhenPerformed()
{
    return when_performed;
}
const std::string &examination::GetWherePerformed()
{
    return where_performed;
}
const exam_results &examination::GetExamResults()
{
    return results;
}

void prescribtion::SetMedicine(const std::string &text)
{
    medicine = text;
}
void prescribtion::SetDose(const std::string &text)
{
    dose = text;
}
void prescribtion::SetExpDate(const std::string &text)
{
    exp_date = text;
}
const std::string &prescribtion::GetMedicine()
{
    return medicine;
}
const std::string &prescribtion::GetDose()
{
    return dose;
}
const std::string &prescribtion::GetExpDate()
{
    return exp_date;
}

void procedure::SetWhenPerformed(const std::string &text)
{
    std::regex reg("[0-9]{4}-([0-9]{2})-([0-9]{2})\\s([0-9]{2}):([0-9]{2}):([0-9]{2})");
    std::smatch match;
    if (std::regex_search(text, match, reg))
    {
        if (std::stoi(match[1]) > 0 && std::stoi(match[1]) <= 12 && std::stoi(match[2]) > 0 && std::stoi(match[2]) <= 31 &&
            std::stoi(match[3]) >= 0 && std::stoi(match[3]) < 24 && std::stoi(match[4]) >= 0 && std::stoi(match[4]) < 60)
        {
            when_performed = text;
        }
    }
}
void procedure::SetWherePerformed(const std::string &text)
{
    where_performed = text;
}
const std::string &procedure::GetWhenPerformed()
{
    return when_performed;
}
const std::string &procedure::GetWherePerformed()
{
    return where_performed;
}

med_event::med_event()
{
    id = 0;
}
med_event::med_event(const med_event &me)
{
    id = me.id;
    describtion = me.describtion;
    when_prescribed = me.when_prescribed;
    where_prescribed = me.where_prescribed;
    who_prescribed = me.who_prescribed;
    patient = me.patient;
}
med_event::med_event(const med_event_message &mem)
{
    id = mem.id();
    describtion = mem.describtion();
    when_prescribed = mem.time();
    where_prescribed = mem.room();
    who_prescribed = mem.who_prescribed();
    patient = mem.name();
}
med_event &med_event::operator=(const med_event &me)
{
    id = me.id;
    describtion = me.describtion;
    when_prescribed = me.when_prescribed;
    where_prescribed = me.where_prescribed;
    who_prescribed = me.who_prescribed;
    patient = me.patient;
    return *this;
}
med_event &med_event::operator=(const med_event_message &mem)
{
    id = mem.id();
    describtion = mem.describtion();
    when_prescribed = mem.time();
    where_prescribed = mem.room();
    who_prescribed = mem.who_prescribed();
    patient = mem.name();
    return *this;
}

examination &examination::operator=(const examination &ex)
{
    (med_event &)(*this) = (med_event &)ex;
    when_performed = ex.when_performed;
    where_performed = ex.where_performed;
    results = ex.results;
    who_performs = ex.who_performs;
    return *this;
}
examination &examination::operator=(const exam_message &em)
{
    (med_event &)(*this) = em.event();
    when_performed = em.when();
    where_performed = em.room();
    who_performs = em.who_performs();
    return *this;
}
prescribtion& prescribtion::operator=(const prescribtion &pr)
{
    (med_event &)(*this) = (med_event &)pr;
    medicine = pr.medicine;
    dose = pr.dose;
    exp_date = pr.exp_date;
    return *this;
}
prescribtion& prescribtion::operator=(const prescribtion_message &prm)
{
    (med_event &)(*this) = prm.event();
    medicine = prm.medicine();
    dose = prm.dose();
    exp_date = prm.exp_date();
    return *this;
}
procedure& procedure::operator=(const procedure &proc)
{
    (med_event &)(*this) = (med_event &)proc;
    when_performed = proc.when_performed;
    where_performed = proc.where_performed;
    who_performs = proc.who_performs;
    return *this;
}
procedure& procedure::operator=(const procedure_message &prcm)
{
    (med_event &)(*this) = prcm.event();
    when_performed = prcm.when();
    where_performed = prcm.room();
    who_performs = prcm.who_performs();
    return *this;
}
