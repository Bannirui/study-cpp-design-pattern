//
// Created by dingrui on 1/18/26.
//

#include "observer.h"

int main() {
    WeatherData data;
    PCDisplay pc(&data);
    MobileDisplay mobile(&data);

    data.Set_Data("1", "1.1");
    data.RemoveObserver(&pc);
    data.Set_Data("2", "2.2");
    data.RemoveObserver(&mobile);
    data.Set_Data("3", "3.2");
    return 0;
}
