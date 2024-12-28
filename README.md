# Linux Keylogger

## Description
A Linux keylogger implemented in both Python and C++ to capture keystrokes from the `/dev/input` system. This project demonstrates low-level input handling using the `evdev` library and explores the interaction between userspace programs and the Linux kernel.

---

## Features
- Captures keystrokes from input devices.
- Logs keystrokes to a file.
- Python implementation for simplicity and prototyping.
- C++ implementation for high performance and embedded systems.

---

## Requirements
### Python Version
- Python 3.6+
- `evdev` library

### C++ Version
- GCC or compatible compiler
- `libevdev` library

---

## Installation

### Clone the Repository
```bash
git clone https://github.com/v8v88v8v88/linux-keylogger.git
cd linux-keylogger
```

### Install Dependencies
#### Python Dependencies
```bash
pip install -r requirements.txt
```

#### C++ Dependencies (Fedora)
```bash
sudo dnf install libevdev-devel
```

---

## Usage

### Python Keylogger
1. Run the Python implementation:
   ```bash
   sudo python3 python/linux_keylogger.py
   ```

2. Logs will be saved to `keylog.txt`.

### C++ Keylogger
1. Compile the C++ implementation:
   ```bash
   g++ cpp/linux_keylogger.cpp -o linux_keylogger -I/usr/include/libevdev-1.0 -levdev
   ```

2. Run the compiled program:
   ```bash
   sudo ./linux_keylogger
   ```

3. Logs will be saved to `keylog.txt`.

---

## Known Issues
- Python version may be slower compared to the C++ version.
- Requires elevated privileges (`sudo`) to access `/dev/input` devices.

---

## Future Enhancements
- Improve log file management.
- Add real-time keystroke monitoring.
- Enhance error handling.

---

## License
This project is for **educational purposes only**. Use responsibly and ensure compliance with all applicable laws and regulations.

---

## Contributing
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Submit a pull request.

---

## Author
[Vaibhav](https://github.com/v8v88v8v88)

