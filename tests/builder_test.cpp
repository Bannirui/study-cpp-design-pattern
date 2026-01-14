//
// Created by dingrui on 1/14/26.
//

#include "builder.h"

#include <iostream>

int main() {
    ExportHeaderModel header("NanJing", "2026-01-01");
    ExportDataModel *data1 = new ExportDataModel("1", 1000.00f);
    ExportDataModel *data2 = new ExportDataModel("2", 1000.01f);
    ExportFooterModel footer("dingrui");
    std::vector<ExportDataModel *> data_vec;
    data_vec.push_back(data1);
    data_vec.push_back(data2);
    ExportToTxtHelper txt;
    txt.doExport(header, data_vec, footer);

    std::cout<<std::endl;

    ExportToXmlHelper xml;
    xml.doExport(header, data_vec, footer);
    return 0;
}
