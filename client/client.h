#ifndef CLIENT_H
#define CLIENT_H

#include <memory>
#include <string>
#include <QDebug>

#include <grpcpp/alarm.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "../lib/com.pb.h"
#include "../lib/com.grpc.pb.h"

#include "../lib/med_event.h"
#include "../lib/exam_results.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

class client
{
    std::unique_ptr<ClientServerCommunication::Stub> stub_;
public:
    client(std::shared_ptr<Channel> channel)
    {
        stub_ = ClientServerCommunication::NewStub(channel);
    }
    account_message SearchForAccount(const account_request& aq, Status& status)
    {
        ClientContext context;
        account_message ret;
        status = stub_->SearchForAccount(&context,aq,&ret);
        if(status.ok())
        {
            qDebug()<<"correct user";
            qDebug()<<ret.type().c_str();
            qDebug()<<ret.name().c_str();
            qDebug()<<ret.familyname().c_str();
        }
        return ret;
    }
    void SearchForPatients(const patient_message& request,std::vector<patient_message>& patient_messages)
    {
        ClientContext context;
        patient_message temp;
        std::unique_ptr<ClientReader<patient_message>> reader(stub_->SearchForPatients(&context,request));
        patient_messages.clear();
        while(reader->Read(&temp))
        {
            patient_messages.push_back(temp);
        }
        qDebug()<<"patient_messages received";
    }
    void UpdatePatientData(const patient_message& update)
    {
        ClientContext context;
        Empty skip;
        Status status = stub_->UpdatePatientData(&context,update,&skip);
        if(status.ok())
        {
            qDebug()<<"patient_message update correct";
        }
    }
    void GetNextVisits(const patient_message& pat, std::vector<std::unique_ptr<med_event>>& med_events)
    {
        ClientContext context;
        med_event_message temp;
        std::unique_ptr<ClientReader<med_event_message>> reader(stub_->GetNextVisits(&context,pat));
        med_events.clear();
        while(reader->Read(&temp))
        {
            med_events.push_back(std::make_unique<med_event>(temp));
        }
        qDebug()<<"next visits received";
        qDebug()<<med_events.size();
    }
    void GetExam(const patient_message& pat, std::vector<std::unique_ptr<med_event>>& exams)
    {
        ClientContext context;
        exam_message temp;
        std::unique_ptr<ClientReader<exam_message>> reader(stub_->GetExam(&context,pat));
        while(reader->Read(&temp))
        {
            exams.push_back(std::make_unique<examination>(temp));
        }
        qDebug()<<"exams received";
        qDebug()<<exams.size();
    }
    void GetPres(const patient_message& pat, std::vector<std::unique_ptr<med_event>>& pres)
    {
        ClientContext context;
        prescribtion_message temp;
        std::unique_ptr<ClientReader<prescribtion_message>> reader(stub_->GetPrescribtions(&context,pat));
        while(reader->Read(&temp))
        {
            pres.push_back(std::make_unique<prescribtion>(temp));
        }
        qDebug()<<"pres received";
        qDebug()<<pres.size();
    }
    void GetProc(const patient_message& pat, std::vector<std::unique_ptr<med_event>>& proc)
    {
        ClientContext context;
        procedure_message temp;
        std::unique_ptr<ClientReader<procedure_message>> reader(stub_->GetProcedure(&context,pat));
        while(reader->Read(&temp))
        {
            proc.push_back(std::make_unique<procedure>(temp));
        }
        qDebug()<<"proc received";
        qDebug()<<proc.size();
    }
    void GetAvailableVisits(const std::string& time,const std::string& type, std::vector<schedule_message>& schedules)
    {
        if(type == "wizyta")
        {
            ClientContext context;
            schedule_message temp;
            med_event_message me;
            me.set_time(time);
            me.set_describtion(type);
            std::unique_ptr<ClientReader<schedule_message>> reader(stub_->GetAvailableVisits(&context,me));
            while(reader->Read(&temp))
            {
                schedules.push_back(temp);
            }
            qDebug()<<"schedules_visits received";
            qDebug()<<schedules.size();
        }
    }
    void GetAvailableExams(const std::string& time,const std::string& type, std::vector<schedule_message>& schedules)
    {
        if(type != "wizyta" && type != "zabieg")
        {
            ClientContext context;
            schedule_message temp;
            exam_message me;
            me.set_when(time);
            me.mutable_event()->set_describtion(type);
            std::unique_ptr<ClientReader<schedule_message>> reader(stub_->GetAvailableExams(&context,me));
            while(reader->Read(&temp))
            {
                schedules.push_back(temp);
            }
            qDebug()<<"schedules_exams received";
            qDebug()<<schedules.size();
        }
    }
    void GetAvailableProcs(const std::string& time,const std::string& type, std::vector<schedule_message>& schedules)
    {
        if(type == "zabieg")
        {
            ClientContext context;
            schedule_message temp;
            procedure_message me;
            me.set_when(time);
            me.mutable_event()->set_describtion(type);
            std::unique_ptr<ClientReader<schedule_message>> reader(stub_->GetAvailableProcs(&context,me));
            while(reader->Read(&temp))
            {
                schedules.push_back(temp);
            }
            qDebug()<<"schedules_procs received";
            qDebug()<<schedules.size();
        }
    }
    Status ScheduleEvent(const schedule_request& sr)
    {
        ClientContext context;
        Empty e;
        qDebug()<<"new scheduled event request sent";
        return stub_->ScheduleEvent(&context,sr,&e);
    }
    void GetReferals(const patient_message& p, std::vector<med_event> &me)
    {
        me.clear();
        ClientContext context;
        med_event_message temp;
        std::unique_ptr<ClientReader<med_event_message>> reader(stub_->GetReferals(&context,p));
        while(reader->Read(&temp))
        {
            med_event t = temp;
            me.push_back(t);
        }
        qDebug()<<"referals received : "<<me.size();
    }
    void GetDoctors(std::vector<account_message>& doctors)
    {
        doctors.clear();
        ClientContext context;
        Empty e;
        account_message temp;
        std::unique_ptr<ClientReader<account_message>> reader(stub_->GetDoctors(&context,e));
        while(reader->Read(&temp))
        {
            doctors.push_back(temp);
        }
        qDebug()<<"doctors received : "<<doctors.size();
    }
    void GetSchedules(const account_message& doc, std::vector<schedule_message> &schedules)
    {
        ClientContext context;
        schedule_message temp;
        schedules.clear();
        std::unique_ptr<ClientReader<schedule_message>> reader(stub_->GetSchedules(&context,doc));
        while(reader->Read(&temp))
        {
            schedules.push_back(temp);
        }
        qDebug()<<"schedules received : "<<schedules.size();
    }
    bool AddAccount(const add_account_msg& acc)
    {
        ClientContext context;
        Empty e;
        Status status = stub_->AddAccount(&context,acc,&e);
        if(status.ok())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool ResetPassword(const account_message& acc)
    {
        ClientContext context;
        Empty e;
        Status status = stub_->ResetPassword(&context,acc,&e);
        if(status.ok())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool DeleteAccount(const account_message& acc)
    {
        ClientContext context;
        Empty e;
        Status status = stub_->DeleteAccount(&context,acc,&e);
        if(status.ok())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool DeleteSchedule(const schedule_message& s)
    {
        ClientContext context;
        Empty e;
        Status status = stub_->DeleteSchedule(&context,s,&e);
        if(status.ok())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool AddSchedule(const schedule_message& s)
    {
        ClientContext context;
        Empty e;
        Status status = stub_->AddSchedule(&context,s,&e);
        if(status.ok())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void GetAccounts(std::vector<account_message>& acc)
    {
        ClientContext context;
        account_message temp;
        Empty e;
        std::unique_ptr<ClientReader<account_message>> reader(stub_->GetAccounts(&context,e));
        acc.clear();
        while(reader->Read(&temp))
        {
            acc.push_back(temp);
        }
        qDebug()<<"accounts received : "<<acc.size();
    }
    void GetPatientsHistory(const account_message& a, std::vector<med_event>& history)
    {
        ClientContext context;
        med_event_message temp;
        history.clear();
        std::unique_ptr<ClientReader<med_event_message>> reader(stub_->GetPatientsHistory(&context,a));
        while(reader->Read(&temp))
        {
            history.push_back(temp);
        }
    }
    std::shared_ptr<med_event>GetPatientEvent(med_event& m)
    {
        ClientContext context;
        med_event_message me;
        me.set_id(m.GetId());
        me.set_describtion(m.GetDescribtion());
        me.set_room(m.GetWherePrescribed());
        me.set_time(m.GetWhenPrescribed());
        *me.mutable_name() = m.patient;
        *me.mutable_who_prescribed() = m.who_prescribed;
        event_response er;
        Status status = stub_->GetPatientsEvent(&context,me,&er);
        if(status.ok())
        {
            if(er.has_exam())
            {
                return std::make_shared<examination>(er.exam());
            }
            else if(er.has_proc())
            {
                return std::make_shared<procedure>(er.proc());
            }
            else if(er.has_pres())
            {
                return std::make_shared<prescribtion>(er.pres());
            }
            else
            {
                return std::make_shared<med_event>(m);
            }
        }
        else
        {
            return std::make_shared<med_event>();
        }
    }
    void GetPatientEvents(const account_message& a, std::vector<med_event>& events)
    {
        ClientContext context;
        med_event_message temp;
        events.clear();
        std::unique_ptr<ClientReader<med_event_message>> reader(stub_->GetPatientsEvents(&context,a));
        while(reader->Read(&temp))
        {
            events.push_back(temp);
        }
    }
    void GetPatientPrescribtion(const account_message& a, std::vector<prescribtion>& pres)
    {
        ClientContext context;
        prescribtion_message temp;
        pres.clear();
        std::unique_ptr<ClientReader<prescribtion_message>> reader(stub_->GetPatientPrescribtion(&context,a));
        while(reader->Read(&temp))
        {
            pres.push_back(temp);
        }
    }
    std::shared_ptr<exam_results> GetExamResults(examination ex)
    {
        ClientContext context;
        exam_message e;
        e.mutable_event()->set_id(ex.GetId());
        e.mutable_event()->set_describtion(ex.GetDescribtion());
        result r;
        Status status = stub_->GetExamResults(&context,e,&r);
        if(r.has_ekg())
        {
            ekg_results t = r.ekg();
            return std::make_shared<ekg_results>(t);
        }
        else if(r.has_mor())
        {
            morphology_results t = r.mor();
            return std::make_shared<morphology_results>(t);
        }
        else
        {
            rtg_results t = r.rest();
            return std::make_shared<rtg_results>(t);
        }
    }
    std::vector<schedule_message> GetDoctorSchedules(const account_message& a)
    {
        ClientContext context;
        schedule_message temp;
        std::vector<schedule_message> ret;
        std::unique_ptr<ClientReader<schedule_message>> reader(stub_->GetDoctorSchedules(&context,a));
        while(reader->Read(&temp))
        {
            ret.push_back(temp);
        }
        return ret;
    }
    std::vector<std::shared_ptr<med_event>> GetScheduledEvents(const schedule_message& s)
    {
        ClientContext context;
        med_event_message temp;
        std::vector<std::shared_ptr<med_event>> ret;
        std::unique_ptr<ClientReader<med_event_message>> reader(stub_->GetScheduledEvents(&context,s));
        while(reader->Read(&temp))
        {
            ret.push_back(std::make_shared<med_event>(temp));
        }
        return ret;
    }
    std::vector<patient_message> GetScheduledPatients(const schedule_message& s)
    {
        ClientContext context;
        patient_message temp;
        std::vector<patient_message> ret;
        std::unique_ptr<ClientReader<patient_message>> reader(stub_->GetScheduledPatients(&context,s));
        while(reader->Read(&temp))
        {
            ret.push_back(temp);
        }
        return ret;
    }
    void NewReferal(const med_event& m)
    {
        med_event_message me;
        me.set_id(m.GetId());
        me.set_room(m.GetWherePrescribed());
        me.set_time(m.GetWhenPrescribed());
        me.set_describtion(m.GetDescribtion());
        *me.mutable_name() = m.patient;
        *me.mutable_who_prescribed() = m.who_prescribed;
        ClientContext context;
        Empty e;
        Status status = stub_->NewReferal(&context,me,&e);
    }
    void NewPrescribtion(prescribtion& m)
    {
        prescribtion_message me;
        me.mutable_event()->set_id(m.GetId());
        me.mutable_event()->set_room(m.GetWherePrescribed());
        me.mutable_event()->set_time(m.GetWhenPrescribed());
        me.mutable_event()->set_describtion(m.GetDescribtion());
        *me.mutable_event()->mutable_name() = m.patient;
        *me.mutable_event()->mutable_who_prescribed() = m.who_prescribed;
        me.set_medicine(m.GetMedicine());
        me.set_dose(m.GetDose());
        me.set_exp_date(m.GetExpDate());
        ClientContext context;
        Empty e;
        Status status = stub_->NewPrescribtion(&context,me,&e);
    }
    void EventDone(const med_event& m)
    {
        med_event_message me;
        me.set_id(m.GetId());
        me.set_room(m.GetWherePrescribed());
        me.set_time(m.GetWhenPrescribed());
        *me.mutable_name() = m.patient;
        *me.mutable_who_prescribed() = m.who_prescribed;
        ClientContext context;
        Empty e;
        Status status = stub_->EventDone(&context,me,&e);
    }
    void ScheduleDone(size_t id)
    {
        schedule_message me;
        me.set_id(id);
        ClientContext context;
        Empty e;
        Status status = stub_->ScheduleDone(&context,me,&e);
    }
    void AddResult(const rtg_res_message& res)
    {
        ClientContext context;
        result se;
        *se.mutable_rest() = res;
        Empty e;
        Status status = stub_->AddResult(&context,se,&e);
    }
    void AddResult(const mor_res_message& res)
    {
        ClientContext context;
        result se;
        *se.mutable_mor() = res;
        Empty e;
        Status status = stub_->AddResult(&context,se,&e);
    }
    void AddResult(const ekg_res_message& res)
    {
        ClientContext context;
        result se;
        *se.mutable_ekg() = res;
        Empty e;
        Status status = stub_->AddResult(&context,se,&e);
    }
};

#endif // CLIENT_H
