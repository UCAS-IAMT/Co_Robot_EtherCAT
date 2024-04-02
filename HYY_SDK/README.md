# HYY_SDK
**HYYRobotX64GRIP**


## 编译
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

## 运行
```
cd build
su
./HYYRobotMain --path /home/robot/Work/system/robot_config
```

## 遇到的问题
### 1.version版本没对应上，报错如下
```
load_configure_data: XXX version mismatch

XXX可以替换为BusConfig / DeviceConfig / ExternalDeviceConfig / GlobalConfig
```
**解决办法**：检查/home/robot/Work/system/robot_config目录下的yaml配置文件，开头4行参数

### 2.busdata配置问题，报错如下
```
libcyaml: ERROR: Load: Unexpected key: ethercat_pdo
libcyaml: ERROR: Load: Backtrace:
libcyaml: ERROR: in mapping:
libcyaml: ERROR: in mapping field: busdata
load_configure_data: load_bus_config failure
```
**解决办法**：/home/robot/Work/system/robot_config目录下的BusConfig.yaml中，第10行，将ethercat_pdo改成bus_pdo

### 3.robot_config的版本过老，显示找不到文件，报错如下
```
cannot open ....
cannot parse file ...
显示找不到robot_config中的xxx.POINT文件
```
**解决办法**：更换新版本的robot_config库进行替换，直接复制粘贴即可，不用重新编译

### 4.eni.yaml报错，报错如下
```
I/O warning : failed to load external entity "/.../eni.xml"
```
**解决办法**：找到电脑中的eni.yaml文件的所在路径，然后填写到robot_config中的BusConfig.yaml中的device_description处
