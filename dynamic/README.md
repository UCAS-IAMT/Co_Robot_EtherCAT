# 动力学参数辨识

如果遇到辨识失败的情况，尝试清楚报错/重新上电/重启通讯
```
在进行动力学参数辨识之前，把机械臂移动到竖直零位位置
```
**先进行零点标定和传感器标定**

正常启动的终端内容：https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/dynamic/dy.txt

效果最好的一次：https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/dynamic/1.txt
```
点完“数据采集”，正常情况下，机械臂会进行10分钟左右的激励轨迹运动过程。
等机械臂完成整个运动之后，再点击“模型辨识”。

机械臂上电后，执行以下步骤
```
![](https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/dynamic/11.jpg)
![](https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/dynamic/22.jpg)
