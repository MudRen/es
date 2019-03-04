#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit DAEMON;

int cmd_clot(string arg)
{
	object dest;
	int skill;
	mixed bleed;

	if( !arg || arg=="" || !(dest = present(arg, environment(this_player()))) )
		return notify_fail( "��Ҫ��˭ֹѪ��\n");

	if( !living(dest) ) return notify_fail("�Ǹ���������������Ѫ��\n");

//	if( dest==this_player() ) return notify_fail( chinese_mode?
//		"�㲻�ܶ��Լ�ʩ�м��ȡ�\n": "You can't aid yourself.\n" );

	if( dest->query("ghost") ) return notify_fail( 
		"̫���� .... "+dest->query("c_name")+"�Ѿ����ˡ�\n");

	if( dest->query_temp("clotted") ) return notify_fail(
		dest->query("c_name") + "���˿��Ѿ�ֹѪ������ˡ�\n");

	if( !(bleed = dest->query("conditions/bleeding")) )
		return notify_fail(
			dest->query("c_name") + "��û��ʧѪ�����Ρ�\n");

	skill = (int)this_player()->query_skill( "clotting");
	if( !skill ) return notify_fail("�㲢û��ѧ��ֹѪ�ļ��ܡ�\n");

	write(
		"����" + dest->query("c_name") + "���˿ڽ���ֹѪ ....\n");
	tell_object( dest, 
		this_player()->query("c_name") + "������˿�ֹѪ .... ����úö��ˣ�\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name") + "��" + dest->query("c_name") + "���˿�ֹѪ��\n",
		({ this_player(), dest }) );
	if( dest!=this_player() )
		this_player()->add( "alignment", 25 );
	if( skill/2 + random(skill/2) > bleed[1] * bleed[2] ) {
		this_player()->receive_experience( skill );
		(CONDITION_PREFIX + "bleeding")->remove_effect( dest );
	} else {
		bleed[2] /= 2;
		dest->set( "conditions/bleeding", bleed );
		this_player()->receive_experience( skill/2 );
	}
	dest->set_temp("clotted", 1 );
	call_out( "remove_clotted", 120, dest );
    return 1;
}

void remove_clotted(object player)
{
	if( player ) player->set_temp("clotted", 0);
}

int help()
{
    write(can_read_chinese()?
    @C_HELP
ָ���ʽ: clot <ĳ��>

���ָ��������ĳ������( �� NPC )���˿�ֹѪ���й�ֹѪ��ϸ�����������
�� help clotting��
C_HELP
    :@HELP
Usage: clot <someone>

This command enables you to clot another player or NPC's bleeding wounds.
For more information about clotting, see help clotting.
HELP
	);
    return 1;
}
