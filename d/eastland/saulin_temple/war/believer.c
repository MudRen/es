
#include "saulin_war.h"

inherit War;

void create ()
{

        ::create();
    set_level(11);
    set_name("believer of evil god","�����̵���");
    add ("id", ({ "believer",}) );
    set_short("�����̵���");
        set_long(@C_LONG
����һ�������̵��ӣ�һ��\�������˵ã��������������ҽ�ͽ��
C_LONG
 );
	set("alignment",10);
	set( "gender", "male" );
	set( "race", "human");
	set( "unit", "��" );
        set( "moving", 1 );
        set( "speed", 20 );
//	set( "wimpy", 40 );
        set( "pursuing", 1 );
        set( "killer", 1 );
        set( "monk_value", 40 );
	set_perm_stat( "dex",  13);
	set_perm_stat( "str",  17);
	set_perm_stat( "int",   8);
	set_perm_stat( "piety", 8);
	set_perm_stat( "karma",15);
        set_skill("shortblade",60);
        set_skill("parry",55);
	set ("max_hp",350);
	set ("max_sp",0);
	set ("hit_points",350);
	set ("spell_points",0);
	set ("wealth", ([ "gold":13]) );
	set_natural_weapon(12,4,9);
        set_natural_armor(35,0);
	set ("weight", 350);
	equip_armor(Obj"water_suit");
	wield_weapon(Obj"water_sword");
	equip_armor(Obj"water_armband");
}

