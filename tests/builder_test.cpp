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

    {
        TxtBuilder txtBuilder;
        Director director(txtBuilder);
        director.construct(header, data_vec, footer);
        std::cout << txtBuilder.get_ret() << std::endl;
    }
    {
        XmlBuilder xmlBuilder;
        Director director(xmlBuilder);
        director.construct(header, data_vec, footer);
        std::cout << xmlBuilder.get_ret() << std::endl;
    }

    return 0;
}
