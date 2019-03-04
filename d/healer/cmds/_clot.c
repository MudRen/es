//#pragma save_binary
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
		return notify_fail( "��Ҫ��˭ֹѪ��\n" ); 

	if( !living(dest) ) return notify_fail( "�Ǹ���������������Ѫ��\n" );

	if( dest->query("ghost") ) return notify_fail( 
		sprintf("̫���� .... %s�Ѿ����ˡ�\n" ,dest->query("c_name")));
        
        if( dest->query("no_clot") ) return notify_fail(
                sprintf("%sЦ������˵:лл��ĺ���, ���������б�Ҫʱ, ���Լ����ֿ��ܱȽϺá�\n",dest->query("c_name") )
           );     
        
	if( dest->query_temp("clotted") ) return notify_fail( 
		 sprintf("%s���˿��Ѿ�ֹѪ������ˡ�\n" ,dest->query("c_name")));

	if( !(bleed = dest->query("conditions/bleeding")) )
		return notify_fail( 
			sprintf("%s��û��ʧѪ�����Ρ�\n" ,dest->query("c_name")));

	skill = (int)this_player()->query_skill( "clotting");
	if( !skill ) return notify_fail( "�㲢û��ѧ��ֹѪ�ļ��ܡ�\n" );

	write( sprintf("����%s���˿ڽ���ֹѪ ....\n" ,dest->query("c_name")));
        if (dest !=this_player())
	tell_object( dest, 
		sprintf("%s������˿�ֹѪ .... ����úö��ˣ�\n" ,this_player()->query("c_name")));
	tell_room( environment(this_player()), 
		sprintf("%s��%s���˿�ֹѪ��\n",
			this_player()->query("c_name"),dest->query("c_name")),
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
    write(
    @C_HELP
ָ���ʽ: clot <ĳ��>

���ָ��������ĳ������( �� NPC )���˿�ֹѪ���й�ֹѪ��ϸ�����������
�� help clotting��
C_HELP
	);
    return 1;
}
