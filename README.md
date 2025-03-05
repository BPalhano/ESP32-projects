# ESP32-projects


To run the project, it is need the ESP-IDF installed and builded in your machine, for installating, follow the steps:

## For Ubuntu

1. update the machines
```
sudo apt update
sudo apt upgrade
```

2. Installing all dependeces
```
sudo apt-get install -y \
    git \
    wget \
    flex \
    bison \
    gperf \
    python3 \
    python3-pip \
    python3-setuptools \
    cmake \
    ninja-build \
    ccache \
    libffi-dev \
    libssl-dev \
    dfu-util
```

3. Generate a dependence for ESP-IDF at home
open a new terminal and type

```
mkdir -p ~/esp
cd ~/esp
git clone --recursive https://github.com/espressif/esp-idf.git
```

4. Setup the ESP-IDF compiler

```
cd esp-idf
git checkout v5.0
git submodule update --init --recursive
```


