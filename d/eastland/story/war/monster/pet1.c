#include "../../story.h"
#include <conditions.h>
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(13);
	set_name( "Troll beast", "������" );
	add( "id", ({ "beast" }) );
	set_short( "������" );
	set_long(@LONG
һֻ��������ľ�����Ұ�ޣ������˳��õ�ѵ�������к�ǿ�Ĺ�������
LONG
	);
	set( "unit", "ֻ" );
	set( "race","����");
	set( "alignment", -100 );
	set_natural_armor(60,15);
	set_natural_weapon(40,8,20);
	set( "killer", 1 );
        set( "pursing", 1 );
        set( "war_points", 50 );
	set_skill( "unarmed-parry", 60 );
        set_skill( "unarm", 100 );
        set_c_verbs( ({
             "%s�ſ�������%sҧȥ",
             "%s�Ӷ���צץ��%s"}) );
        set_c_limbs( ({ "ͷ��", "����", "��" }) );
        set("tactic_func","my_tactic");
}
int my_tactic()
{
     object victim;
     string name;
     if ( !victim=query_attacker() ) return 0;
     if ( random(10) > 1 ) return 0;
     name=victim->query("c_name");
     tell_room(environment(),sprintf("�������ſ�������%s����һҧ��\n",name),victim);
     tell_object(victim,"�������ſ�������������һҧ��\n\n");
     (CONDITION_PREFIX + "simple_poison")->apply_effect(victim,5,5);
     return 1;
}
