#include "gpio.h"
/*! \brief Select GPIO function
 *  \ingroup hardware_gpio
 *
 * \param gpio GPIO number
 * \param fn Which GPIO function select to use from list \ref gpio_function
 */
void gpio_set_function(uint gpio, enum gpio_function fn)
{

}

/*! \brief Determine current GPIO function
 *  \ingroup hardware_gpio
 *
 * \param gpio GPIO number
 * \return Which GPIO function is currently selected from list \ref gpio_function
 */
enum gpio_function gpio_get_function(uint gpio)
{
    return 0;
}

/*! \brief Select up and down pulls on specific GPIO
 *  \ingroup hardware_gpio
 *
 * \param gpio GPIO number
 * \param up If true set a pull up on the GPIO
 * \param down If true set a pull down on the GPIO
 *
 * \note On the RP2040, setting both pulls enables a "bus keep" function,
 * i.e. a weak pull to whatever is current high/low state of GPIO.
 */
void gpio_set_pulls(uint gpio, bool up, bool down)
{

}

/*! \brief Set GPIO IRQ override
 *  \ingroup hardware_gpio
 *
 * Optionally invert a GPIO IRQ signal, or drive it high or low
 *
 * \param gpio GPIO number
 * \param value See \ref gpio_override
 */
void gpio_set_irqover(uint gpio, uint value)
{

}

/*! \brief Set GPIO output override
 *  \ingroup hardware_gpio
 *
 * \param gpio GPIO number
 * \param value See \ref gpio_override
 */
void gpio_set_outover(uint gpio, uint value)
{

}

/*! \brief Select GPIO input override
 *  \ingroup hardware_gpio
 *
 * \param gpio GPIO number
 * \param value See \ref gpio_override
 */
void gpio_set_inover(uint gpio, uint value)
{

}

/*! \brief Select GPIO output enable override
 *  \ingroup hardware_gpio
 *
 * \param gpio GPIO number
 * \param value See \ref gpio_override
 */
void gpio_set_oeover(uint gpio, uint value)
{

}

/*! \brief Enable GPIO input
 *  \ingroup hardware_gpio
 *
 * \param gpio GPIO number
 * \param enabled true to enable input on specified GPIO
 */
void gpio_set_input_enabled(uint gpio, bool enabled)
{

}

/*! \brief Enable/disable GPIO input hysteresis (Schmitt trigger)
 *  \ingroup hardware_gpio
 *
 * Enable or disable the Schmitt trigger hysteresis on a given GPIO. This is
 * enabled on all GPIOs by default. Disabling input hysteresis can lead to
 * inconsistent readings when the input signal has very long rise or fall
 * times, but slightly reduces the GPIO's input delay.
 *
 * \sa gpio_is_input_hysteresis_enabled
 * \param gpio GPIO number
 * \param enabled true to enable input hysteresis on specified GPIO
 */
void gpio_set_input_hysteresis_enabled(uint gpio, bool enabled)
{

}

/*! \brief Determine whether input hysteresis is enabled on a specified GPIO
 *  \ingroup hardware_gpio
 *
 * \sa gpio_set_input_hysteresis_enabled
 * \param gpio GPIO number
 */
bool gpio_is_input_hysteresis_enabled(uint gpio)
{
    return false;
}


/*! \brief Set slew rate for a specified GPIO
 *  \ingroup hardware_gpio
 *
 * \sa gpio_get_slew_rate
 * \param gpio GPIO number
 * \param slew GPIO output slew rate
 */
void gpio_set_slew_rate(uint gpio, enum gpio_slew_rate slew)
{

}

/*! \brief Determine current slew rate for a specified GPIO
 *  \ingroup hardware_gpio
 *
 * \sa gpio_set_slew_rate
 * \param gpio GPIO number
 * \return Current slew rate of that GPIO
 */
enum gpio_slew_rate gpio_get_slew_rate(uint gpio)
{
    return 0;
}

/*! \brief Set drive strength for a specified GPIO
 *  \ingroup hardware_gpio
 *
 * \sa gpio_get_drive_strength
 * \param gpio GPIO number
 * \param drive GPIO output drive strength
 */
void gpio_set_drive_strength(uint gpio, enum gpio_drive_strength drive)
{

}

/*! \brief Determine current slew rate for a specified GPIO
 *  \ingroup hardware_gpio
 *
 * \sa gpio_set_drive_strength
 * \param gpio GPIO number
 * \return Current drive strength of that GPIO
 */
enum gpio_drive_strength gpio_get_drive_strength(uint gpio)
{
    return 0;
}

