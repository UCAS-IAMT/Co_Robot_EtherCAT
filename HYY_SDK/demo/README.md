# 常用指令

1. ethercat通讯
```
cd /home/robot/Work/EtherCAT/acontis/master
su            //pwd = robot
（启动命令）./runECM.sh

（停止命令）./stopECM.sh
```

2. 示教器启动
```
cd /home/robot/Work/system
su
（启动命令）./runrobot.sh

（停止命令）./stoprobot.sh
```

3. c++二次开发，可执行文件启动
```
cd /home/robot
su
chmod +x HYYRobotMain

（启动命令）./runrobot.sh

或者

（启动命令）./HYYRobotMain --path /home/robot/Work/system/robot_config
```

4. 杀死线程
```
(停止通信，记得也断电重启一下) pkill EtherCATMaster
(终止示教程序的运行) pkill RobotMain
(终止c++可执行文件) pkill HYYRobotMain
```
