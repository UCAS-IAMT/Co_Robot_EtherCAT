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
### 1.version版本没对应上
**解决办法**：检查/home/robot/Work/system/robot_config目录下的yaml配置文件，开头4行参数

### 2.报错如下
```
libcyaml: ERROR: Load: Unexpected key: ethercat_pdo
```
**解决办法**：/home/robot/Work/system/robot_config目录下的BusConfig.yaml中，第10行，将ethercat_pdo改成bus_pdo
