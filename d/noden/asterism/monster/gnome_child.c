#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "Gnome child", "�ؾ�С��" );
	add ("id", ({ "child", "gnome", }) );
   set_short( "�ؾ�С��" );
	set_long(
                 "��˵�Ǹ�С��,�������ῴ�������ϡ���������ǽ�ϵķ��ţ�\n"
                 "���������дʣ������ڱ���ʲ���Ƶġ�\n");

        set( "alignment",-10);
        set( "gender", "male" );
        set( "race", "gnome" );
        set( "unit", "��" );
	set_perm_stat( "str", 5 );
	set ("wealth", ([ "gold": 3 ]) );
	set_natural_weapon(3,1,4);
	set_natural_armor(17,2);
        set("weight", 200);
	wield_weapon(WEAPONS"small_dagger");
}
