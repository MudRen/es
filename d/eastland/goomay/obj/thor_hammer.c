#include <../goomay.h>

inherit Weapon_special;

void create()
{
	set_name( "Thunder's hammer", "����֮��" );
	add( "id", ({ "hammer" }) );
	set_short( "����֮��" );
	set_long(
		"����һ�ѽ�ɫ�ľ޴�����˵���Է���������һ����������\n"
	);
	set( "unit", "��" );
	set( "weight", 250 );
	setup_weapon( "blunt", 45, 25, 45 );
	set( "value", ({ 220, "gold" }) );
        set("no_sale",1);
        set("nosecond",1);
	set("special_attack",(["damage_type" : "electric","main_damage" : 25,
                                "random_damage" : 20 , "hit_rate" : 20]));
//        set("hit_func","special_attack");

set("c_msg","�������֮������¡����һ�����죬����һ����⣬������˵����塣\n\n");
set("c_enemy_msg","������֮������¡����һ�����죬����һ����⣬�����ĺ���� !! \n\n");
set("c_fail_msg","�������֮������¡��һ�����췢��һ����⣬ȴ�䵽���Լ� ! \n\n");
set("c_fail_room_msg","������֮������¡��һ�����췢��һ����⣬ȴ�䵽���Լ� !\n\n");

}

int fail_to_use()
{
        object ob;
        if ( !(ob = present("thunder's gloves", environment(this_object()) )) ||
                            !(ob->query("equipped")) )
	return 1;
	if ( environment()->query_perm_skill("blunt")<95) return 1;
	return 0;
}

