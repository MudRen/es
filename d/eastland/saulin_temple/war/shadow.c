
#include "saulin_war.h"

inherit War;

void create ()
{

        ::create();
    set_level(10);
    set_name("shadow guardian","Ӱ����");
    add ("id", ({ "guardian","shadow",}) );
    set_short("Ӱ����");
        set_long(@C_LONG
һ��ȫ����µ����ߣ��ƺ���һ�����ڻ�Ӱ�е��ˣ���ֻ֪��һֱ���ĵ��ػ����ˡ�
C_LONG
 );
	set("alignment" , -700 );
	set( "gender", "male" );
	set( "unit", "��" );
        set( "pursuing", 1 );
        set( "killer", 1 );
        set( "monk_value", 30 );
	set_perm_stat( "dex",  12);
	set_perm_stat( "str",  15);
	set_perm_stat( "int",  18);
	set_perm_stat( "piety", 8);
	set_perm_stat( "karma",14);
	set ("max_hp",290);
	set ("max_sp",20);
	set ("hit_points",290);
	set ("spell_points",20);
	set ("wealth", ([ "gold":33]) );
	set_natural_weapon(17,1,9);
        set_natural_armor(65,18);
        set ("special_defense",(["all":17]) );
	wield_weapon(Obj"shadow_dagger");
}

