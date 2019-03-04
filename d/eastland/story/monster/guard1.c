#include "../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "wing guard", "����������" );
	add( "id", ({ "guard" }) );
	set_short( "����������" );
	set_long(@C_LONG
�������������𱣻���������İ�ȫ���ڻ�Ҫ�ط����������ټ�������λǿ��սʿ
�����������������Ļ�顣��������嶼�Ǻ�������С�Ĺ�����������������
һ�۵�ӡ���ǿ�����������Ȼ���������������������൱�����ġ�
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 100 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 23 );
        set_perm_stat( "kar", 35 );
        set_skill( "parry", 50 );
        set_skill( "anatomlogy", 50 );
        set_skill( "dodge", 50 );
        set_skill( "dagger", 60 );
        set("max_hp", 500);
        set("hit_points",500);
        set("aiming_loc","weakest");
        set("special_defense", ([ "all":30, "none":20]) );
        set("aim_difficulty",
           ([ "vascular":50, "weakest":20 ]) );
        set_natural_armor(40,14);
        set_natural_weapon( 33,10,10);
        wield_weapon(SWEA"dagger1");
        equip_armor(SARM"imp_armband");
        equip_armor(SARM"imp_leggings");
        equip_armor(SARM"imp_plate");
}
