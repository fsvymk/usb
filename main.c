// Command example

// VOLTage:
// DC:RANGe { <range> | Minimum | Maximum }

// флэшка: /dev/sdb

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

#include <linux/usbdevice_fs.h>
#include <malloc.h>


int main(int argc, char **argv)
{
    const char *filename = "/dev/sdb";

    int fd;
    int rc;

    fd = open(filename, O_WRONLY);
    if (fd < 0) {
        perror("file error.\n");
        return 1;
    }
    else{

        printf("Ok. ");
    // SCAN USB DEVICE

    char *buf = malloc(1024);

    size_t scan;
    size_t sz   = sizeof(buf);
    size_t sz_t = 1;

    int ri = read(fd, buf, sz);

    }
    // COMMAND



    //fwrite()

    // RESET
    /*
    printf("Resetting USB device %s\n", filename);
    rc = ioctl(fd, USBDEVFS_RESET, 0);
    if (rc < 0) {
        perror("Error in ioctl");
        return 1;
    }
    printf("Reset successful\n");
*/
    close(fd);
    return 0;
}
