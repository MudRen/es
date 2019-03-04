#include "../legend.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name("occult eye", "����֮��");
	add("id",({"eye","beholder"}));
	set_short("����֮��");
	set_long(
	    "���ص����壬��ħ�������Ĵ�����ǰ�ɹ���\n"
	);
	set( "unit", "ֻ" );
	set_perm_stat("int",30);
	set_natural_weapon( 55, 23, 27 );
	set_natural_armor( 60, 1 );
	set("max_hp",500);
        set("hit_points",500);
	set( "tactic_func", "magic_attack" );
	set("special_defense",(["all":100, "none":50]) );
	set_c_limbs( ({ "ͷ��", "�۾�" }) );
	set_c_verbs( ({ "%s�������۾�����%s","%s���һ������ɨ��%s" }) );
        equip_armor(LARMOR"globe1");
}

int magic_attack()
{
	object victim;

	if( !(victim=query_attacker()) || random(10)<4 ) return 0;
	tell_room( environment(this_object()), 
    sprintf("����֮�����������۾�����һ�������İ׹⣬ֱ��%s��ȥ��\n",
    victim->query("c_name")));
	victim->receive_special_damage("magic",30+random(20));	
	return 1;
}