/*! \brief Enable or disable specific interrupt events for specified GPIO
 *  \ingroup hardware_gpio
 *
 * This function sets which GPIO events cause a GPIO interrupt on the calling core. See
 * \ref gpio_set_irq_callback, \ref gpio_set_irq_enabled_with_callback and
 * \ref gpio_add_raw_irq_handler to set up a GPIO interrupt handler to handle the events.
 *
 * \note The IO IRQs are independent per-processor. This configures the interrupt events for
 * the processor that calls the function.
 *
 * \param gpio GPIO number
 * \param event_mask Which events will cause an interrupt
 * \param enabled Enable or disable flag
 *
 * Events is a bitmask of the following \ref gpio_irq_level values:
 *
 * bit | constant            | interrupt
 * ----|----------------------------------------------------------
 *   0 | GPIO_IRQ_LEVEL_LOW  | Continuously while level is low
 *   1 | GPIO_IRQ_LEVEL_HIGH | Continuously while level is high
 *   2 | GPIO_IRQ_EDGE_FALL  | On each transition from high to low
 *   3 | GPIO_IRQ_EDGE_RISE  | On each transition from low to high
 *
 * which are specified in \ref gpio_irq_level
 */
void gpio_set_irq_enabled(uint gpio, uint32_t event_mask, bool enabled)
{

}

/*! \brief Set the generic callback used for GPIO IRQ events for the current core
 *  \ingroup hardware_gpio
 *
 * This function sets the callback used for all GPIO IRQs on the current core that are not explicitly
 * hooked via \ref gpio_add_raw_irq_handler or other gpio_add_raw_irq_handler_ functions.
 *
 * This function is called with the GPIO number and event mask for each of the (not explicitly hooked)
 * GPIOs that have events enabled and that are pending (see \ref gpio_get_irq_event_mask).
 *
 * \note The IO IRQs are independent per-processor. This function affects
 * the processor that calls the function.
 *
 * \param callback default user function to call on GPIO irq. Note only one of these can be set per processor.
 */
void gpio_set_irq_callback(gpio_irq_callback_t callback)
{

}

/*! \brief Convenience function which performs multiple GPIO IRQ related initializations
 *  \ingroup hardware_gpio
 *
 * This method is a slightly eclectic mix of initialization, that:
 *
 * \li Updates whether the specified events for the specified GPIO causes an interrupt on the calling core based
 * on the enable flag.
 *
 * \li Sets the callback handler for the calling core to callback (or clears the handler if the callback is NULL).
 *
 * \li Enables GPIO IRQs on the current core if enabled is true.
 *
 * This method is commonly used to perform a one time setup, and following that any additional IRQs/events are enabled
 * via \ref gpio_set_irq_enabled. All GPIOs/events added in this way on the same core share the same callback; for multiple
 * independent handlers for different GPIOs you should use \ref gpio_add_raw_irq_handler and related functions.
 *
 * This method is equivalent to:
 *
 * \code{.c}
 * gpio_set_irq_enabled(gpio, event_mask, enabled);
 * gpio_set_irq_callback(callback);
 * if (enabled) irq_set_enabled(IO_IRQ_BANK0, true);
 * \endcode
 *
 * \note The IO IRQs are independent per-processor. This method affects only the processor that calls the function.
 *
 * \param gpio GPIO number
 * \param event_mask Which events will cause an interrupt. See \ref gpio_irq_level for details.
 * \param enabled Enable or disable flag
 * \param callback user function to call on GPIO irq. if NULL, the callback is removed
 */
void gpio_set_irq_enabled_with_callback(uint gpio, uint32_t event_mask, bool enabled, gpio_irq_callback_t callback)
{

}

/*! \brief Enable dormant wake up interrupt for specified GPIO and events
 *  \ingroup hardware_gpio
 *
 * This configures IRQs to restart the XOSC or ROSC when they are
 * disabled in dormant mode
 *
 * \param gpio GPIO number
 * \param event_mask Which events will cause an interrupt. See \ref gpio_irq_level for details.
 * \param enabled Enable/disable flag
 */
void gpio_set_dormant_irq_enabled(uint gpio, uint32_t event_mask, bool enabled)
{

}

/*! \brief Acknowledge a GPIO interrupt for the specified events on the calling core
 *  \ingroup hardware_gpio
 *
 * \note This may be called with a mask of any of valid bits specified in \ref gpio_irq_level, however
 * it has no effect on \a level sensitive interrupts which remain pending while the GPIO is at the specified
 * level. When handling \a level sensitive interrupts, you should generally disable the interrupt (see
 * \ref gpio_set_irq_enabled) and then set it up again later once the GPIO level has changed (or to catch
 * the opposite level).
 *
 * \param gpio GPIO number
 *
 * \note For callbacks set with \ref gpio_set_irq_enabled_with_callback, or \ref gpio_set_irq_callback, this function is called automatically.
 * \param event_mask Bitmask of events to clear. See \ref gpio_irq_level for details.
 */
void gpio_acknowledge_irq(uint gpio, uint32_t event_mask)
{

}

