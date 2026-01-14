//
// Created by dingrui on 1/14/26.
//

#include "builder.h"

#include <functional>
#include <iostream>
#include <utility>

ExportHeaderModel::ExportHeaderModel(std::string depId, std::string exportDate)
    : m_depId(std::move(depId)), m_exportDate(std::move(exportDate)) {
}

ExportDataModel::ExportDataModel(std::string transId, double quantity)
    : m_transId(std::move(transId)), m_quantity(quantity) {
}

ExportFooterModel::ExportFooterModel(std::string user)
    : m_user(std::move(user)) {
}

Builder::Builder() {
    this->m_ret = "";
}

void TxtBuilder::buildHeader(ExportHeaderModel &header) {
    this->m_ret.append(header.get_dep_id() + "," + header.get_export_date() + "\n");
}

void TxtBuilder::buildBody(std::vector<ExportDataModel *> &datas) {
    for (auto &x: datas) {
        this->m_ret.append(x->get_trans_id() + ":" + ConvertToStr(x->get_quantity()) + "\n");
    }
}

void TxtBuilder::buildFooter(ExportFooterModel &footer) {
    this->m_ret.append(footer.get_user() + "\n");
}

void XmlBuilder::buildHeader(ExportHeaderModel &header) {
    m_ret.append("<?xml version='1.0' encoding='utf-8'>\n");
    m_ret.append("<Receipt>\n");
    m_ret.append("    <Header>\n");
    m_ret.append("        <DepId>");
    m_ret.append(header.get_dep_id() + "</DepId>\n");
    m_ret.append("        <ExportDate>" + header.get_export_date() + "</ExportDate>\n");
    m_ret.append("    </Header>\n");
}

void XmlBuilder::buildBody(std::vector<ExportDataModel *> &datas) {
    m_ret.append("    <Body>\n");
    for (auto &x: datas) {
        m_ret.append("        <id>" + x->get_trans_id() + "</id>\n");
        m_ret.append("        <quantity>" + ConvertToStr(x->get_quantity()) + "</quantity>\n");
    }
    m_ret.append("    </Body>\n");
}

void XmlBuilder::buildFooter(ExportFooterModel &footer) {
    m_ret.append("    <Footer>\n");
    m_ret.append("        <ExportUser>" + footer.get_user() + "</ExportUser>\n");
    m_ret.append("    </Footer>\n");
}

Director::Director(Builder &builder) : m_builder(builder) {
}

void Director::construct(ExportHeaderModel &header, std::vector<ExportDataModel *> &datas,
                         ExportFooterModel &footer) {
    m_builder.buildHeader(header);
    m_builder.buildBody(datas);
    m_builder.buildFooter(footer);
}