#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_helm ", "��ʿͷ��");
        add( "id", ({ "helm" }) );
        set_short("samurai_helm", "��ʿͷ��");
        set_long(@AAA
һ����ʿ����ʽ����ͷ��,��������ͷ����
AAA
        );
        set( "unit", "��"); 
        set( "type", "head" );
        set( "armor_class", 7 );
        set( "defense_bonus", 1 );
        set("material","element");
        set( "weight", 70 );
        set( "value", ({ 780, "silver"
        }) );
}
