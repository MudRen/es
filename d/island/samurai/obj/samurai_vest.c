#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_vest", "��ʿս��");
        add( "id", ({ "samurai_vest","vest" }) );
        set_short("samurai_vest", "��ʿս��");
        set_long(@AAA
����һ�����ؽ����Ƴ�֮ս��,���ṩ����ķ���,�����۽�
��,���Բ�����ͨ��ʿ���Դ���
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 15 );
        set( "defense_bonus", 5 );
        set("material","heavy_metal");
        set( "weight", 250 );
        set( "value", ({ 900, "silver" }) );
}
