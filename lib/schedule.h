#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "com.pb.h"
#include "com.grpc.pb.h"
#include "med_event.h"
#include "../client/client.h"
#include <vector>
#include <memory>


class schedule {
    std::vector<std::shared_ptr<med_event>> events;
    std::vector<patient_message> patients;
    size_t current_patient_index;
    size_t current_event;
    size_t schedule_id;
    std::shared_ptr<client> client_;
    account_message doctor;
    void init();
    public:
    std::vector<std::shared_ptr<med_event>> GetEvents() { return events;}
    std::vector<patient_message> GetPatients() { return patients;}
    patient_message GetCurrentPatient();
    std::shared_ptr<med_event> GetCurrentEvent();
    void Next();
    std::vector<std::shared_ptr<med_event>> GetCurrentPatientHistory();
    void NewReferal(const std::shared_ptr<med_event>& new_referal);
    void NewPrescribtion(const std::shared_ptr<prescribtion>& new_prescribtion);
    void SetDoctor(const account_message& d) { doctor =d;}
    schedule(const std::shared_ptr<client>& c, size_t id);
    ~schedule();
};



#endif //SCHEDULE_H
