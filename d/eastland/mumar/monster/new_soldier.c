#include <../mumar.h>
inherit "/d/eastland/mumar/mumar_army";
 
void create()
{
        object ob1;
 
        ::create();
        set_level(4);
        set_name( "new soldier", "�±�" );
        add( "id", ({ "soldier","rookie" }) );
        set_short( "�±�" );
        set_long(
                "�㿴��һ���������ܼᶨ���±������ڲٳ���ս��������\n"
        );
        set( "gender", "male" );
        set( "alignment", 100 );
        set( "wealth/silver", 20 );
        set( "natural_armor_class", 20 );
        set( "natural_defense_bonus", 6 );
        set_perm_stat( "str", 2 );
        set_perm_stat( "dex", 7 );
        set_skill( "dodge", 30 );
 
        ob1 = new( OBJS"wooden_blade" );
        ob1->move(this_object());
        wield_weapon(ob1);
}
