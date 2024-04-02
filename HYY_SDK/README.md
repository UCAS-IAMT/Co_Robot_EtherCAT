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
