//
// Created by dingrui on 1/19/26.
//

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

class DownloadMgr;

class DownloadState {
public:
    virtual void Download(std::string user, std::string item, DownloadMgr *mgr) =0;

protected:
    DownloadState() = default;
};

class NormalState : public DownloadState {
public:
    void Download(std::string user, std::string item, DownloadMgr *mgr) override {
        std::cout << "normal" << std::endl;
    }
};

class RepeatState : public DownloadState {
public:
    void Download(std::string user, std::string item, DownloadMgr *mgr) override {
        std::cout << "repeat" << std::endl;
    }
};

class SpiteState : public DownloadState {
public:
    void Download(std::string user, std::string item, DownloadMgr *mgr) override {
        std::cout << "spite" << std::endl;
    }
};

class ForbidState : public DownloadState {
public:
    void Download(std::string user, std::string item, DownloadMgr *mgr) override {
        std::cout << "forbid" << std::endl;
    }
};

class DownloadMgr {
public:
    std::unordered_map<std::string, std::string> get_user_download_item_map() {
        return this->m_userMap;
    }

    void DownLoad(std::string user, std::string item) {
        int preDownloadCnt = 0;
        if (this->m_downloadCntMap.count(user) > 0) {
            preDownloadCnt = this->m_downloadCntMap[user];
        } else {
            this->m_downloadCntMap[user] = 0;
        }
        ++preDownloadCnt;
        this->m_downloadCntMap[user] = preDownloadCnt;
        if (preDownloadCnt == 1) {
            this->m_state = new NormalState;
        } else if (preDownloadCnt > 1 && preDownloadCnt < 3) {
            this->m_state = new RepeatState;
        } else if (preDownloadCnt >= 3 && preDownloadCnt < 5) {
            this->m_state = new SpiteState;
        } else {
            this->m_state = new ForbidState;
        }
        this->m_state->Download(user, item, this);
    }

private:
    DownloadState *m_state;
    std::unordered_map<std::string, std::string> m_userMap;
    std::unordered_map<std::string, int> m_downloadCntMap;
};
