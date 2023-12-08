#include <stdint.h>
#include <stdbool.h>

//! Estructura anónima del gpio
typedef struct gpio_s * gpio_t;

/**
 * @brief Función constructor del objeto
 *
 * @param puerto
 * @param bit
 * @return gpio_t
 */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);
/**
 * @brief Función set dirección GPIO
 *
 * @param Objeto gpio
 * @param output
 * @return void
 */
void gpioSetOutput(gpio_t gpio, bool output);
/**
 * @brief Función set estado GPIO (alto o bajo)
 *
 * @param gpio
 * @param state
 * @return void
 */
void gpioSetState(gpio_t gpio, bool state);
/**
 * @brief Función para leer el estado GPIO (alto o bajo)
 *
 * @param gpio
 * @return bool Estado GPIO
 */
bool gpioGetState(gpio_t gpio);
