#include <mudlib.h>

inherit WEAPON;
void create()
{
       set_name("copper hammer","ͭ�ǡ�");
   add("id",({"hammer"}));
   set_short("ͭ�ǡ�");
       set_long(
@C_LONG
���ǰ���ͭƬ����ԭľ���ϵġ��ӣ��հѵĵط�����֩���ͼ����
C_LONG
        );

        set( "unit", "��" );
        set( "weapon_class", 15 );
        set("type","blunt");
        set( "min_damage", 14 );
        set( "max_damage", 20 );
        set( "weight", 80 );
        set( "value", ({ 280 , "silver" }) );
}
