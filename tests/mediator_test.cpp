//
// Created by dingrui on 1/19/26.
//

#include "mediator.h"

#include <vector>
#include <string>

int main() {
    MotherBoard *motherboard = new MotherBoard();
    CPU *cpu = new CPU(motherboard);
    VideoCard *video = new VideoCard(motherboard);
    SoundCard *sound = new SoundCard(motherboard);

    motherboard->set_cpu(cpu);
    motherboard->set_video_card(video);
    motherboard->set_sound_card(sound);

    std::vector<std::string> datas{"abc", "def"};
    cpu->CPUData(datas);

    delete motherboard;
    delete video;
    delete sound;
    return 0;
}
