//
// Created by dingrui on 1/14/26.
//

#pragma once

// interface
class ExportApi {
public:
    virtual bool exportData() =0;

protected:
    ExportApi() = default;
};

class ExportTxt : public ExportApi {
public:
    bool exportData() override;
};

class ExportDB : public ExportApi {
public:
    bool exportData() override;
};

class ExportOperate {
public:
    bool exportData();

protected:
    ExportOperate() = default;

    virtual ExportApi *factoryMethod() =0;
};

class ExportTxtOperate : public ExportOperate {
protected:
    ExportApi *factoryMethod() override;
};

class ExportDBOperate : public ExportOperate {
protected:
    ExportApi *factoryMethod() override;
};
