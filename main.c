// g++ source.cpp `pkg-config --libs --cflags libusb-1.0`

//b#include "/usr/include/libusb-1.0/libusb.h"

#include "libusb.h"
//#include <linux/usb/>

#include <linux/module.h>
#include <linux/usbdevice_fs.h>
#include <linux/kernel.h>
#include <linux/usb.h>

int main(int argc, char *argv[])
{

    libusb_init(NULL);

    printf("Hello World!\n");
    return 0;
}
