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
    const char *filename;
    //char *filename[20]; //ok

    int fd;
    int rc;

    if (argc != 2) {
        fprintf(stderr, "Usage: usbreset device-filename\n");

        //return 1;
        fprintf(stderr, "Now, input filename\n");

        //KEYBOARD INPUT
        scanf("%s",filename);
    }
    else{
        filename = argv[1];
    }

    fd = open(filename, O_WRONLY);
    if (fd < 0) {
        perror("Error opening output file");
        //return 1;
    }
    else{


    // SCAN USB DEVICE

    char *buf = malloc(1024);
    size_t scan;

    size_t sz   = sizeof(buf);
    size_t sz_t = 1;

    scan = fread(buf, sz, sz_t, fd);

    }
    // COMMAND

    //fwrite()

    // RESET
    printf("Resetting USB device %s\n", filename);
    rc = ioctl(fd, USBDEVFS_RESET, 0);
    if (rc < 0) {
        perror("Error in ioctl");
        return 1;
    }
    printf("Reset successful\n");

    close(fd);
    return 0;
}
