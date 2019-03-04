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
		return notify_fail("�㲻�ܰ� guest �� okip!!\n");

	if( !str ) {
		if(!me->query("ok_ip"))
 			tell_object(me, "�㻹û�� ok-ip.\n");
 		else
			tell_object(me, "��� ok-ip �����趨Ϊ :\n"+"  "+
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
		write(pname+" �� OK-IP �����趨Ϊ :\n"+
			"  "+act_ob->query("ok_ip")+"\n");
	else
		write("OK-IP �����趨Ϊ :\n"+"  "+act_ob->query("ok_ip")+"\n");
	act_ob->save_data();
	if( link ) link->clean_up();
	return 1;
}

int help()
{
	write(@C_HELP

ʹ�ø�ʽ: okip [-a|-d|-s] [IP:IP:...]

    ��ָ����������趨���Լ��� okip LIST��ֻ�д���Щ IP address ������
�����˲���ʹ��������� ��

����˵��: a - ���ӡ�d - ɾ����s - �����趨��

    IP ��ʽ��Ϊ 140.113.23.32 �� 140* �� *23 �� cis* �� *pc �ȡ�
������ʹ��"?"�����޸����κβ������ᴫ�����е� okip list��
�� IP = now ����ΪĿǰ�� login IP��

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
