#include "uart.h"

/*! \brief Initialise a UART
 *  \ingroup hardware_uart
 *
 * Put the UART into a known state, and enable it. Must be called before other
 * functions.
 *
 * This function always enables the FIFOs, and configures the UART for the
 * following default line format:
 *
 * - 8 data bits
 * - No parity bit
 * - One stop bit
 *
 * \note There is no guarantee that the baudrate requested will be possible, the nearest will be chosen,
 * and this function will return the configured baud rate.
 *
 * \param uart UART instance. \ref uart0 or \ref uart1
 * \param baudrate Baudrate of UART in Hz
 * \return Actual set baudrate
 */
uint uart_init(uart_inst_t *uart, uint baudrate)
{
    return 9600;
}

/*! \brief DeInitialise a UART
 *  \ingroup hardware_uart
 *
 * Disable the UART if it is no longer used. Must be reinitialised before
 * being used again.
 *
 * \param uart UART instance. \ref uart0 or \ref uart1
 */
void uart_deinit(uart_inst_t *uart)
{

}

/*! \brief Set UART baud rate
 *  \ingroup hardware_uart
 *
 * Set baud rate as close as possible to requested, and return actual rate selected.
 *
 * The UART is paused for around two character periods whilst the settings are
 * changed. Data received during this time may be dropped by the UART.
 *
 * Any characters still in the transmit buffer will be sent using the new
 * updated baud rate. uart_tx_wait_blocking() can be called before this
 * function to ensure all characters at the old baud rate have been sent
 * before the rate is changed.
 *
 * This function should not be called from an interrupt context, and the UART
 * interrupt should be disabled before calling this function.
 *
 * \param uart UART instance. \ref uart0 or \ref uart1
 * \param baudrate Baudrate in Hz
 * \return Actual set baudrate
 */
uint uart_set_baudrate(uart_inst_t *uart, uint baudrate)
{
    return 0;
}

/*! \brief Set UART data format
 *  \ingroup hardware_uart
 *
 * Configure the data format (bits etc) for the UART.
 *
 * The UART is paused for around two character periods whilst the settings are
 * changed. Data received during this time may be dropped by the UART.
 *
 * Any characters still in the transmit buffer will be sent using the new
 * updated data format. uart_tx_wait_blocking() can be called before this
 * function to ensure all characters needing the old format have been sent
 * before the format is changed.
 *
 * This function should not be called from an interrupt context, and the UART
 * interrupt should be disabled before calling this function.
 *
 * \param uart UART instance. \ref uart0 or \ref uart1
 * \param data_bits Number of bits of data. 5..8
 * \param stop_bits Number of stop bits 1..2
 * \param parity Parity option.
 */
void uart_set_format(uart_inst_t *uart, uint data_bits, uint stop_bits, uart_parity_t parity)
{

}

/*! \brief Enable/Disable the FIFOs on specified UART
 *  \ingroup hardware_uart
 *
 * The UART is paused for around two character periods whilst the settings are
 * changed. Data received during this time may be dropped by the UART.
 *
 * Any characters still in the transmit FIFO will be lost if the FIFO is
 * disabled. uart_tx_wait_blocking() can be called before this
 * function to avoid this.
 *
 * This function should not be called from an interrupt context, and the UART
 * interrupt should be disabled when calling this function.
 *
 * \param uart UART instance. \ref uart0 or \ref uart1
 * \param enabled true to enable FIFO (default), false to disable
 */
void uart_set_fifo_enabled(uart_inst_t *uart, bool enabled)
{

}

/*! \brief Assert a break condition on the UART transmission.
 *  \ingroup hardware_uart
 *
 * \param uart UART instance. \ref uart0 or \ref uart1
 * \param en Assert break condition (TX held low) if true. Clear break condition if false.
 */
void uart_set_break(uart_inst_t *uart, bool en)
{

}

/*! \brief Wait for up to a certain number of microseconds for the RX FIFO to be non empty
 *  \ingroup hardware_uart
 *
 * \param uart UART instance. \ref uart0 or \ref uart1
 * \param us the number of microseconds to wait at most (may be 0 for an instantaneous check)
 * \return true if the RX FIFO became non empty before the timeout, false otherwise
 */
bool uart_is_readable_within_us(uart_inst_t *uart, uint32_t us)
{
    return false;
}
