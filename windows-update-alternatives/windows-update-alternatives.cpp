// windows-update-alternatives.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 首先设置环境变量到某个链接路径(希望可以在install中实现)
// 要有一个配置文件，里面标清注册了那些应用，目前是什么版本，一共有那些版本
// 运行文件，接收命令行参数和原版工具一致，有初始注册组件(install)，删除组件(remove)和配置组件(config)功能

// 尽可能的还原原版
#include "pch.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

bool menu(string argv1);	//菜单
void help();				//打印--help
bool set(string app, string path);	//执行--set

/**
 * @title main
 * @author ['ssssdl']
 * @dev 主函数，接收命令行参数，提交给menu处理分支
 * @param argc 命令行参数个数
 * @param argv 命令行参数内容
 * @return 0
 */
int main(int argc, char* argv[])
{
	cout << argc << endl;  //参数个数
	menu(argv); //除了执行文件的第一个参数 --help
    cout << "Hello World!\n"; 
	return 0;
}

/**
 * @title menu
 * @author ['ssssdl']
 * @dev 菜单函数，处理命令行参数交给相关模块处理  //这里面应该是两个命令行参数都需要传过来
 * @param argv1 命令行参数内容
 * @return bool 返回是否成功
 */
bool menu(char* argv[]) {
	//本来想switch 太菜了  秀不起来
	if (argv[1] == "--install" || argv[1] == "-i") {
		cout << "注册组件" << endl;
		return true;
	}
	else if(argv[1] == "--remove" || argv[1] == "-r") {
		cout << "删除已经注册的组件" << endl;
		return true;
	}
	else if (argv[1] == "--config" || argv[1] == "-c") {
		cout << "删除已经注册的组件" << endl;
		return true;
	}
	else if (argv[1] == "--set" || argv[1] == "-s") {
		//update-alternatives --set python /usr/bin/python3.6
		cout << "直接设置路径" << endl;
		return true;
	}
	else if (argv[1] == "--help" || argv[1] == "-h") {
		help();
		return true;
	}
	return false;
}

/**
 * @title help
 * @author ['ssssdl']
 * @dev 处理--help||-h，打印help
 * @param null
 * @return void
 */

void help() {
	cout << "windows-update-alternatives --set python D:\python27 \t 直接设置路径python路径为D:\python27" << endl;
}

/**
 * @title set
 * @author ['ssssdl']
 * @dev 处理--set||-s
 * @param app 要设置路径的app
 * @param path 要设置的路径
 * @return bool 返回是否成功
 */
bool set(string app, string path) {
	// 先查询app是否注册，没注册的话注册（设置环境变量，默认软连接到程序目录，建立软连接，添加记录，设置优先级默认10）--to do
	// 已经注册的app，查询软连接到的地址，删除改地址重新创建 --doing
	// 例子：
	string appName = app;	//php
	//利用appname查询appFromPath，假设结果如下
	string appFromPath = "D:\\wamp64\\bin\\php\\php";  //比如查询结果是D:\wamp64\bin\php\php
	string appToPath = path;	//新设置的路径
	system(("rmdir " + appFromPath).c_str());
	system(("mklink / D " + appFromPath + " " + appToPath).c_str());
	return false;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
