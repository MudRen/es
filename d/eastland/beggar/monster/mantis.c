#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "mantis", "���" );
	add( "id",({"mantis"}) );
	set_short( "���" );
	set_long(@C_LONG
һֻ���������׺ݵ�����,������֧������������������ؿ�����,�ƺ�Ҫ��������
����
C_LONG
        );
        set( "unit", "ֻ" );
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
        set("weight",650);
	set_skill( "dodge", 80 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "alignment", -200 );
	set_natural_armor( 25, 10 );
	set_natural_weapon( 40, 18, 20 );
        set( "natural_weapon_class2", 40 );
        set( "natural_min_damage2", 15 );
        set( "natural_max_damage2", 25 );
	set_c_verbs( ({ "%s����֧��������������%s",
                        "%s����ݺݵ�ҧ��%s"      
                    }) );
}
