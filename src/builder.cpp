//
// Created by dingrui on 1/14/26.
//

#include "builder.h"

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

void ExportToTxtHelper::doExport(ExportHeaderModel &header, std::vector<ExportDataModel *> &dataColl,
                                 ExportFooterModel &footer) {
    std::string str = "";
    // header
    str += header.get_dep_id() + "," + header.get_export_date() + "\n";
    // data
    for (auto &x: dataColl) {
        str += x->get_trans_id() + ":" + ConvertToStr(x->get_quantity()) + "\n";
    }
    // footer
    str += footer.get_user() + "\n";
    std::cout << str;
}

void ExportToXmlHelper::doExport(ExportHeaderModel &header, std::vector<ExportDataModel *> &dataColl,
                                 ExportFooterModel &footer) {
    std::string str = "";
    // header
    str.append("<?xml version='1.0' encoding='utf-8'>\n");
    str.append("<Receipt>\n");
    str.append("    <Header>\n");
    str.append("        <DepId>");
    str.append(header.get_dep_id() + "</DepId>\n");
    str.append("        <ExportDate>" + header.get_export_date() + "</ExportDate>\n");
    str.append("    </Header>\n");
    // data
    str.append("    <Body>\n");
    for (auto &x: dataColl) {
        str.append("        <id>" + x->get_trans_id() + "</id>\n");
        str.append("        <quantity>" + ConvertToStr(x->get_quantity()) + "</quantity>\n");
    }
    str.append("    </Body>\n");
    // footer
    str.append("    <Footer>\n");
    str.append("        <ExportUser>" + footer.get_user() + "</ExportUser>\n");
    str.append("    </Footer>\n");
    std::cout << str;
}
