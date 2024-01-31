#include "timer.h"

/*! \brief Return the current 64 bit timestamp value in microseconds
*  \ingroup hardware_timer
*
* Returns the full 64 bits of the hardware timer. The \ref pico_time and other functions rely on the fact that this
* value monotonically increases from power up. As such it is expected that this value counts upwards and never wraps
* (we apologize for introducing a potential year 5851444 bug).
*
* \return the 64 bit timestamp
*/
uint64_t time_us_64(void)
{
    return 0; //todo: return a climing time
}

/*! \brief Busy wait wasting cycles for the given (32 bit) number of microseconds
 *  \ingroup hardware_timer
 *
 * \param delay_us delay amount in microseconds
 */
void busy_wait_us_32(uint32_t delay_us)
{

}

/*! \brief Busy wait wasting cycles for the given (64 bit) number of microseconds
 *  \ingroup hardware_timer
 *
 * \param delay_us delay amount in microseconds
 */
void busy_wait_us(uint64_t delay_us)
{

}

/*! \brief Busy wait wasting cycles for the given number of milliseconds
 *  \ingroup hardware_timer
 *
 * \param delay_ms delay amount in milliseconds
 */
void busy_wait_ms(uint32_t delay_ms)
{

}

/*! \brief Busy wait wasting cycles until after the specified timestamp
 *  \ingroup hardware_timer
 *
 * \param t Absolute time to wait until
 */
void busy_wait_until(absolute_time_t t)
{

}

/*! \brief cooperatively claim the use of this hardware alarm_num
 *  \ingroup hardware_timer
 *
 * This method hard asserts if the hardware alarm is currently claimed.
 *
 * \param alarm_num the hardware alarm to claim
 * \sa hardware_claiming
 */
void hardware_alarm_claim(uint alarm_num)
{

}

/*! \brief cooperatively claim the use of this hardware alarm_num
 *  \ingroup hardware_timer
 *
 * This method attempts to claim an unused hardware alarm
 *
 * \return alarm_num the hardware alarm claimed or -1 if requires was false, and none are available
 * \sa hardware_claiming
 */
int hardware_alarm_claim_unused(bool required)
{
    return 0;
}

/*! \brief cooperatively release the claim on use of this hardware alarm_num
 *  \ingroup hardware_timer
 *
 * \param alarm_num the hardware alarm to unclaim
 * \sa hardware_claiming
 */
void hardware_alarm_unclaim(uint alarm_num)
{

}

/*! \brief Determine if a hardware alarm has been claimed
 *  \ingroup hardware_timer
 *
 * \param alarm_num the hardware alarm number
 * \return true if claimed, false otherwise
 * \see hardware_alarm_claim
 */
bool hardware_alarm_is_claimed(uint alarm_num)
{
    return false;
}

/*! \brief Enable/Disable a callback for a hardware timer on this core
 *  \ingroup hardware_timer
 *
 * This method enables/disables the alarm IRQ for the specified hardware alarm on the
 * calling core, and set the specified callback to be associated with that alarm.
 *
 * This callback will be used for the timeout set via hardware_alarm_set_target
 *
 * \note This will install the handler on the current core if the IRQ handler isn't already set.
 * Therefore the user has the opportunity to call this up from the core of their choice
 *
 * \param alarm_num the hardware alarm number
 * \param callback the callback to install, or NULL to unset
 *
 * \sa hardware_alarm_set_target()
 */
void hardware_alarm_set_callback(uint alarm_num, hardware_alarm_callback_t callback)
{

}

/**
 * \brief Set the current target for the specified hardware alarm
 * \ingroup hardware_timer
 *
 * This will replace any existing target
 *
 * @param alarm_num the hardware alarm number
 * @param t the target timestamp
 * @return true if the target was "missed"; i.e. it was in the past, or occurred before a future hardware timeout could be set
 */
bool hardware_alarm_set_target(uint alarm_num, absolute_time_t t)
{
    return false;
}

/**
 * \brief Cancel an existing target (if any) for a given hardware_alarm
 * \ingroup hardware_timer
 *
 * @param alarm_num the hardware alarm number
 */
void hardware_alarm_cancel(uint alarm_num)
{

}

/**
 * \brief Force and IRQ for a specific hardware alarm
 * \ingroup hardware_timer
 *
 * This method will forcibly make sure the current alarm callback (if present) for the hardware
 * alarm is called from an IRQ context after this call. If an actual callback is due at the same
 * time then the callback may only be called once.
 *
 * Calling this method does not otherwise interfere with regular callback operations.
 *
 * @param alarm_num the hardware alarm number
 */
void hardware_alarm_force_irq(uint alarm_num)
{

}
