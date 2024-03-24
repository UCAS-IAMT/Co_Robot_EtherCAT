# ros_control_co_robot

## urdf

co_robot.urdf ：最初的建模，去掉两个夹爪；
co_robot_environment.urdf.xacro ：更改了配色，设置了环境，末端重新添加了魔改版kuka力矩传感；

## launch

co_robot_urdf.launch ：co_robot.urdf + 7个joint的position_controller；
co_robot_urdf_environment.launch ：co_robot_environment.urdf.xacro + 7个joint的position_controller；