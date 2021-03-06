
#include "UserIO.h"

void UserInputs_init(UserInputs *dev) {
    UserInputs_disable_interrupts(dev);
    UserInputs_clear_events(dev);
    InterruptController_enable(dev->intc_on,  dev->on_off_mask);
    InterruptController_enable(dev->intc_off, dev->on_off_mask);
}

void UserInputs_enable_interrupts(UserInputs *dev) {
    InterruptController_enable(dev->intc,     dev->on_evt_mask | dev->off_evt_mask);
}

void UserInputs_disable_interrupts(UserInputs *dev) {
    InterruptController_disable(dev->intc,     dev->on_evt_mask | dev->off_evt_mask);
}

bool UserInputs_has_events(UserInputs *dev) {
    return InterruptController_has_events(dev->intc, dev->on_evt_mask | dev->off_evt_mask);
}

void UserInputs_clear_events(UserInputs *dev) {
    InterruptController_clear_events(dev->intc_on,  dev->on_off_mask);
    InterruptController_clear_events(dev->intc_off, dev->on_off_mask);
    InterruptController_clear_events(dev->intc, dev->on_evt_mask | dev->off_evt_mask);
}

uint32_t UserInputs_get_on_events(UserInputs *dev) {
    return dev->intc_on->events;
}

uint32_t UserInputs_get_off_events(UserInputs *dev) {
    return dev->intc_off->events;
}

uint32_t UserInputs_get_status(UserInputs *dev) {
    return *dev->status;
}