/*! \brief Adds a raw GPIO IRQ handler for the specified GPIOs on the current core
 *  \ingroup hardware_gpio
 *
 * In addition to the default mechanism of a single GPIO IRQ event callback per core (see \ref gpio_set_irq_callback),
 * it is possible to add explicit GPIO IRQ handlers which are called independent of the default callback. The order
 * relative to the default callback can be controlled via the order_priority parameter (the default callback has the priority
 * \ref GPIO_IRQ_CALLBACK_ORDER_PRIORITY which defaults to the lowest priority with the intention of it running last).
 *
 * This method adds such an explicit GPIO IRQ handler, and disables the "default" callback for the specified GPIOs.
 *
 * \note Multiple raw handlers should not be added for the same GPIOs, and this method will assert if you attempt to.
 *
 * A raw handler should check for whichever GPIOs and events it handles, and acknowledge them itself; it might look something like:
 *
 * \code{.c}
 * void my_irq_handler(void) {
 *     if (gpio_get_irq_event_mask(my_gpio_num) & my_gpio_event_mask) {
 *        gpio_acknowledge_irq(my_gpio_num, my_gpio_event_mask);
 *       // handle the IRQ
 *     }
 *     if (gpio_get_irq_event_mask(my_gpio_num2) & my_gpio_event_mask2) {
 *        gpio_acknowledge_irq(my_gpio_num2, my_gpio_event_mask2);
 *       // handle the IRQ
 *     }
 * }
 * \endcode
 *
 * @param gpio_mask a bit mask of the GPIO numbers that will no longer be passed to the default callback for this core
 * @param handler the handler to add to the list of GPIO IRQ handlers for this core
 * @param order_priority the priority order to determine the relative position of the handler in the list of GPIO IRQ handlers for this core.
 */
void gpio_add_raw_irq_handler_with_order_priority_masked(uint gpio_mask, irq_handler_t handler, uint8_t order_priority)
{

}

/*! \brief Adds a raw GPIO IRQ handler for the specified GPIOs on the current core
 *  \ingroup hardware_gpio
 *
 * In addition to the default mechanism of a single GPIO IRQ event callback per core (see \ref gpio_set_irq_callback),
 * it is possible to add explicit GPIO IRQ handlers which are called independent of the default event callback.
 *
 * This method adds such a callback, and disables the "default" callback for the specified GPIOs.
 *
 * \note Multiple raw handlers should not be added for the same GPIOs, and this method will assert if you attempt to.
 *
 * A raw handler should check for whichever GPIOs and events it handles, and acknowledge them itself; it might look something like:
 *
 * \code{.c}
 * void my_irq_handler(void) {
 *     if (gpio_get_irq_event_mask(my_gpio_num) & my_gpio_event_mask) {
 *        gpio_acknowledge_irq(my_gpio_num, my_gpio_event_mask);
 *       // handle the IRQ
 *     }
 *     if (gpio_get_irq_event_mask(my_gpio_num2) & my_gpio_event_mask2) {
 *        gpio_acknowledge_irq(my_gpio_num2, my_gpio_event_mask2);
 *       // handle the IRQ
 *     }
 * }
 * \endcode
 *
 * @param gpio_mask a bit mask of the GPIO numbers that will no longer be passed to the default callback for this core
 * @param handler the handler to add to the list of GPIO IRQ handlers for this core
 */
void gpio_add_raw_irq_handler_masked(uint gpio_mask, irq_handler_t handler)
{

}

/*! \brief Removes a raw GPIO IRQ handler for the specified GPIOs on the current core
 *  \ingroup hardware_gpio
 *
 * In addition to the default mechanism of a single GPIO IRQ event callback per core (see \ref gpio_set_irq_callback),
 * it is possible to add explicit GPIO IRQ handlers which are called independent of the default event callback.
 *
 * This method removes such a callback, and enables the "default" callback for the specified GPIOs.
 *
 * @param gpio_mask a bit mask of the GPIO numbers that will now be passed to the default callback for this core
 * @param handler the handler to remove from the list of GPIO IRQ handlers for this core
 */
void gpio_remove_raw_irq_handler_masked(uint gpio_mask, irq_handler_t handler)
{

}

/*! \brief Initialise a GPIO for (enabled I/O and set func to GPIO_FUNC_SIO)
 *  \ingroup hardware_gpio
 *
 * Clear the output enable (i.e. set to input).
 * Clear any output value.
 *
 * \param gpio GPIO number
 */
void gpio_init(uint gpio)
{

}

/*! \brief Resets a GPIO back to the NULL function, i.e. disables it.
 *  \ingroup hardware_gpio
 *
 * \param gpio GPIO number
 */
void gpio_deinit(uint gpio)
{

}

/*! \brief Initialise multiple GPIOs (enabled I/O and set func to GPIO_FUNC_SIO)
 *  \ingroup hardware_gpio
 *
 * Clear the output enable (i.e. set to input).
 * Clear any output value.
 *
 * \param gpio_mask Mask with 1 bit per GPIO number to initialize
 */
void gpio_init_mask(uint gpio_mask)
{

}
