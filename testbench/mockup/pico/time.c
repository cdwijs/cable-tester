#include "time.h"


/*! \brief The timestamp representing the end of time; this is actually not the maximum possible
 * timestamp, but is set to 0x7fffffff_ffffffff microseconds to avoid sign overflows with time
 * arithmetic. This is almost 300,000 years, so should be sufficient.
 * \ingroup timestamp
 */
const absolute_time_t at_the_end_of_time;

/*! \brief The timestamp representing a null timestamp
 * \ingroup timestamp
 */
const absolute_time_t nil_time;

/*! \brief Wait until after the given timestamp to return
 * \ingroup sleep
 *
 * \note  This method attempts to perform a lower power (WFE) sleep
 *
 * \param target the time after which to return
 * \sa sleep_us()
 * \sa busy_wait_until()
 * */
void sleep_until(absolute_time_t target)
{

}

/*! \brief Wait for the given number of microseconds before returning
 * \ingroup sleep
 *
 * \note This method attempts to perform a lower power (WFE) sleep
 *
 * \param us the number of microseconds to sleep
 * \sa busy_wait_us()
 */
void sleep_us(uint64_t us)
{

}

/*! \brief Wait for the given number of milliseconds before returning
 * \ingroup sleep
 *
 * \note This method attempts to perform a lower power sleep (using WFE) as much as possible.
 *
 * \param ms the number of milliseconds to sleep
 */
void sleep_ms(uint32_t ms)
{

}

/*! \brief Helper method for blocking on a timeout
 * \ingroup sleep
 *
 * This method will return in response to an event (as per __wfe) or
 * when the target time is reached, or at any point before.
 *
 * This method can be used to implement a lower power polling loop waiting on
 * some condition signalled by an event (__sev()).
 *
 * This is called \a best_effort because under certain circumstances (notably the default timer pool
 * being disabled or full) the best effort is simply to return immediately without a __wfe, thus turning the calling
 * code into a busy wait.
 *
 * Example usage:
 * ```c
 * bool my_function_with_timeout_us(uint64_t timeout_us) {
 *     absolute_time_t timeout_time = make_timeout_time_us(timeout_us);
 *     do {
 *         // each time round the loop, we check to see if the condition
 *         // we are waiting on has happened
 *         if (my_check_done()) {
 *             // do something
 *             return true;
 *         }
 *         // will try to sleep until timeout or the next processor event 
 *     } while (!best_effort_wfe_or_timeout(timeout_time));
 *     return false; // timed out
 * }
 * ```
 *
 * @param timeout_timestamp the timeout time
 * @return true if the target time is reached, false otherwise
 */
bool best_effort_wfe_or_timeout(absolute_time_t timeout_timestamp)
{
    return true;
}

/**
 * \brief Create the default alarm pool (if not already created or disabled)
 * \ingroup alarm
 */
void alarm_pool_init_default(void)
{

}

#if !PICO_TIME_DEFAULT_ALARM_POOL_DISABLED
/*!
 * \brief The default alarm pool used when alarms are added without specifying an alarm pool,
 *        and also used by the SDK to support lower power sleeps and timeouts.
 *
 * \ingroup alarm
 * \sa #PICO_TIME_DEFAULT_ALARM_POOL_HARDWARE_ALARM_NUM
 */
alarm_pool_t *alarm_pool_get_default(void)
{
    return 0;
}
#endif

/**
 * \brief Create an alarm pool
 *
 * The alarm pool will call callbacks from an alarm IRQ Handler on the core of this function is called from.
 *
 * In many situations there is never any need for anything other than the default alarm pool, however you
 * might want to create another if you want alarm callbacks on core 1 or require alarm pools of
 * different priority (IRQ priority based preemption of callbacks)
 *
 * \note This method will hard assert if the hardware alarm is already claimed.
 *
 * \ingroup alarm
 * \param hardware_alarm_num the hardware alarm to use to back this pool
 * \param max_timers the maximum number of timers
 *        \note For implementation reasons this is limited to PICO_PHEAP_MAX_ENTRIES which defaults to 255
 * \sa alarm_pool_get_default()
 * \sa hardware_claiming
 */
alarm_pool_t *alarm_pool_create(uint hardware_alarm_num, uint max_timers)
{
    return 0;
}

/**
 * \brief Create an alarm pool, claiming an used hardware alarm to back it.
 *
 * The alarm pool will call callbacks from an alarm IRQ Handler on the core of this function is called from.
 *
 * In many situations there is never any need for anything other than the default alarm pool, however you
 * might want to create another if you want alarm callbacks on core 1 or require alarm pools of
 * different priority (IRQ priority based preemption of callbacks)
 *
 * \note This method will hard assert if the there is no free hardware to claim.
 *
 * \ingroup alarm
 * \param max_timers the maximum number of timers
 *        \note For implementation reasons this is limited to PICO_PHEAP_MAX_ENTRIES which defaults to 255
 * \sa alarm_pool_get_default()
 * \sa hardware_claiming
 */
alarm_pool_t *alarm_pool_create_with_unused_hardware_alarm(uint max_timers)
{
    return 0;
}

/**
 * \brief Return the hardware alarm used by an alarm pool
 * \ingroup alarm
 * \param pool the pool
 * \return the hardware alarm used by the pool
 */
