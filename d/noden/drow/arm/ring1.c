#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("copper ring", "��ָͭ��");
   add( "id", ({ "ring" }) );
        set_short( "��ָͭ��" );
        set_long(
@C_LONG
���Ǹ���ͭ�Ƶ���ָ�׻����������֩��ı�־��
C_LONG
        );
        set( "unit", "ֻ");
        set( "type", "finger" );
        set( "material", "heavy_metal" );
        set( "defense_bonus", 2 );
        set( "weight", 17 );
        set( "value", ({ 120, "silver" }) );
}
