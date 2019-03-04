#include "../ruin.h"
inherit MONSTER;

#define MIN_GARGOYLES 6

void create()
{
	::create();
	seteuid( getuid() );
	set_level(9);
	set_name( "Gargoyle", "ʯ���" );
	add ("id", ({ "gargoyle", }) );
	set_short( "ʯ���" );
	set_long( @C_LONG
��ʹ�ñ����ĳ��������з���, �����Ƚ�ϲ����ס�ںڰ��Ľ��䡣��ʹ��
ͷ�ϵ���ֻ��, �������ˡ�
C_LONG
	);
	set( "alignment", -250 );
    set( "gender", "male" );
    set( "race", "daemon" );
    set( "unit", "ֻ" );
    set( "killer", 1);
	set_perm_stat( "dex", 14 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 7 );
	set_perm_stat( "con", 13 );
	set_perm_stat( "piety", 5 );
	set_perm_stat( "karma", 10 );
	set("max_hp", 400);
	set("hit_points", 400);
	set("unbleeding", 1);
	set("special_defense", ([ "all":30, "none":15, ]) );
	set("aim_difficulty",
		([ "critical":30, "ganglion":50, "weakest":20, ]) );
	set_natural_weapon( 40, 10, 18 );
	set_natural_armor( 55, 10 );
    set("weight", 550);
    set_c_limbs( ({ "������", "��ͷ", "�Ľ�", "�Ľ�"}) );
    set_c_verbs( ({ "%s�ýǴ�%s", "%s��%s", "%sײ%s",}) ); 
}

void die()
{
	object env;
	env = environment(this_object());
	if( env->query("mob_storage") && 
		((int)env->query("mob_storage") > MIN_GARGOYLES) )
		env->add("mob_storage", -1);
	::die();
}
