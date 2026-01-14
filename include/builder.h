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

template<class T>
std::string ConvertToStr(const T &v) {
    std::stringstream ss;
    ss << v;
    return ss.str();
}

// interface
class Builder {
public:
    virtual void buildHeader(ExportHeaderModel &header) =0;

    virtual void buildBody(std::vector<ExportDataModel *> &datas) =0;

    virtual void buildFooter(ExportFooterModel &footer) =0;

    std::string get_ret() const { return this->m_ret; };

protected:
    Builder();

    std::string m_ret;
};

class TxtBuilder : public Builder {
public:
    TxtBuilder() = default;

    void buildHeader(ExportHeaderModel &header) override;

    void buildBody(std::vector<ExportDataModel *> &datas) override;

    void buildFooter(ExportFooterModel &footer) override;
};

class XmlBuilder : public Builder {
public:
    XmlBuilder() = default;

    void buildHeader(ExportHeaderModel &header) override;

    void buildBody(std::vector<ExportDataModel *> &datas) override;

    void buildFooter(ExportFooterModel &footer) override;
};

class Director {
public:
    Director(Builder &builder);

    void construct(ExportHeaderModel &header, std::vector<ExportDataModel *> &datas, ExportFooterModel &footer);

private:
    Builder &m_builder;
};
