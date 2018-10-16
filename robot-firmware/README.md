# Firmware

Firmware for Lego Mindstorms EV3 (TBA)

## Docker Setup

If you are cross-compiling with Docker you need to install it first:

```bash
docker pull ev3dev/debian-jessie-cross
docker tag ev3dev/debian-jessie-cross ev3cc
```

Then to enter the vm run:
```bash
docker run --rm -it -v $(pwd):/src -w /src ev3cc
```

## Compiling

```bash
mkdir build
cd build
cmake ..
make
```
