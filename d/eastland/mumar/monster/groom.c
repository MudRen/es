#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(5);
        set_name( "groom", "���" );
        set_short( "���" );
        add( "id", ({ "groom" }) );
        set_long( "һ����򣬸��𿴹��չ����������ǡ�\n" );
        set( "gender", "male" );
        set( "alignment", 150 );
        set( "wealth/silver", 30 );
        set( "natural_armor_class", 26 );
        set( "natural_defense_bonus", 12 );
        set( "no_attack",1 );
        set_natural_weapon(11,4,14);
        set_perm_stat( "str", 5 );
        set_perm_stat( "dex", 7 );
        set_skill( "dodge", 50 );
}
