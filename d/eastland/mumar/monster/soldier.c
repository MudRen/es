#include <../mumar.h>
inherit "/d/eastland/mumar/mumar_army";
 
void create()
{
        ::create();
        set_level(6);
        set_name( "soldier", "ʿ��" );
        set_short( "ʿ��" );
        add( "id", ({ "soldier" }) );
        set_long(
                "һ������ص�����ʿ����\n"
        );
        set( "gender", "male" );
        set( "alignment", 150 );
        set( "wealth/silver", 40 );
        set( "natural_armor_class", 10 );
        set( "natural_defense_bonus", 15);
        set_natural_weapon( 5, 3, 7 );
        set_perm_stat( "str", 6 );
        set_perm_stat( "dex", 8 );
        set_skill( "dodge", 30 );
        set_skill( "parry", 30 );
 
        equip_armor(OBJS"mail01");
        wield_weapon(OBJS"javelin");
}
