#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("gold helmet", "��׺��������");
        add( "id", ({ "helmet" }) );
        set_short( "gold helmet", "��׺��������");
        set_long(
                "A beautiful golden helmet .\n",
                "�㿴��һ���ý�˿�̳ɵ�ͷ������Ե����Ŀ�ĺ�˿���������Ҳ�ʧ�����������\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "light_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "none":1, "magic":2]) );
        set( "weight", 80 );
        set( "value", ({ 260, "gold" }) );
}