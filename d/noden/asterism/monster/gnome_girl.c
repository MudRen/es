#include "../asterism.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(3);
	set_name( "Gnome little girl", "�ؾ�СŮ��" );
	add ("id", ({ "girl", "gnome","little girl" }) );
   set_short( "�ؾ�СŮ��" );
	set_long(
                 "һ���ؾ�СŮ��.����������רע��ж����ϵ��顣\n");

    set ("alignment",200 );
    set( "gender", "female" );
    set( "race", "gnome" );
    set( "unit", "��" );
	set_perm_stat( "dex", 6 );
	set ("wealth", ([ "silver": 5 ]) );
	set_natural_weapon(3,1,5);
	set_natural_armor(20,0);
    set ("weight", 200);
    wield_weapon(WEAPONS"small_dagger");
}
