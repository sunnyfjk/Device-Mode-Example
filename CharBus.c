/**
 * @Author: fjk
 * @Date:   2018-05-08T15:28:06+08:00
 * @Email:  sunnyfjk@gmail.com
 * @Filename: CharBus.c
 * @Last modified by:   fjk
 * @Last modified time: 2018-05-08T16:21:34+08:00
 * @License: GPLV3.0
 */
#include "command.h"
#include <linux/device.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("FJK");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("this is a test char device");

#define DRIVER_NAME "CharDevice"

/*Char Bus Type Start*/
int CharBus_match(struct device *dev, struct device_driver *drv) {
  struct CharDeviceData_t *data = dev->platform_data;
  return !(memcmp(data->name, drv->name, strlen(data->name)));
}
struct bus_type CharBus = {
    /**/
    .name = "CharBus",
    /**/
    .match = CharBus_match,
};
EXPORT_SYMBOL(CharBus);
int __init CharBus_init(void) {
  PINFO("INIT\n");
  return bus_register(&CharBus);
}
void __exit CharBus_exit(void) {
  PINFO("EXIT\n");
  bus_unregister(&CharBus);
}

module_init(CharBus_init);
module_exit(CharBus_exit);
/*Char Bus Type End*/
