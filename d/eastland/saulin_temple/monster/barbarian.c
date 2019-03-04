#include "../saulin_temple.h" 

inherit MONSTER;

void create()
{
	object ob1, ob2;

	::create();
	set_level(16);
	set_name( "barbarian fighter", "Ұ����սʿ" );
	add( "id", ({ "fighter" }) );
	set_short( "Ұ����սʿ" );
	set_long(@C_LONG
���Ұ������������߰룬����һ���ʯͷ�������֪��������������ˡ�
����Ұ���˵�ΰ��սʿ��ס�ڶ�������ɽ�С�������˵�����ֵ��书\���� 
�������Ծ���������������
C_LONG
                );
	set_perm_stat( "str", 30 );
	set_perm_stat( "kar", 17 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "int", 14 );
	set_skill( "bo", 80 );

	set_natural_armor( 72, 25 );
	set_natural_weapon( 0, 10, 10 );
	set( "time_to_heal", 2 );

        set("special_defense", ([ "all":30, "none":10, "monk":10 ]) );
	set("aim_difficulty", ([ "critical":25, "vascular":30,
                                  "ganglion":40,"weakest":10, ]) );

	set( "max_hp", 900 );
	set( "hit_points", 900 );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set( "wealth/silver", 720 );
	set( "pursuing", 1 );
        set ("exp_reward", 14000);

	wield_weapon(SAULIN_OBJ"stone_club1");
	equip_armor(SAULIN_OBJ"stone_helmet");
	equip_armor(SAULIN_OBJ"stone_leggings");
}
