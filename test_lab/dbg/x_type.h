


#ifndef _X_TYPE_H_
#define _X_TYPE_H_


enum x_error {

    X_SUCCESS = 0,

    X_ERROR = -1, 

    X_ERROR_BOUNDS = -2,

    X_ERROR_INVALID_PTR = -3,

    X_ERROR_MEMORY = -4, 

    X_ERROR_LOCK = -5,

    X_ERROR_XXX = -6

};

enum x_dbg {

    X_DBG_MSG = 0,

    X_DBG_PRN = 1,

    X_DBG_WRN = 2,

    X_DBG_ERR = 3,

    X_DBG_OFF = 4
};

#endif
