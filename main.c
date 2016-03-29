// Command example

// VOLTage:
// DC:RANGe { <range> | Minimum | Maximum }

// флэшка:      /dev/sdb

// Вольтметр:   /dev/usbtmc0

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

#include <linux/usbdevice_fs.h>
#include <malloc.h>


int main(int argc, char **argv)
{
    //const char *filename = "/dev/sdb";
    const char *filename = "/dev/usbtmc0";

    int fd;
    int rc;

    fd = open(filename, O_WRONLY);
    if (fd < 0) {
        perror("file error.\n");
        return 1;
    }
    else{

    printf("Ok.\n");
    // SEND COMMAND




    // SCAN USB DEVICE

    char *buf = malloc(512);

    size_t scan;
    size_t sz   = sizeof(buf);
    size_t sz_t = 1;

    char *cmd1 = "VOLT:DC:RANG 10";

    int sr = write(fd, cmd1, sizeof(cmd1));

    int ri = read(fd, buf, sz);

    printf("buf size = %d\n", sizeof(&buf));
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
