#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper armbands", "��ͭ�ۻ�");
   add( "id", ({ "armbands" }) );
        set_short( "��ͭ�ۻ�" );
        set_long(
@C_LONG
�����ɻ�ͭ����ıۻ������ض���ʵ�Ĳ����ܱ�������ֱۡ�
C_LONG
        );
        set( "unit", "��");
         set( "type","arms" );
        set( "material", "heavy_metal" );
        set( "armor_class", 4 );
        set( "defense_bonus", 1 );
        set( "weight", 65 );
        set( "value", ({ 210, "silver" }) );
}