uint alarm_pool_hardware_alarm_num(alarm_pool_t *pool)
{
    return 0;
}

/**
 * \brief Return the core number the alarm pool was initialized on (and hence callbacks are called on)
 * \ingroup alarm
 * \param pool the pool
 * \return the core used by the pool
 */
uint alarm_pool_core_num(alarm_pool_t *pool)
{
    return 0;
}

/**
 * \brief Destroy the alarm pool, cancelling all alarms and freeing up the underlying hardware alarm
 * \ingroup alarm
 * \param pool the pool
 */
void alarm_pool_destroy(alarm_pool_t *pool)
{

}

/*!
 * \brief Add an alarm callback to be called at a specific time
 * \ingroup alarm
 *
 * Generally the callback is called as soon as possible after the time specified from an IRQ handler
 * on the core the alarm pool was created on. If the callback is in the past or happens before
 * the alarm setup could be completed, then this method will optionally call the callback itself
 * and then return a return code to indicate that the target time has passed.
 *
 * \note It is safe to call this method from an IRQ handler (including alarm callbacks), and from either core.
 *
 * @param pool the alarm pool to use for scheduling the callback (this determines which hardware alarm is used, and which core calls the callback)
 * @param time the timestamp when (after which) the callback should fire
 * @param callback the callback function
 * @param user_data user data to pass to the callback function
 * @param fire_if_past if true, and the alarm time falls before or during this call before the alarm can be set,
 *                     then the callback should be called during (by) this function instead 
 * @return >0 the alarm id for an active (at the time of return) alarm
 * @return 0 if the alarm time passed before or during the call AND there is no active alarm to return the id of.
 *           The latter can either happen because fire_if_past was false (i.e. no timer was ever created),
 *           or if the callback <i>was</i> called during this method but the callback cancelled itself by returning 0
 * @return -1 if there were no alarm slots available
 */
alarm_id_t alarm_pool_add_alarm_at(alarm_pool_t *pool, absolute_time_t time, alarm_callback_t callback, void *user_data, bool fire_if_past)
{
    return 0;
}

/*!
 * \brief Add an alarm callback to be called at or after a specific time
 * \ingroup alarm
 *
 * The callback is called as soon as possible after the time specified from an IRQ handler
 * on the core the alarm pool was created on. Unlike \ref alarm_pool_add_alarm_at, this method
 * guarantees to call the callback from that core even if the time is during this method call or in the past.
 *
 * \note It is safe to call this method from an IRQ handler (including alarm callbacks), and from either core.
 *
 * @param pool the alarm pool to use for scheduling the callback (this determines which hardware alarm is used, and which core calls the callback)
 * @param time the timestamp when (after which) the callback should fire
 * @param callback the callback function
 * @param user_data user data to pass to the callback function
 * @return >0 the alarm id for an active (at the time of return) alarm
 * @return -1 if there were no alarm slots available
 */
alarm_id_t alarm_pool_add_alarm_at_force_in_context(alarm_pool_t *pool, absolute_time_t time, alarm_callback_t callback,
                                                    void *user_data)
{
    return 0;
}

/*!
 * \brief Cancel an alarm
 * \ingroup alarm
 * \param pool the alarm_pool containing the alarm
 * \param alarm_id the alarm
 * \return true if the alarm was cancelled, false if it didn't exist
 * \sa alarm_id_t for a note on reuse of IDs
 */
bool alarm_pool_cancel_alarm(alarm_pool_t *pool, alarm_id_t alarm_id)
{
    return false;
}

/*!
 * \brief Add a repeating timer that is called repeatedly at the specified interval in microseconds
 * \ingroup repeating_timer
 *
 * Generally the callback is called as soon as possible after the time specified from an IRQ handler
 * on the core the alarm pool was created on. If the callback is in the past or happens before
 * the alarm setup could be completed, then this method will optionally call the callback itself
 * and then return a return code to indicate that the target time has passed.
 *
 * \note It is safe to call this method from an IRQ handler (including alarm callbacks), and from either core.
 *
 * @param pool the alarm pool to use for scheduling the repeating timer (this determines which hardware alarm is used, and which core calls the callback)
 * @param delay_us the repeat delay in microseconds; if >0 then this is the delay between one callback ending and the next starting; if <0 then this is the negative of the time between the starts of the callbacks. The value of 0 is treated as 1
 * @param callback the repeating timer callback function
 * @param user_data user data to pass to store in the repeating_timer structure for use by the callback.
 * @param out the pointer to the user owned structure to store the repeating timer info in. BEWARE this storage location must outlive the repeating timer, so be careful of using stack space
 * @return false if there were no alarm slots available to create the timer, true otherwise.
 */
bool alarm_pool_add_repeating_timer_us(alarm_pool_t *pool, int64_t delay_us, repeating_timer_callback_t callback, void *user_data, repeating_timer_t *out)
{
    return true;
}

/**
 * \brief Cancel a repeating timer
 * \ingroup repeating_timer
 * \param timer the repeating timer to cancel
 * \return true if the repeating timer was cancelled, false if it didn't exist
 * \sa alarm_id_t for a note on reuse of IDs
 */
bool cancel_repeating_timer(repeating_timer_t *timer)
{
    return true;
}
