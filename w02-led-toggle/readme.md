# W2 - LED Toggle (Skill Day)
LED toggle = GPIO sysfs + Time
## 1. Skills I learned
- LED = GPIO output device
- Toggle = write 1/0 with delay
- Basic loop control in C

## 2. Flow diagram
![LED toggle flow](./led-toggle-flow.png)

## 3. Test plan
- echo N > export
- echo out > direction
- repeat:
  - echo 1 > value
  - sleep 0.1
  - echo 0 > value
  - sleep 0.1

## 4. Pseudocode
1. export gpio
2. set direction = out
3. for i in 0..count-1:
   - write 1
   - delay
   - write 0
   - delay
4. unexport gpio
+---------------------------+
|           Start           |
+---------------------------+
              |
              v
+---------------------------+
|  Input: gpio, count, ms   |
+---------------------------+
              |
              v
+---------------------------+
|   Write gpio -> export    |
+---------------------------+
              |
              v
+---------------------------+
|  Write "out" -> direction |
+---------------------------+
              |
              v
+---------------------------+
|       Toggle loop         |
|  i = 0 .. count-1         |
+---------------------------+
              |
   +----------+----------+
   |                     |
   v                     |
+-------------------+    |
| Write "1"->value  |    |
+-------------------+    |
              |          |
              v          |
+-------------------+    |
|   Delay (ms)      |    |
+-------------------+    |
              |          |
              v          |
+-------------------+    |
| Write "0"->value  |    |
+-------------------+    |
              |          |
              v          |
+-------------------+    |
|   Delay (ms)      |    |
+-------------------+    |
              |          |
              +----------+
              |
              v
+---------------------------+
|  Write gpio -> unexport   |
+---------------------------+
              |
              v
+---------------------------+
|            End            |
+---------------------------+