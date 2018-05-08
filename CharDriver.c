/**
 * @Author: fjk
 * @Date:   2018-05-08T15:32:24+08:00
 * @Email:  sunnyfjk@gmail.com
 * @Filename: CharDriver.c
 * @Last modified by:   fjk
 * @Last modified time: 2018-05-08T16:21:10+08:00
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

extern struct bus_type CharBus;
int driver_probe(struct device *dev) {
  struct CharDeviceData_t *data = dev->platform_data;
  PERR("probe device name %s\n", data->name);
  return 0;
}
int driver_remove(struct device *dev) {
  struct CharDeviceData_t *data = dev->platform_data;
  PERR("remove device or driver name %s\n", data->name);
  return 0;
}

struct device_driver CharListDriver = {
    /**/
    .name = "CharListDriver",
    /**/
    .bus = &CharBus,
    /**/
    .probe = driver_probe,
    /**/
    .remove = driver_remove,
};
struct device_driver CharQueueDriver = {
    /**/
    .name = "CharQueueDriver",
    /**/
    .bus = &CharBus,
    /**/
    .probe = driver_probe,
    /**/
    .remove = driver_remove,
};
struct device_driver CharStacksDriver = {
    /**/
    .name = "CharStacksDriver",
    /**/
    .bus = &CharBus,
    /**/
    .probe = driver_probe,
    /**/
    .remove = driver_remove,
};
int __init CharDeviceDriver_init(void) {
  int ret = 0;
  PINFO("INIT\n");
  ret = driver_register(&CharListDriver);
  if (ret)
    goto driver_register_char_list_err;
  ret = driver_register(&CharQueueDriver);
  if (ret)
    goto driver_register_char_queue_err;
  ret = driver_register(&CharStacksDriver);
  if (ret)
    goto driver_register_char_stacks_err;
  return 0;
driver_register_char_stacks_err:
  driver_unregister(&CharQueueDriver);
driver_register_char_queue_err:
  driver_unregister(&CharListDriver);
driver_register_char_list_err:
  return ret;
}
void __exit CharDeviceDriver_exit(void) {
  PINFO("EXIT\n");
  driver_unregister(&CharStacksDriver);
  driver_unregister(&CharQueueDriver);
  driver_unregister(&CharListDriver);
}

module_init(CharDeviceDriver_init);
module_exit(CharDeviceDriver_exit);
