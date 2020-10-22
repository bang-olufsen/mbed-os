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


//! @brief   Defines the platform's MAC address
//! This function is called by mbedOS to retrieve the MAC that the interface should use.
//! @param   mac A 6-byte array defining the MAC address
extern "C" void mbed_mac_address(char* mac)
{
    // We don't have access to a random source or to a unique MAC address, but by putting the platforms and the role of the executable 
    // in the test setup we can choose MAC addresses that are unlikely to collide in the test setup.
    unsigned char macAddress[6] = { 0x00, 0x09, 0xa7, 0x08, 0x00, 0x00 };
    macAddress[4] = MBED_CONF_APP_ECHO_SERVER;
    #if defined(BOARD_EVAL)
    macAddress[5] = 1;
    #endif

    memcpy(mac, macAddress, sizeof(macAddress));
};