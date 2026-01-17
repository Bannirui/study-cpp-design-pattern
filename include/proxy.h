//
// Created by dingrui on 1/17/26.
//

#pragma once

#include <vector>
#include <string>

// interface
class BugMgrApi {
public:
    virtual void GetBug() =0;

protected:
    BugMgrApi() = default;
};

class RealBugModel : public BugMgrApi {
public:
    void GetBug() override;

private:
    std::vector<std::string> parseLine(std::string line);
};

class ProxyModel : public BugMgrApi {
public:
    ProxyModel() = default;

    void GetBug() override;

private:
    void show();

private:
    bool m_reload{false};
};
