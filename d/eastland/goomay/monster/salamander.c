#include "../goomay.h"

inherit Mob_special;

void create()
{
	::create();
	set_level(10);
	set( "unit","ֻ");
	set("killer",1);
	set_name("salamander", "������");
	add( "id", ({ "lizard" }) );
	set_short("������");
	set_long(
		"����һ��ס�ڻ����Ի�Ϊʳ��������Բб�����ʲ�ᶼ�ԡ�\n"
	);
	set_skill( "dodge", 50 );
	set_perm_stat("dex",15);
        set_perm_stat("str",15);
        set( "natural_armor_class", 50 );
        set( "natural_weapon_class1", 17 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
	set( "alignment", -450 );
	set( "wealth/copper", 400 );
        set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
        set("special_attack",(["damage_type" : "fire","main_damage" : 15,
                                "random_dam" : 10 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg","\n���������һ�����ȵĻ𻨣����䡹��һ��ը��������..\n\n");
set("c_room_msg","���������һ��𻨣���");
set("c_room_msg2", "����������ȼ�� ...\n");
}
