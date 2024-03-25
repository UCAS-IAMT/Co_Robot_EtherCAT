# Co_Robot_EtherCAT——2024.3.24
七轴25kg协作机械臂EtherCAT通讯控制

**系统环境**：Ubuntu16.04 + Ros1-kinetic ；上位机示教器（windows 10测试通过）

**感谢韩冰老师的指导！**

## 1.启动25kg机械臂——实物控制demo (moveit控制)
<div align="center">
<table>
<tr>
<td>

![image](https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/images/1.1.jpg)   

</td>
<td>

![image](https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/images/1.2.jpg)   

</td>
</tr>
</table>
</div>

先确定网线、48v电源线、24v电源线已经插上；ethercat板子冒蓝光（检查每个关节）

————终端1————
```
cd /home/robot/Work/EtherCAT/acontis/master
su            //pwd = robot
（启动命令）./runECM.sh

（停止命令）./stopECM.sh
```

————终端2————
```
cd catkin_ws
su            //pwd = robot
source devel/setup.bash
roslaunch device_driver device_driver.launch （一定要先进入管理员模式）
```

————终端3————
```
cd catkin_ws
source devel/setup.bash
roslaunch device_driver start_controller.launch controller_name:=joint_trajectory_controller
roslaunch arm25kg_moveit_config demo.launch
```

## 2.windows机械臂示教器使用
<div align="center">
<table>
<tr>
<td>

![](https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/images/2.1.jpg)  

</td>
</tr>
</table>
</div>

### 作用
1.机械臂关节解除奇异位置，回零

2.设置初始零位（肉眼标定）

### 启动
双击 ***\HBRobot\HBRobotConfigure.exe

### 使用
详见：https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/tree/main/simulator

## 3.Elmo Application Studio II
<div align="center">
<table>
<tr>
<td>

![](https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/images/m0.jpg)  

</td>
</tr>
</table>
</div>

### 作用
1.清除电机报错

2.整定电机内部PID（当发现机械臂位置控制时，moveit界面和实物偏差很大，建议重新整定一下各个电机）

### 使用
详见：https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/tree/main/Elmo
