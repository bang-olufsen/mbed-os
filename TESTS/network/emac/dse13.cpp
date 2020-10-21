// Copyright 2020 - Bang & Olufsen a/s

#include "dse13.h"
#include "PowerControlBeoLab.h"

void init_dse13() {
    // The FFX needs to be turned on before the network interface is enabled
    // because the FFX generates a clock needed by the LPC ethernet
    std::shared_ptr<EventQueue> eventQueue = make_shared<EventQueue>();
    PowerControlBeoLab powerControl(eventQueue, nullptr);
    powerControl.setPowerState(PowerControl::PowerState::On);

    osDelay(5000); // wait for the Firefox to enable the switch
}