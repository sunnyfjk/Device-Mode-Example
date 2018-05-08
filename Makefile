
# @Author: fjk
# @Date:   2018-04-17T09:50:00+08:00
# @Email:  sunnyfjk@gmail.com
# @Filename: Makefile
# @Last modified by:   fjk
# @Last modified time: 2018-05-08T16:20:06+08:00
# @License: GPLV3.0
obj-m =CharDevice.o
obj-m +=CharBus.o
obj-m +=CharDriver.o
PWD = $(shell pwd)
KVERSION = $(shell uname -r)
all:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
install:
	@insmod CharBus.ko
	@insmod CharDevice.ko
	@insmod CharDriver.ko
uninstall:
	@rmmod CharDevice
	@rmmod CharDriver
	@rmmod CharBus
