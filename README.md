# Co_Robot_EtherCAT
七轴25kg协作机械臂EtherCAT通讯控制

### 启动25kg机械臂——实物控制demo (moveit控制)

先确定网线、48v电源线、24v电源线已经插上；ethercat板子冒蓝光（检查每个关节）

#————终端1————
```
cd /home/robot/Work/EtherCAT/acontis/master

su            //pwd = robot

./runECM.sh

（停止命令）./stopECM.sh
```

#————终端2————
```
cd catkin_ws

su            //pwd = robot

roslaunch device_driver device_driver.launch
```

#————终端3————
```
cd catkin_ws

source devel/setup.bash

roslaunch device_driver start_controller.launch controller_name:=joint_trajectory_controller

roslaunch arm25kg_moveit_config demo.launch
```

