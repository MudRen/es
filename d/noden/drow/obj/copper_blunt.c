#include <mudlib.h>

inherit WEAPON;
void create()
{
       set_name("copper blunt","ͭ��");
   add("id",({"blunt"}));
   set_short("ͭ��");
       set_long(
@C_LONG
�������ǰ�ͭ�Ƶĳ������ȣ�����ͷ�ϵ����֩���ͼ�ơ�
C_LONG
        );

        set( "unit", "��" );
        set( "weapon_class", 11 );
        set("type","blunt");
        set( "min_damage", 12 );
        set( "max_damage", 16 );
        set( "weight", 50 );
        set( "value", ({ 180 , "silver" }) );
}
