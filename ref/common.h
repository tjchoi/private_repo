

#ifndef _X_COMMON_H_
#define _X_COMMON_H_

/** Return with \ref omci_error::OMCI_ERROR_INVALID_PTR
    if PTR == NULL */
#define RETURN_IF_PTR_NULL(PTR) \
    do { \
        if ((PTR) == NULL) { \
            dbg_err("ERROR(%d) Pointer '" #PTR \
                "' is null in %s", \
                 OMCI_ERROR_INVALID_PTR, \
                 __func__); \
            dbg_out_ret(__func__, OMCI_ERROR_INVALID_PTR); \
            return OMCI_ERROR_INVALID_PTR; \
        } \
    } while (0)

/** Version of \ref RETURN_IF_PTR_NULL that doesn't use \ref dbg_out_ret */
#define _RETURN_IF_PTR_NULL(PTR) \
    do { \
        if ((PTR) == NULL) { \
            dbg_err("ERROR(%d) Pointer '" #PTR \
                "' is null in %s", \
                 OMCI_ERROR_INVALID_PTR, \
                 __func__); \
            return OMCI_ERROR_INVALID_PTR; \
        } \
    } while (0)

/** Return with \ref omci_error::OMCI_ERROR_MEMORY if PTR == NULL */
#define RETURN_IF_MALLOC_ERROR(PTR) \
    do { \
        if ((PTR) == NULL) { \
            dbg_err("ERROR(%d) Memory allocation error for '" #PTR \
                 "' in %s", \
                 OMCI_ERROR_MEMORY, \
                 __func__); \
            dbg_out_ret(__func__, OMCI_ERROR_MEMORY); \
            return OMCI_ERROR_MEMORY; \
        } \
    } while (0)

/** Version of \ref RETURN_IF_MALLOC_ERROR that doesn't use \ref dbg_out_ret */
#define _RETURN_IF_MALLOC_ERROR(PTR) \
    do { \
        if ((PTR) == NULL) { \
            dbg_err("ERROR(%d) Memory allocation error for '" #PTR \
                 "' in %s", \
                 OMCI_ERROR_MEMORY, \
                 __func__); \
            return OMCI_ERROR_MEMORY; \
        } \
    } while (0)

/** Return with ERROR if ERROR != OMCI_SUCCESS */
#define RETURN_IF_ERROR(ERROR) \
    do { \
        if ((ERROR)) { \
            dbg_out_ret(__func__, ERROR); \
            return ERROR; \
        } \
    } while (0)

/** Version of \ref RETURN_IF_ERROR that doesn't use \ref dbg_out_ret */
#define _RETURN_IF_ERROR(ERROR) \
    do { \
        if ((ERROR)) { \
            return ERROR; \
        } \
    } while (0)

/** Return with \ref omci_error::OMCI_ERROR_BOUNDS
    if DATA_SIZE > MAX_SIZE */
#define RETURN_IF_BOUNDS_ERROR(DATA_SIZE, MAX_SIZE) \
    do { \
        if ((DATA_SIZE) > (MAX_SIZE)) { \
            dbg_err("ERROR(%d) " \
                "Bounds error (" #DATA_SIZE \
                " > " #MAX_SIZE ")" \
                " in %s", \
                OMCI_ERROR_BOUNDS, \
                __func__); \
            dbg_out_ret(__func__, OMCI_ERROR_BOUNDS); \
            return OMCI_ERROR_BOUNDS; \
        } \
    } while (0)

#endif
