#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky shoes", "����Ь");
        add( "id", ({ "boots","shoes" }) );
        set_short( "����Ь" );
        set_long(
@C_LONG
����һ˫�ܴ������˵�Ь�ӡ��ɰ�ɫ����ϸ�ܵ�֯�ɣ�Ь������һ
��С���ı�־��
C_LONG
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
   set("extra_skills",(["steal": 10 ]));
        set( "defense_bonus", 5 );
        set( "weight", 38 );
        set( "value", ({ 120, "gold" }) );
}
