#include "bluedotio.hpp"

int bdio_send_packet(hid_device *handle, unsigned char cmd, unsigned char *data, unsigned int data_size) {
    if(handle == NULL) return -1;

    //Build packet
    unsigned char buf[33];
    buf[0] = 0x00; //First byte is the report number
    buf[1] = cmd;  //Command identifier
    memcpy(&buf[2], data, (data_size <= 31 ? data_size : 31) * sizeof(unsigned char));

    //Send packet and get result
    return hid_write(handle, buf, 33) != -1 ? 0 : -1;
}

int bdio_jump_to_bootloader(hid_device *handle) {
    return bdio_send_packet(handle, 0xFF, 0x00, 0x00);
}

int bdio_set_lights(hid_device *handle, unsigned char *mask, unsigned int size) {
    return bdio_send_packet(handle, 0x02, mask, size);
}

int bdio_turn_on_lights(hid_device *handle, unsigned char *mask, unsigned int size) {
    return bdio_send_packet(handle, 0x03, mask, size);
}

int bdio_turn_off_lights(hid_device *handle, unsigned char *mask, unsigned int size) {
    return bdio_send_packet(handle, 0x04, mask, size);
}

int bdio_init() {
    return hid_init();
}

int bdio_exit() {
    return hid_exit();
}

hid_device *bdio_open_device() {
    hid_device *handle = NULL;
    hid_device_info *devs, *cur_dev;

    devs = hid_enumerate(BLUEDOT_VID, BLUEDOT_PID);
    cur_dev = devs;
    while(cur_dev) {
        if(cur_dev->interface_number == 0) {
            handle = hid_open_path(cur_dev->path);
            break;
        }
        cur_dev = cur_dev->next;        
    }
    hid_free_enumeration(devs);

    return handle;
}

void bdio_close_device(hid_device *handle) {
    hid_close(handle);
}
