#ifndef EXAM_RESULTS_H
#define EXAM_RESULTS_H

#include <string>
#include "com.pb.h"
#include "com.grpc.pb.h"

class exam_results
{
    protected:
    size_t id;
    public:
    void SetId(const size_t i)
    {
        id = i;
    }
    const size_t GetId()
    {
        return id;
    }
    exam_results()
    {
        id = 0;
    }
    exam_results(const exam_results& er)
    {
        id = er.id;
    }
    exam_results(const ekg_res_message& rm)
    {
        id = rm.result_id().result_id();
    }
    exam_results(const usg_res_message& rm)
    {
        id = rm.result_id().result_id();
    }
    exam_results(const mri_res_message& rm)
    {
        id = rm.result_id().result_id();
    }
    exam_results(const rtg_res_message& rm)
    {
        id = rm.result_id().result_id();
    }
    exam_results(const mor_res_message& rm)
    {
        id = rm.result_id().result_id();
    }
    exam_results& operator=(const exam_results& er)
    {
        id = er.id;
        return *this;
    }
    exam_results& operator=(const ekg_res_message& rm)
    {
        id = rm.result_id().result_id();
        return *this;
    }
    exam_results& operator=(const usg_res_message& rm)
    {
        id = rm.result_id().result_id();
        return *this;
    }
    exam_results& operator=(const mri_res_message& rm)
    {
        id = rm.result_id().result_id();
        return *this;
    }
    exam_results& operator=(const rtg_res_message& rm)
    {
        id = rm.result_id().result_id();
        return *this;
    }
    exam_results& operator=(const mor_res_message& rm)
    {
        id = rm.result_id().result_id();
        return *this;
    }
    std::string virtual get_str() const
    {
        return std::string(std::to_string(id));
    }
};

class morphology_results : public exam_results
{
    unsigned int RBC, Hb, WBC, PLT;
    public:
    void SetRBC(unsigned int i)
    {
        RBC = i;
    }
    void SetHB(unsigned int i)
    {
        Hb = i;
    }
    void SetWBC(unsigned int i)
    {
        WBC = i;
    }
    void SetPLT(unsigned int i)
    {
        PLT = i;
    }
    const int GetRBC()
    {
        return RBC;
    }
    const int GetHB()
    {
        return Hb;
    }
    const int GetWBC()
    {
        return WBC;
    }
    const int GetPLT()
    {
        return PLT;
    }
    morphology_results() : exam_results()
    {
        RBC = Hb = WBC = PLT = 0;
    }
    morphology_results(const morphology_results& res) : exam_results(res)
    {
        RBC = res.RBC;
        Hb = res.Hb;
        WBC = res.WBC;
        PLT = res.PLT;
    }
    morphology_results(const mor_res_message& res) : exam_results(res)
    {
        RBC = res.rbc();
        Hb = res.hb();
        WBC = res.wbc();
        PLT = res.plt();
    }
    morphology_results& operator=(const morphology_results& res)
    {
        (exam_results&)(*this) = (exam_results&)res;
        RBC = res.RBC;
        Hb = res.Hb;
        WBC = res.WBC;
        PLT = res.PLT;
        return *this;
    }
    morphology_results& operator=(const mor_res_message& res)
    {
        (exam_results&)(*this) = res;
        RBC = res.rbc();
        Hb = res.hb();
        WBC = res.wbc();
        PLT = res.plt();
        return *this;
    }
    std::string get_str() const
    {
        return std::string("RBC: " + std::to_string(RBC) + ", Hb: " + std::to_string(Hb) + "WBC: " + std::to_string(WBC) + "PLT: " + std::to_string(PLT));
    }
};
class rtg_results : public exam_results
{
    std::string results;
    public:
    void SetResults(const std::string& text)
    {
        results = text;
    }
    const std::string& GetResults()
    {
        return results;
    }
    rtg_results() : exam_results() {};
    rtg_results(const rtg_results& res) : exam_results(res) 
    {
        results = res.results;
    };
    rtg_results(const rtg_res_message& res) : exam_results(res) 
    {
        results = res.result();
    };
    rtg_results& operator=(const rtg_results& res)
    {
        (exam_results&)(*this) = (exam_results&)res;
        results = res.results;
        return *this;
    }
    rtg_results& operator=(const rtg_res_message& res)
    {
        (exam_results&)(*this) = res;
        results = res.result();
        return *this;
    }
    std::string get_str() const
    {
        return results;
    }
};

class usg_results : public exam_results
{
    std::string results;
    public:
    void SetResults(const std::string& text)
    {
        results = text;
    }
    const std::string& GetResults()
    {
        return results;
    }
    usg_results() : exam_results() {};
    usg_results(const usg_results& res) : exam_results(res) 
    {
        results = res.results;
    };
    usg_results(const usg_res_message& res) : exam_results(res) 
    {
        results = res.result();
    };
    usg_results& operator=(const usg_results& res)
    {
        (exam_results&)(*this) = (exam_results&)res;
        results = res.results;
        return *this;
    }
    usg_results& operator=(const usg_res_message& res)
    {
        (exam_results&)(*this) = res;
        results = res.result();
        return *this;
    }
    std::string get_str() const
    {
        return results;
    }
};
class mri_results : public exam_results
{
    std::string results;
    public:
    void SetResults(const std::string& text)
    {
        results = text;
    }
    const std::string& GetResults()
    {
        return results;
    }
    mri_results() : exam_results() {};
    mri_results(const mri_results& res) : exam_results(res) 
    {
        results = res.results;
    };
    mri_results(const mri_res_message& res) : exam_results(res) 
    {
        results = res.result();
    };
    mri_results& operator=(const mri_results& res)
    {
        (exam_results&)(*this) = (exam_results&)res;
        results = res.results;
        return *this;
    }
    mri_results& operator=(const mri_res_message& res)
    {
        (exam_results&)(*this) = res;
        results = res.result();
        return *this;
    }
    std::string get_str() const
    {
        return results;
    }
};
class ekg_results : public exam_results
{
    unsigned int rhytm, pr_delay, qrs;
    public:
    void SetRhytm(const int i)
    {
        rhytm = i;
    }
    void SetPRDelay(const int i)
    {
        pr_delay = i;
    }
    void SetQRS(const int i)
    {
        qrs = i;
    }
    const int GetRhytm()
    {
        return rhytm;
    }
    const int GetPRDelay()
    {
        return pr_delay;
    }
    const int GetQRS()
    {
        return qrs;
    }
    ekg_results() : exam_results() 
    {
        rhytm = qrs = pr_delay = 0;
    }
    ekg_results(const ekg_results& res) : exam_results(res)
    {
        rhytm = res.rhytm;
        qrs = res.qrs;
        pr_delay = res.pr_delay;
    }
    ekg_results(const ekg_res_message& res) : exam_results(res)
    {
        rhytm = res.rhytm();
        qrs = res.qrs();
        pr_delay = res.pr_delay();
    }
    ekg_results& operator=(const ekg_results& res)
    {
        (exam_results&)(*this) = (exam_results&)res;
        rhytm = res.rhytm;
        qrs = res.qrs;
        pr_delay = res.pr_delay;
        return *this;
    }
    ekg_results& operator=(const ekg_res_message& res)
    {
        (exam_results&)(*this) = res;
        rhytm = res.rhytm();
        qrs = res.qrs();
        pr_delay = res.pr_delay();
        return *this;
    }
    std::string get_str() const
    {
        return std::string("rytm: " + std::to_string(rhytm) + ", qrs: " + std::to_string(qrs) + "pr: " + std::to_string(pr_delay));
    }
};

#endif
