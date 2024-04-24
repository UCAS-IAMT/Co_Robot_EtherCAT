#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "HYYRobotInterface.h"
#include "user/BscanServer.h"
//矩阵运算库
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>
// C++头文件
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <time.h>
#include <thread>
#include <mutex>
#include <future>
#include <utility>

extern int test1();

using namespace std;
using namespace std::chrono;
using namespace HYYRobotBase;

// 参数
#define Pi 3.14159265358979323846
double F_sensor_time = 1.0 / 1000.0 * 1000000; //定义时间,单位ms
double cal_times = 200.0; //定义计算频率
double cal_dt = 1.0 / cal_times; //定义计算时间常数
double cal_time = cal_dt * 1000000; //定义计算循环时间,单位ms
int send_times = cal_times / (200.0); //定义发送频率

// 机械臂导纳属性
float M = 5;// 惯量M
float B = 25;// 阻尼B
float K = 10;// 刚度K

// t时刻，(qe = q - qd)xe的d和dd
double qd = 0;
double q = 0;
double reference_q = 0;// 参考q
double current_qe = 0;
double current_qe_dot = 0;
double current_qe_ddot = 0;
// t-1时刻
double last_qe = 0;
double last_qe_dot = 0;
double last_qe_ddot = 0;

// 力矩
short torque = 0;// 实时力矩
short torque_d = 10;// 期望

//计算时间，添加微秒（us）
void timespec_add_us(struct timespec *t, long us)
{
	t->tv_nsec += us * 1000;
	if (t->tv_nsec > 1000000000)
	{
		t->tv_nsec = t->tv_nsec - 1000000000; // + ms*1000000;
		t->tv_sec += 1;
	}
}

int main(int argc, char *argv[])
{	
	//------------------------initialize----------------------------------
	int err=0;
	HYYRobotBase::command_arg arg;
	err=HYYRobotBase::commandLineParser(argc, argv,&arg);
	if (0!=err)
	{
		return -1;
	}
	err=HYYRobotBase::system_initialize(&arg);
	if (0!=err)
	{
		return err;
	}
	//-----------------------user designation codes---------------

	//创建定时器
	RTimer timer;
    initUserTimer(&timer,0,1);//定时周期为1倍总线周期
	
	// 获取索要操作的机器人名称
    const char* robot_name=get_name_robot_device(get_deviceName(0,NULL),0);
    double td=get_control_cycle(get_deviceName(0,NULL));//获取总线周期
	int dof=get_group_dof(robot_name);//获取机器人关节数目
	int i=0;

	// 轴6使能
	group_power_off(robot_name);//机器人所有轴下电
	sleep(1);
	int axis_ID[7]={1,2,3,4,5,6,7};//指定操作单轴id
    axis_power_on(robot_name,axis_ID[5]);//单轴6上电

	qd = GetAxisPosition(robot_name,axis_ID[5]);


	// int loop_times = 1; //循环次数
	// int temp_times = 1;
	// int F_times = 1;
	// auto start = high_resolution_clock::now(); //开始时间戳

	// //记录当前绝对时间
	// struct timespec next;
	// clock_gettime(CLOCK_REALTIME, &next);

	while(robot_ok())//循环，当程序被强制停止或遇到错误时循环退出
    {
		/*
        userTimer(&timer);//定时
        pos_target=A*cos(3.14*2*f*t)-A+pos_base;//设置期望数据
        // 获取当前单轴关节目标位置
        pos_target_1=GetAxisTargetPosition(robot_name,axis_ID[5]);
        pos_real=GetAxisPosition(robot_name,axis_ID[5]);//获取当前单轴关节位置
        SetAxisPosition(robot_name,pos_target,axis_ID[5]);//设置单轴关节目标位置

		torque = GetAxisSensorTorque(robot_name,axis_ID[5]);
        printf("torque_axis[%d]:%hd\n",axis_ID[5],torque);

        t+=td;
		*/

		//循环周期控制
		userTimer(&timer);//定时

		torque = GetAxisSensorTorque(robot_name,axis_ID[5]);
        printf("torque_axis[%d]:%hd\n",axis_ID[5],torque);

		// 更新误差数据
		last_qe = current_qe;
		last_qe_dot = current_qe_dot;

		// admittance 
		current_qe_ddot = (1/M) * (-0.1*torque - B * last_qe_dot - K * last_qe);
		current_qe_dot = last_qe_dot + current_qe_ddot * cal_dt;
		current_qe = last_qe + current_qe_dot * cal_dt;
		reference_q = current_qe + qd;

		double pos_real=GetAxisPosition(robot_name,axis_ID[5]);//获取当前单轴关节位置

		if(pos_real>-2.18 && pos_real<2.18) // 关节限位
		{
			SetAxisPosition(robot_name,reference_q,axis_ID[5]);//设置单轴关节目标位置
		}
    }

	//------------------------wait----------------------------------
	pause();
	return 0;
}
