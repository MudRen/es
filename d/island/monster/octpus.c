
#include "../island.h"
#include <mudlib.h>
#include <stats.h>

inherit ISLAND+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name("octpus", "������");
	add("id",({"octpus"}));
	set_short("������");
	set_long(@LONG
һֻ�����͵����㣬���İ�ֻ���������ϵĻӶ������㻹������
Զ����ˡ�
LONG
	);
	set( "unit", "ֻ" );
	set( "alignment", -250 );
	set("max_hp",600);
	set("likefish",1);
	set("hit_points",600);
	set_perm_stat( "dex", 21 );
	set_perm_stat( "kar",16 );
	set_natural_weapon(45,12,24);
	set_skill( "unarmed" , 55 );
	set_natural_armor(52,15);
	set( "tactic_func", "emit_lick" );
	set_c_limbs( ({ "ͷ��", "����" }) );
	set_c_verbs( ({ "%s�Ӷ����Ĵ�����%s�޴��ȥ" }) );
}

int emit_lick()
{
	object victim;

	if( random(19)>3 || !(victim= query_attacker()) ) return 0;
	else {
	  tell_room( environment(this_object()), 
		  "\n�����������Ĵ��ְ�"+victim->query("c_name")+"��������ס\n\n"
		  );
	  victim->receive_damage(1+random(4));
	  report(victim);	
	  return 1;
      }
}