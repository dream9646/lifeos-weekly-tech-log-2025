20251203 - 完成最基本GPIO sysfs架構,因實際系統不支援sysfs故使用tmp模擬,還需要補上流程圖以及函數化優化
# W1 - GPIO sysfs (Skill Day)

## 1. Skills I learned
- export / direction / value
- sysfs driver path
- user space → kernel → hardware
- minimal C workflow

## 2. ASCII diagram
(放你記得的流程圖)

## 3. Test plan (實作結果未來補)
- echo 27 > export
- echo out > direction
- echo 1 > value
- echo 0 > value

## 4. Pseudocode
1.Write gpio index to /sys/class/gpio/export for create GPIOsysfs
2.Write gpio direction (Out/In) to /sys/class/gpio/gpio"index"/direction for confirm how GPIOsysfs do
3.Write gpio value (0/1) to /sys/class/gpio/gpio"index"/value for make GPIOsysfs work
4.Read gpio value (0/1) with /sys/class/gpio/gpio"index" for confirm data
5.Write gpio index to /sys/class/gpio/unexport for close GPIOsysfs