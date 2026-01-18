//
// Created by dingrui on 1/19/26.
//

#pragma once

#include <iostream>
#include <string>
#include <vector>

class Colleague;

class Mediator {
public:
    virtual ~Mediator() = default;

    virtual void Changed(Colleague *colleague) =0;

protected:
    Mediator() = default;
};

class Colleague {
public:
    Colleague() = default;

    Colleague(Mediator *mediator) : m_mediator(mediator) {
    }

    Mediator *get_mediator() const {
        return this->m_mediator;
    }

private:
    Mediator *m_mediator{nullptr};
};

class SoundCard : public Colleague {
public:
    SoundCard(Mediator *mediator) : Colleague(mediator) {
    }

    void SoundData(std::string data) {
        std::cout << "SoundData:" << data << std::endl;
    }
};

class VideoCard : public Colleague {
public:
    VideoCard(Mediator *mediator) : Colleague(mediator) {
    }

    void VideoData(std::string data) {
        std::cout << "VideoData:" << data << std::endl;
    }
};

class CPU : public Colleague {
public:
    CPU(Mediator *mediator) : Colleague(mediator) {
    }

    void CPUData(std::vector<std::string> datas) {
        this->m_videData = datas[0];
        this->m_soundData = datas[1];
        this->get_mediator()->Changed(this);
    }

    std::string get_videoData() {
        return this->m_videData;
    }

    std::string get_soundData() {
        return this->m_soundData;
    }

private:
    std::string m_videData;
    std::string m_soundData;
};

class MotherBoard : public Mediator {
public:
    MotherBoard() = default;

    ~MotherBoard() = default;

    void set_cpu(CPU *cpu) {
        this->m_cpu = cpu;
    }

    void set_video_card(VideoCard *videoCard) {
        this->m_video = videoCard;
    }

    void set_sound_card(SoundCard *soundCard) {
        this->m_sound = soundCard;
    }

    void Changed(Colleague *colleague) override {
        if (colleague == this->m_cpu) {
            this->openCPU((CPU *) colleague);
        }
    }

private:
    void openCPU(CPU *cpu) {
        std::string videoData = cpu->get_videoData();
        std::string soundData = cpu->get_soundData();
        this->m_video->VideoData(videoData);
        this->m_sound->SoundData(soundData);
    }

private:
    CPU *m_cpu;
    VideoCard *m_video;
    SoundCard *m_sound;
};
