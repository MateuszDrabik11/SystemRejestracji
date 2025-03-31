#include "schedule.h"

void schedule::init() {
    schedule_message t;
    t.set_id(schedule_id);
    events = client_->GetScheduledEvents(t);
    patients = client_->GetScheduledPatients(t);
}

patient_message schedule::GetCurrentPatient() {
    if(!patients.empty() && current_patient_index < patients.size()) {
        return patients[current_patient_index];
    }
    else {
        return {};
    }
}

std::shared_ptr<med_event> schedule::GetCurrentEvent() {
    if(!events.empty() && current_event < events.size()) {
        return events[current_event];
    }
    else {
        return std::make_shared<med_event>();
    }
}

void schedule::Next() {
    if(current_patient_index < patients.size()) {
        client_->EventDone(*events[current_event]);
        ++current_patient_index;
        ++current_event;
    }
}

std::vector<std::shared_ptr<med_event>> schedule::GetCurrentPatientHistory() {
    if(current_patient_index < patients.size()) {
        std::vector<med_event> temp;
        std::vector<std::shared_ptr<med_event>> ret;
        client_->GetPatientEvents(patients[current_patient_index].username(),temp);
        std::ranges::for_each(temp,[&ret](const auto& i){ret.push_back(std::make_shared<med_event>(i));});
        client_->GetPatientsHistory(patients[current_patient_index].username(),temp);
        std::ranges::for_each(temp,[&ret](const auto& i){ret.push_back(std::make_shared<med_event>(i));});
        return ret;
    }
    else {
        return {};
    }
}

void schedule::NewReferal(const std::shared_ptr<med_event> &new_referal) {
    client_->NewReferal(*new_referal);
}

void schedule::NewPrescribtion(const std::shared_ptr<prescribtion> &new_prescribtion) {
    client_->NewPrescribtion(*new_prescribtion);
}

schedule::schedule(const std::shared_ptr<client> &c, size_t id){
    client_ = c;
    current_event = 0;
    current_patient_index = 0;
    schedule_id = id;
    init();
}

schedule::~schedule(){
    client_->ScheduleDone(schedule_id);
}
