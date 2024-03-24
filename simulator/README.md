# 示教器使用
网线：一端插入Ubuntu电脑的网口3；另一端插入笔记本电脑的网口。

## 1. Ubuntu16.04
**pwd** = robot

终端1
```
su
pkill EtherCATMaster
pkill RobotMain
```

终端2
```
cd /home/robot/Work/EtherCAT/acontis/master
su           
./runECM.sh
```

终端3
```
cd /home/robot/Work/system
su
./runrobot.sh
```

显示如下：
<div align="center">
<table>
<tr>
<td>

![](https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/images/simulator_1.jpg)  

</td>
</tr>
</table>
</div>

## 2. Windows
### 2-1 配置网络连接，设置静态ip
[参考链接-CSDN](https://blog.csdn.net/qq_68613861/article/details/134030902?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171127580416800188587141%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=171127580416800188587141&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-134030902-null-null.142^v99^pc_search_result_base5&utm_term=windows%E9%9D%99%E6%80%81ip%E8%AE%BE%E7%BD%AE&spm=1018.2226.3001.4187)
```
Ubuntu电脑的网口3，静态ip是 192.168.0.99 ；所以笔记本电脑的网线接口静态ip设成192.168.0.XX ，最后XX不要和99重复。
```
![](https://github.com/UCAS-IAMT/Co_Robot_EtherCAT/blob/main/images/simulator_2-1.jpg)
```
！！！参考CSDN链接，重启网卡；先禁用，再启用。
```




