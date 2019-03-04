#include <../goomay.h>

inherit Weapon_special;

void create()
{
	set_name( "Sword of snow", "��ѩ��" );
	add( "id", ({ "sword" }) );
	set_short( "��ѩ��" );
	set_long(
		"����һ�����صĶ̽��������ϸ��ֳ�һƬƬ��������ѩ��һ���\n"
		"ӡ�ۣ���Ȼ��ֻ�ǿ���һ�ۣ���Ҳ�ƺ��ܸ��ܵ��ǹ�˿˿���⡣\n"
	);
	set( "unit", "��" );
	set( "weight", 150 );
	setup_weapon( "shortblade", 37, 20, 32 );
	set( "value", ({ 220, "gold" }) );
        set("no_sale",1);

        set("special_attack",(["damage_type" : "cold","main_damage" : 10,
                                "random_damage" : 10 , "hit_rate" : 15]));
//        set("hit_func","special_attack");

set("c_msg","\n��Ĵ�ѩ�����һƬ����ĺ������������˵����塣\n\n");
set("c_enemy_msg","�Ĵ�ѩ�����һƬ����ĺ���������������塣\n\n");
set("c_fail_msg","\n��Ĵ�ѩ�����һƬ����ĺ�����ȴ�������Լ� ! \n\n");
set("c_fail_room_msg","�Ĵ�ѩ�����һƬ����ĺ�����ȴ�������Լ� ! \n\n");
}

int fail_to_use()
{
	object ob;
	if ( !(ob = present("flame shield", environment(this_object()) )) ||
			    !(ob->query("equipped")) )
	       return 1;
	else
	       return 0;
}
