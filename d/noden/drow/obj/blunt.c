#include <mudlib.h>

inherit WEAPON;
void create()
{
       set_name("blunt","�ⵣ");
       add("id",({"blunt",}) );
   set_short("�ⵣ");
       set_long(
@C_LONG
    ����ū������������ĳ��ⵣ��
C_LONG
        );

        set( "unit", "��" );
        set( "weapon_class", 9 );
    set("type","blunt");
        set( "min_damage", 6 );
        set( "max_damage", 10 );
        set( "weight", 35 );
        set( "value", ({ 80 , "silver" }) );
}
