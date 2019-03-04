#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
	//seteuid( getuid() );
    set_level(4);
    set_name("injured soldier","�����˱�");
add ("id", ({ "soldier","dwarf"}) );
set_short( "a dwarf injured soldier",
           "�����˱�");
	set_long(@LONG
A dwarf soldier is defending the evil troll and protecting his country,but
he is injured now
LONG
    ,@C_LONG
һ����ս���������˵�ʿ��,���ϳ����˰̺�,����Ŀǰȫ���Ǳ���.
C_LONG
	);
    set("alignment", 20 );
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",4);
    set_perm_stat( "str",5);
    set_perm_stat( "int",3);
    set_perm_stat( "piety",2);
    set_perm_stat( "karma", 3);
	
    set ("max_hp",140);
    set ("max_sp",0);
    set ("hit_points",140);
    set ("spell_points",0);
    set ("wealth", ([ "gold":3]) );
    set_natural_weapon(8,4,9);
    set_natural_armor(20,0);
    set ("weight", 350);

}


