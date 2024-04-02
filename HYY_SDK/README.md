# HYY_SDK
**HYYRobotX64GRIP**


## 编译
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

## launch

co_robot_urdf.launch ：co_robot.urdf + 7个joint的position_controller；
co_robot_urdf_environment.launch ：co_robot_environment.urdf.xacro + 7个joint的position_controller；
