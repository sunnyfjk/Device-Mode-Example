/**
 * @Author: fjk
 * @Date:   2018-05-08T15:48:18+08:00
 * @Email:  sunnyfjk@gmail.com
 * @Filename: command.h
 * @Last modified by:   fjk
 * @Last modified time: 2018-05-08T16:21:18+08:00
 * @License: GPLV3.0
 */
#ifndef __COMMAND_H__
#define __COMMAND_H__

#define PDEBUG(fmt, args ...)                                                   \
        printk(KERN_DEBUG "[%s(%s:%d)]" fmt, DRIVER_NAME, __FUNCTION__, __LINE__,    \
               ## args)
#define PERR(fmt, args ...)                                                     \
        printk(KERN_ERR "[%s(%s:%d)]" fmt, DRIVER_NAME, __FUNCTION__, __LINE__,      \
               ## args)
#define PINFO(fmt, args ...)                                                    \
        printk(KERN_INFO "[%s(%s:%d)]" fmt, DRIVER_NAME, __FUNCTION__, __LINE__,     \
               ## args)

struct CharDeviceData_t {
        const char *name;
        char *data;
};

#endif
