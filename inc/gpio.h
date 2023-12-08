#include <stdint.h>
#include <stdbool.h>

//! Estructura anónima del gpio
typedef struct gpio_s * gpio_t;

/**
 * @brief Función constructor del objeto
 *
 * @param puerto Puerto GPIO
 * @param bit Estado del GPIO
 * @return gpio_t
 */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);
/**
 * @brief Función set dirección GPIO
 *
 * @param gpio Objeto gpio
 * @param output Puerto GPIO
 * @return void
 */
void gpioSetOutput(gpio_t gpio, bool output);
/**
 * @brief Función set estado GPIO (alto o bajo)
 *
 * @param gpio Objeto gpio
 * @param state Estado alto o bajo GPIO
 * @return void
 */
void gpioSetState(gpio_t gpio, bool state);
/**
 * @brief Función para leer el estado GPIO (alto o bajo)
 *
 * @param gpio  Objeto gpio
 * @return bool Estado GPIO
 */
bool gpioGetState(gpio_t gpio);
