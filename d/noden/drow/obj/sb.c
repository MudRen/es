#include <mudlib.h>

inherit WEAPON;
void create()
{
   set_name("shortsword","С�̵�");
   add("id",({"sword"}) );
   set_short("С�̵�");
       set_long(
@C_LONG
    С���۵�С���ӡ�
C_LONG
        );

        set( "unit", "��" );
        set( "weapon_class", 6 );
    set("type","shortblade");
        set( "min_damage", 2 );
        set( "max_damage", 6 );
        set( "weight", 20 );
        set( "value", ({ 40 , "silver" }) );
}
// Ending QC.
