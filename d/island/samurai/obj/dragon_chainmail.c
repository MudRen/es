#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "dragon chainmail","����֮��");
        add( "id", ({ "chainmail","dragon" }) );
        set_short( "dragon chainmail","����֮��" );
        set_long(@AAA
һ�����з���ͼ�������ף����г��ߵķ������������߸����Ĵ���֮����˵
��߷�����������������������Ѫ��
AAA
        );
        set( "unit", "��"); 
        set( "type", "body" );
        set( "armor_class", 35 );
        set( "defense_bonus", 4 );
        set("material","element");
        set("extra_skills", ([ "dodge" : 5 ]) );
        set( "weight", 170 );
        set( "no_sale",1);
        set( "value", ({ 1600, "silver"
         }) );
}
