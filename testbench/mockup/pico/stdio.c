#include "stdio.h"
/*! \brief Initialize all of the present standard stdio types that are linked into the binary.
 * \ingroup pico_stdio
 *
 * Call this method once you have set up your clocks to enable the stdio support for UART, USB
 * and semihosting based on the presence of the respective libraries in the binary.
 *
 * When stdio_usb is configured, this method can be optionally made to block, waiting for a connection
 * via the variables specified in \ref stdio_usb_init (i.e. \ref PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS)
 *
 * \return true if at least one output was successfully initialized, false otherwise.
 * \see stdio_uart, stdio_usb, stdio_semihosting
 */
bool stdio_init_all(void)
{
    return true;
}

/*! \brief Flushes any buffered output.
 * \ingroup pico_stdio
 */
void stdio_flush(void)
{

}

/*! \brief Return a character from stdin if there is one available within a timeout
 * \ingroup pico_stdio
 *
 * \param timeout_us the timeout in microseconds, or 0 to not wait for a character if none available.
 * \return the character from 0-255 or PICO_ERROR_TIMEOUT if timeout occurs
 */
int getchar_timeout_us(uint32_t timeout_us)
{
    return 0;
}

/*! \brief Adds or removes a driver from the list of active drivers used for input/output
 * \ingroup pico_stdio
 *
 * \note this method should always be called on an initialized driver and is not re-entrant
 * \param driver the driver
 * \param enabled true to add, false to remove
 */
void stdio_set_driver_enabled(stdio_driver_t *driver, bool enabled)
{

}

/*! \brief Control limiting of output to a single driver
 * \ingroup pico_stdio
 *
 * \note this method should always be called on an initialized driver
 *
 * \param driver if non-null then output only that driver will be used for input/output (assuming it is in the list of enabled drivers).
 *               if NULL then all enabled drivers will be used
 */
void stdio_filter_driver(stdio_driver_t *driver)
{

}

/*! \brief control conversion of line feeds to carriage return on transmissions
 * \ingroup pico_stdio
 *
 * \note this method should always be called on an initialized driver
 *
 * \param driver the driver
 * \param translate If true, convert line feeds to carriage return on transmissions
 */
void stdio_set_translate_crlf(stdio_driver_t *driver, bool translate)
{

}

/*! \brief putchar variant that skips any CR/LF conversion if enabled
 * \ingroup pico_stdio
 */
int putchar_raw(int c)
{
    return 0;
}

/*! \brief puts variant that skips any CR/LF conversion if enabled
 * \ingroup pico_stdio
 */
int puts_raw(const char *s)
{
    return 0;
}

/*! \brief get notified when there are input characters available
 * \ingroup pico_stdio
 *
 * \param fn Callback function to be called when characters are available. Pass NULL to cancel any existing callback
 * \param param Pointer to pass to the callback
 */
void stdio_set_chars_available_callback(void (*fn)(void*), void *param)
{

}
