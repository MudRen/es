#include <mudlib.h>

inherit DAEMON;

int cmd_aid(string arg)
{
	object dest;
	int hp, max_hp, skill, chinese_mode;

	chinese_mode = can_read_chinese();
	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail( "��Ҫ��˭ʩ�м��ȣ�\n");

	if( !living(dest) ) return notify_fail("�Ǹ�������������Ҫ���ȡ�\n");

//	if( dest==this_player() ) return notify_fail( chinese_mode?
//		"�㲻�ܶ��Լ�ʩ�м��ȡ�\n": "You can't aid yourself.\n" );

	if( dest->query("ghost") ) return notify_fail(
		"̫���� .... "+dest->query("c_name")+"�Ѿ����ˡ�\n");

	if( dest->query_temp("aided") ) return notify_fail(
		dest->query("c_name") + "�Ѿ������ȹ��ˡ�\n");

	hp = (int)dest->query( "hit_points" );
	max_hp = (int)dest->query( "max_hp" );
	if( hp==max_hp ) return notify_fail(
		dest->query("c_name") + "��û�����ˡ�\n" );

	if( hp > max_hp/6 ) return notify_fail(
		dest->query("c_name") + "�����ƻ�û�����ص���Ҫ���ȵĵز���\n" );

	skill = (int)this_player()->query_skill( "first-aid");
	if( !skill ) return notify_fail("�㲢û��ѧ�����ȵļ��ܡ�\n");

	write("���" + dest->query("c_name") + "���м��� ....\n");
	tell_object( dest, this_player()->query("c_name") + "������м��� .... ����úö��ˣ�\n");
	tell_room( environment(this_player()), this_player()->query("c_name") + "��" + dest->query("c_name") + "���м��� ....\n",
		({ this_player(), dest }) );
	if( dest!=this_player() ) this_player()->add( "alignment", 25 );
	dest->receive_healing( skill/2 + random(skill/2) );
	dest->set_temp( "aided", 1 );
	this_player()->receive_experience( skill );
	call_out( "remove_aided", 300, dest );
    return 1;
}

void remove_aided(object player)
{
	if( player ) player->set_temp("aided", 0);
}

int help()
{
    write(can_read_chinese()?
    @C_HELP
ָ���ʽ: aid <ĳ��>

���ָ�������ĳ������( �� NPC )ʩ�м��ȣ��йؼ��ȵ�ϸ�����������
�� help first-aid��
C_HELP
    :@HELP
Usage: aid <someone>

This command enables you to perform first aid to another player or
NPC. For more information about first aid, see help first_aid.
HELP
	);
    return 1;
}
