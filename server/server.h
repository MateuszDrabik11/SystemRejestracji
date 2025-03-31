#ifndef SERVER_H
#define SERVER_H

#include "../lib/sqlite3.h"
#include "../lib/com.pb.h"
#include "../lib/com.grpc.pb.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server_builder.h>
#include <thread>

#include <chrono>
#include <ctime>
#include <iomanip>

#include "app_control.h"
#include "../lib/med_event.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::Status;

inline std::string current_datetime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
namespace global {
    static std::string path_to_log;
}
class server : public ClientServerCommunication::Service
{
    sqlite3 *db;
    bool db_closed;
    Status SearchForAccount(ServerContext *context, const account_request *ar, account_message *ac) override;

    Status SearchForPatients(ServerContext *context, const patient_message *request, ServerWriter<patient_message> *writer) override;

    Status UpdatePatientData(ServerContext *context, const patient_message *update, Empty *skip) override;

    Status GetNextVisits(ServerContext *context, const patient_message *selected, ServerWriter<med_event_message> *writer) override;

    Status GetExam(ServerContext *context, const patient_message *selected, ServerWriter<exam_message> *exam_writer) override;

    Status GetProcedure(ServerContext *context, const patient_message *selected, ServerWriter<procedure_message> *proc_writer) override;

    Status GetPrescribtions(ServerContext *context, const patient_message *selected, ServerWriter<prescribtion_message> *pres_writer) override;

    Status GetAvailableVisits(ServerContext *context, const med_event_message *me, ServerWriter<schedule_message> *writer) override;

    Status GetAvailableExams(ServerContext *context, const exam_message *me, ServerWriter<schedule_message> *writer) override;

    Status GetAvailableProcs(ServerContext *context, const procedure_message *me, ServerWriter<schedule_message> *writer) override;

    Status ScheduleEvent(ServerContext *context, const schedule_request *sr, Empty *e);

    Status GetReferals(ServerContext *context, const patient_message *selected, ServerWriter<med_event_message> *writer) override;

    Status GetDoctors(ServerContext *context, const Empty *e, ServerWriter<account_message> *writer) override;

    Status GetSchedules(ServerContext *context, const account_message *acc, ServerWriter<schedule_message> *writer) override;

    Status AddAccount(ServerContext *context, const add_account_msg *acc, Empty *e) override;

    Status ResetPassword(ServerContext *context, const account_message *acc, Empty *e) override;

    Status DeleteAccount(ServerContext *context, const account_message *acc, Empty *e) override;

    Status AddSchedule(ServerContext *context, const schedule_message *s, Empty *e) override;

    Status DeleteSchedule(ServerContext *context, const schedule_message *s, Empty *e) override;

    Status GetAccounts(ServerContext *context, const Empty *e, ServerWriter<account_message> *writer) override;

    Status GetPatientsHistory(ServerContext *context, const account_message *acc, ServerWriter<med_event_message> *writer) override;

    Status GetPatientsEvent(ServerContext *context, const med_event_message *me, event_response *r) override;

    Status GetPatientsEvents(ServerContext *context, const account_message *acc, ServerWriter<med_event_message> *writer) override;

    Status GetPatientPrescribtion(ServerContext *context, const account_message *acc, ServerWriter<prescribtion_message> *writer) override;

    Status GetExamResults(ServerContext *context, const exam_message *e, result *res) override;

    Status GetDoctorSchedules(grpc::ServerContext *context, const account_message *request, grpc::ServerWriter<schedule_message> *writer) override;

    Status GetScheduledPatients(grpc::ServerContext *context, const schedule_message *request, grpc::ServerWriter<patient_message> *writer) override;

    Status GetScheduledEvents(grpc::ServerContext *context, const schedule_message *request, grpc::ServerWriter<med_event_message> *writer) override;

    Status NewReferal(grpc::ServerContext *context, const med_event_message *request, Empty *response) override;

    Status EventDone(grpc::ServerContext *context, const med_event_message *request, Empty *response) override;

    Status NewPrescribtion(grpc::ServerContext *context, const prescribtion_message *request, Empty *response) override;

    Status ScheduleDone(grpc::ServerContext *context, const schedule_message *request, Empty *response) override;

    Status AddResult(grpc::ServerContext* context, const result* res, Empty * e) override;

    std::ofstream log;
public:
    server();

    void RunServer();

    ~server();
};


#endif //SERVER_H
