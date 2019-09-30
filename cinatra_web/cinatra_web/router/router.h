#pragma once
#ifndef _SERVER_ROUTER_H_
#define _SERVER_ROUTER_H_

///////////////////// 2019/06/21 17:53:30 用户服务器 ==> BEGIN /////////////////////////////////////////////////////
#define USER_SERVER_LOGIN		    "/login"		                /*\ 登录路由 \*/
#define USER_SERVER_WXLOGIN		    "/wx_login"		                /*\ 微信登录 \*/
#define USER_SERVER_QQLOGIN		    "/qq_login"		                /*\ qq登录 \*/
#define USER_SERVER_PHONELOGIN	    "/phone_login"	                /*\ 手机号登陆 \*/
#define USER_SERVER_MANAGELOGIN		"/manage_login"					/*\ 后台管理登录 \*/
#define USER_SERVER_REGIST		    "/regist"		                /*\ 注册路由 \*/
///////////////////// 2019/06/21 17:53:30 用户服务器 ==> END /////////////////////////////////////////////////////

///////////////////// 2019/06/21 17:53:44 后台管理服务器 ==> BEGIN /////////////////////////////////////////////////////
#define MANAGE_SERVER_USERINFO		"/select_userinfo"			    /*\ 测试路由 \*/
///////////////////// 2019/06/21 17:53:44 后台管理服务器 ==> END /////////////////////////////////////////////////

#endif