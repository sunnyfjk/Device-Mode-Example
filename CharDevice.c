/**
 * @Author: fjk
 * @Date:   2018-05-08T10:52:10+08:00
 * @Email:  sunnyfjk@gmail.com
 * @Filename: charDevice.c
 * @Last modified by:   fjk
 * @Last modified time: 2018-05-08T16:21:28+08:00
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

struct CharDeviceData_t CharList_data[] = {
    {
        .name = "CharListDriver",
    },
    {
        .name = "CharQueueDriver",
    },
    {
        .name = "CharStacksDriver",
    },
};

void CharList_release(struct device *dev) {}
struct device CharList = {
    /**/
    .init_name = "CharList",
    /**/
    .bus = &CharBus,
    /**/
    .release = CharList_release,
    /**/
    .platform_data = &(CharList_data[0]),
};
struct device CharQueue = {
    /**/
    .init_name = "CharQueue",
    /**/
    .bus = &CharBus,
    /**/
    .release = CharList_release,
    .platform_data = &(CharList_data[1]),
};
struct device CharStacks = {
    /**/
    .init_name = "CharStacks",
    /**/
    .bus = &CharBus,
    /**/
    .release = CharList_release,
    .platform_data = &(CharList_data[2]),
};
int __init CharDevice_init(void) {
  int ret = 0;
  PINFO("INIT\n");
  ret = device_register(&CharList);
  if (ret)
    goto device_register_char_list_err;
  ret = device_register(&CharQueue);
  if (ret)
    goto device_register_char_queue_err;
  ret = device_register(&CharStacks);
  if (ret)
    goto device_register_char_stacks_err;
  return 0;
device_register_char_stacks_err:
  device_unregister(&CharQueue);
device_register_char_queue_err:
  device_unregister(&CharList);
device_register_char_list_err:
  return ret;
}
void __exit CharDevice_exit(void) {
  PINFO("EXIT\n");
  device_unregister(&CharStacks);
  device_unregister(&CharQueue);
  device_unregister(&CharList);
}

module_init(CharDevice_init);
module_exit(CharDevice_exit);
