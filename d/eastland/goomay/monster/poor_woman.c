#include <../goomay.h>

inherit Mob_special;

void create()
{
	::create();
	set_level(5);
	set_name("woman", "ϴ�¸�");
	set_short("ϴ�¸�");
	set_long(
		"���Ů�˳���˫�š���ͷ���棬�������ھ���ϴ�·���\n"
	);
	set_skill( "dodge", 50 );
	set_perm_stat("dex",10);
        set_perm_stat("str",10);
        set( "natural_armor_class", 25 );
        set( "natural_weapon_class1", 6 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 14 );
	set( "alignment", 150 );
	set( "wealth/silver", 10 );
	set( "gender", "female" );
	set( "race", "halfling" );
        set("special_attack",(["damage_type" : "none","main_damage" : 10,
                                "random_dam" : 5 , "hit_rate" : 20]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "��Ů�˻ӳ����·����ĵ�һ�����صĴ��������ϣ���е�һ���ʹ..\n\n");
set("c_room_msg","��Ů�˻ӳ����·�����");
set("c_room_msg2", "�����ͷת�� ...\n");

}
