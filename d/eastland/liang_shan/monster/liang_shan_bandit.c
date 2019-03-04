// liang_shan_bandit.c 
#include <mudlib.h>
#define HEADQUARTER "/d/eastland/liang_shan/daemons/army_d"

inherit MONSTER;

void create()
{
	::create();
	HEADQUARTER->add_member();
}

void remove()
{
	HEADQUARTER->remove_member();
	return ::remove();
}

int stop_attack()
{
	HEADQUARTER->add_huntee(this_player());
	return 0;
}

void pseudo_hunt(object me, object player)
{
	if( environment() && present(player, environment()) ) 
		if( this_object()==me )
			tell_room( environment(), 
				query("c_name") + "���������ͼ�����: �ֵ��ǣ��������һ���������ˣ�\n",
				this_object() );
		else {
			tell_room( environment(), 
				query("c_name") + "�嵽����ǰ�����:����Ҫ���ļһ������ɽ��Ұ��ȥ���ɣ���\n",
				this_object() );
			if( !pointerp(attackers) || member_array(player, attackers)==-1 )
				kill_ob(player);
		}
	else if( !pointerp(will_attack) )
		will_attack = ({ player });
	else if( member_array(player, will_attack)==-1 )
		will_attack += ({ player });
}
