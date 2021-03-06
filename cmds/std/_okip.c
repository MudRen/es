//#pragma save_binary

// _okip.c
// Used to change another player's okip ( only admin ) or himself's okip.

#include <uid.h>
#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int help();

int cmd_okip(string str)
{
	object act_ob, me, link;
	string flag, *ip_list, pname, strip, *ips;
	int i;

	me = this_player();
	if( (string)me->query("name") == "guest" )
		return notify_fail("你不能帮 guest 设 okip!!\n");

	if( !str ) {
		if(!me->query("ok_ip"))
 			tell_object(me, "你还没设 ok-ip.\n");
 		else
			tell_object(me, "你的 ok-ip 现在设定为 :\n"+"  "+
 				(string)me->query("ok_ip")+"\n" );
 		return 1;
	}

	if( sscanf(str,"-%s %s %s", flag, pname, strip) != 3 &&
		sscanf(str,"-%s %s", flag, strip) != 2 )
		return help();

	// if target is not me && I am a admin && target is not an admin.
	if( pname && member_group(getuid(me), "admin") &&
		!member_group(pname, "admin") ) {
		link = FINGER_D->restore_data(pname);
		if( !link ) return notify_fail("No such user.\n");
		act_ob = link->query("body_ob");
		if( !act_ob ) {
			link->restore_body();
			act_ob = link->query("body_ob");
		}
	} else act_ob = me;

	if( act_ob->query("ok_ip") )
		ip_list=explode((string)act_ob->query("ok_ip"),":");
	else ip_list = ({});

	if( strip == "now" )
		ips = ({ (string)me->query("ip") });
	else if( strip )
		ips = explode(strip,":");

	if( flag == "s" )
		ip_list = ips;
	else if( flag == "a" ) {
 		for( i=0; i<sizeof(ips); i++ )
 			if( member_array(ips[i], ip_list) == -1 )
 				ip_list += ({ ips[i] });
	} else if( flag == "d" ) {
 		for( i=0; i<sizeof(ips); i++ )
 			if( member_array(ips[i], ip_list) != -1 )
				ip_list -= ({ ips[i] });
	} else return notify_fail("Wrong flag!\n");

	act_ob->set("ok_ip", implode(ip_list,":"));
	if( pname )
		write(pname+" 的 OK-IP 现在设定为 :\n"+
			"  "+act_ob->query("ok_ip")+"\n");
	else
		write("OK-IP 现在设定为 :\n"+"  "+act_ob->query("ok_ip")+"\n");
	act_ob->save_data();
	if( link ) link->clean_up();
	return 1;
}

int help()
{
	write(@C_HELP

使用格式: okip [-a|-d|-s] [IP:IP:...]

    这指令可以用来设定你自己的 okip LIST，只有从这些 IP address 上连过
来的人才能使用这个人物 。

参数说明: a - 增加、d - 删除、s - 重新设定。

    IP 格式可为 140.113.23.32 或 140* 或 *23 或 cis* 或 *pc 等。
但请勿使用"?"。若无给予任何参数将会传回现有的 okip list。
若 IP = now 则视为目前的 login IP。

C_HELP
	);

	if( member_group(geteuid(this_player()), "admin") )
		write( @ADMIN_HELP

  For Admin, usage can be: okip [-a|-d|-s] [player] <IP:IP....> If you
want change player's okip.
ADMIN_HELP
		);
    return 1;
}
