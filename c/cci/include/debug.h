#include <stdio.h>
#include <stdbool.h>

#ifdef __DEBUG_H__
#define __DEBUG_H__

static bool debug_enabled = false;
static inline bool is_debug_enabled() {
	return debug_enabled;
}

/*!
 * Enable debugging
 */
void debug_on() {
	debug_enabled = true;
}

/*!
 * Disable debugging
 */
void debug_off() {
	debug_enabled = false;
}

/*!
 * Use this macro for writing debug logs
 */
#define DEBUG(fmt, args...)     \
  do {                          \
    if (is_debug_enabled()) {           \
      printf("\n" fmt, ##args); \
    }                           \
  } while(0)

#endif // __DEBUG_H__