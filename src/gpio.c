#include "gpio.h"
#include <stddef.h>

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

//! Definición de la struct anónima 
struct gpio_s {
    uint8_t port; //!< Puerto GPIO 
    uint8_t bit;  //!< Pin GPIO 
    bool output;  //!< Dirección GPIO 
    bool used;    //!< Estado de uso de la instancia (en uso o sin uso) 
};

/**
 * @brief Función para asignar memoria a una instancia
 *
 * @return gpio_t
 */
static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index].used;
            result->used = true;
            break;
        }
    }
    return result;
}

gpio_t gpioCreate(uint8_t puerto, uint8_t bit) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpio_t self = allocateInstance();
#endif
    if (self) {
        self->port = puerto;
        self->bit = bit;
        self->output = false;
    }
    return self;
}

void gpioSetOutput(gpio_t self, bool output) {
    self->output = output;
    HAL_GPIO_SET_OUTPUT(self->port, self->bit);
}

void gpioSetState(gpio_t self, bool state) {
    if (self->output) {
        HAL_GPIO_SET_STATE(self->port, self->bit);
    }
}

bool gpioGetState(gpio_t self) {
    return HAL_GPIO_GET_STATE(self->port, self->bit);
}
