#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_clothes ", "��ʿ֮�� ");
        add( "id", ({ "clothes","cloth" }) );
        set_short("samurai_clothes ", "��ʿ֮�� ");
        set_long(@AAA
������ʿ��ս��ʱ�������ս����,��Ȼ���ᵫȴ����ѵķ�����
��˵��������춴��·����ܹ��߼���ʦ��ף��
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 33 );
        set( "defense_bonus", 4 );
        set("material","element");
        set( "weight", 120 );
        set("special_defense",(["energy":5, ]));
        set( "value", ({ 900, "silver" }) );
}
