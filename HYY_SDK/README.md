# HYY_SDK
**HYYRobotX64GRIP**

可执行文件一定要**root启动**

## 一、编译
把src目录下的cpp文件，进行编译产生可执行文件HYYRobotMain，运行的是main.cpp中的内容。
```
《方法一》
cd build
cmake ..
make
```
```
《方法二》
按下F5  //我配置了.vscode目录下的launch.json和tasks.json配置文件，可以进行debug
```
如何编写可执行sh脚本
```
xxx.sh 和 HYYRobotMain可执行文件，都需要进行 chmod +x （文件名）的操作
添加权限
```

## 二、运行
```
cd build
su
./HYYRobotMain --path /home/robot/Work/system/robot_config
```

## 三、硬件报错
### 1.某个电机无法运动
```
在使用示教器时，某个关节无法运动调节
```
**解决办法**：1）下电重启；2）用Elmo，对那个出问题的电机进行整定；

### 2.代码实现机器人回零，出现问题，关节不往零点运动
```
电机编码器 —— 增量式
输出端编码器 —— 绝对式
两个编码器，其中任意一个的错误方向，都会导致程序发生错误
```
**解决办法**：
```
电机编码器：更改DeviceConfig.yaml文件中的 direction 参数值（true / false）

正方向，根据dh建模，通过右手定则确定；配合示教器去验证
```
```
输出端编码器：更改DeviceConfig.yaml文件中的 direction2 参数值（true / false）

正方向，确定完电机编码器的正确方向之后，用代码去验证，知道可以实现代码的正确效果
```

## 四、软件报错
### 1.version版本没对应上，报错如下
```
load_configure_data: XXX version mismatch

XXX可以替换为BusConfig / DeviceConfig / ExternalDeviceConfig / GlobalConfig
```
**解决办法**：检查/home/robot/Work/system/robot_config目录下的yaml配置文件，开头4行参数；

### 2.busdata配置问题，报错如下
```
libcyaml: ERROR: Load: Unexpected key: ethercat_pdo
libcyaml: ERROR: Load: Backtrace:
libcyaml: ERROR: in mapping:
libcyaml: ERROR: in mapping field: busdata
load_configure_data: load_bus_config failure
```
**解决办法**：/home/robot/Work/system/robot_config目录下的BusConfig.yaml中，第10行，将ethercat_pdo改成bus_pdo；

### 3.robot_config的版本过老，显示找不到文件，报错如下
```
cannot open ....
cannot parse file ...
显示找不到robot_config中的xxx.POINT文件
```
**解决办法**：更换新版本的robot_config库进行替换，直接复制粘贴即可，不用重新编译；

### 4.eni.yaml报错，报错如下
```
I/O warning : failed to load external entity "/.../eni.xml"
```
**解决办法**：找到电脑中的eni.yaml文件的所在路径，然后填写到robot_config中的BusConfig.yaml中的device_description处；

### 5.重复启动
```
start teach server port 6666
TCPConcurrentServer: bind failure!
TeachServer: TCPConcurrentServer failure
start teach command server port 6667
TCPConcurrentServer: bind failure!
TeachServer: TCPConcurrentServer failure
start teach feedback server port 6668
TCPConcurrentServer: bind failure!
TeachServer: TCPConcurrentServer failure
```
**解决办法**：pkill一下，杀死一下RobotMain / HYYRobotMain / ...

### 6.关节使能失败
```
axis 1 is poweroff failure!
poweroff timeout-->poweroff failure!
axis 2 is poweroff failure!
poweroff timeout-->poweroff failure!
axis 3 is poweroff failure!
poweroff timeout-->poweroff failure!
axis 4 is poweroff failure!
poweroff timeout-->poweroff failure!
axis 5 is poweroff failure!
poweroff timeout-->poweroff failure!
axis 6 is poweroff failure!
poweroff timeout-->poweroff failure!
axis 7 is poweroff failure!
```
**解决办法**：1）机械臂下电，重启ethercat通讯，用示教器测试是否可以正常使能；2）检查是否上电，急停开关是否释放；

### 7.关节存在运动错误信息
```
robot_enable_i: robot <0> state wrong(err=-176), can't enable
```
**解决办法**：1）示教器windows上位机，进行“清楚运动错误”操作；2）下电，重启；

### 8.没使能
```
movej: robot not power, can't run
```
**解决办法**：用代码使能，具体函数在MovePlan.h
