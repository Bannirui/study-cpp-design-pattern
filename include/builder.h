//
// Created by dingrui on 1/14/26.
//

#pragma once

#include <string>
#include <vector>
#include <sstream>

class ExportHeaderModel {
public:
    ExportHeaderModel(std::string depId, std::string exportDate);

    std::string get_dep_id() const {
        return this->m_depId;
    }

    std::string get_export_date() const {
        return this->m_exportDate;
    }

private:
    std::string m_depId;
    std::string m_exportDate;
};

class ExportDataModel {
public:
    ExportDataModel(std::string transId, double quantity);

    std::string get_trans_id() const {
        return this->m_transId;
    }

    double get_quantity() const {
        return this->m_quantity;
    }

private:
    std::string m_transId;
    double m_quantity;
};

class ExportFooterModel {
public:
    explicit ExportFooterModel(std::string user);

    std::string get_user() const {
        return this->m_user;
    }

private:
    std::string m_user;
};

class ExportToTxtHelper {
public:
    void doExport(ExportHeaderModel &header, std::vector<ExportDataModel *> &dataColl, ExportFooterModel &footer);
};

class ExportToXmlHelper {
public:
    void doExport(ExportHeaderModel &header, std::vector<ExportDataModel *> &dataColl, ExportFooterModel &footer);
};

template<class T>
std::string ConvertToStr(const T &v) {
    std::stringstream ss;
    ss << v;
    return ss.str();
}
