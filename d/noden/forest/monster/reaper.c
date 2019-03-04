#include "../forest.h"
inherit MONSTER;

void create()
{
	::create();
	seteuid( getuid() );
	set_level(8);
	set_name( "small reaper", "С����" );
	add ("id", ({ "reaper", }) );
	set_short( "С����" );
	set_long( @C_LONG
��������������һ��û��֦Ҷ����, ���������̵�, �ÿ�����������
���Ľ���·���������ܺ���Ӧ����
C_LONG
	);
	set( "alignment", -200 );
    set( "race", "human" );
    set( "unit", "ֻ" );
    set( "aggressive", 1);
    set_skill( "longblade", 40);
    set( "wealth/silver", 20 );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "con", 8 );
	set_perm_stat( "piety", 5 );
	set_perm_stat( "karma", 3 );
	set("unbleeding", 1);
	set("special_defense", ([ "all": 50, "fire":25, ]) );
	set("aim_difficulty", ([ "critical":20, "weakest":30, "ganglion":50, ]) );
	set_natural_armor( 40, 10 );
	set_natural_weapon( 10, 3, 6 );
    set ("weight", 550);
    set_c_limbs( ({ "�����������", "���ֽŵ�֦��", "��ŵ�����"}) );
    wield_weapon( OBJ"blade" );
}
