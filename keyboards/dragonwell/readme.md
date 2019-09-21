# Dragonwell

## Building

```
$ make dragonwell:default:dfu-util
```

## Entering Bootloader

Using the `RESET` kecode, bootmagic, and bootmagic lite to enter the bootloader are not supported for STM32F042xx chips. To enter bootloader, hold BOOT0 while keyboard is powering up or after pressing RESET0 switch (or sending the `RESET` keycode).
