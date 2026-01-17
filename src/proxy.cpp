//
// Created by dingrui on 1/17/26.
//

#include "proxy.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

std::map<int, std::vector<std::string> > Cache;

void RealBugModel::GetBug() {
    std::ifstream ifs("asset/bug_logs.txt");
    if (!ifs) {
        std::cerr << "Cannot open bug_logs.txt" << std::endl;
        exit(1);
    }
    std::string line;
    int i = 0;
    while (std::getline(ifs, line)) {
        Cache[i++] = this->parseLine(line);
    }
    ifs.close();
}

std::vector<std::string> RealBugModel::parseLine(std::string line) {
    std::vector<std::string> result;
    std::istringstream ss(line);
    while (!ss.eof()) {
        std::string word;
        std::getline(ss, word, '|');
        result.push_back(word);
    }
    return result;
}

void ProxyModel::GetBug() {
    if (this->m_reload) {
        std::cout << "FROM CACHE" << std::endl;
        this->show();
    } else {
        std::cout << "FROM REAL" << std::endl;
        (new RealBugModel())->GetBug();
        this->m_reload = true;
        this->show();
    }
}

void ProxyModel::show() {
    for (int i = 0, n = Cache.size(); i < n; ++i) {
        std::cout << "ROW=" << i << "\t";
        for (auto &it: Cache[i]) {
            std::cout << it << "\t";
        }
        std::cout << std::endl;
    }
}
