#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("floral cape", "�ٻ���������");
        add( "id", ({ "cloak","cape" }) );
        set_short("floral cape","�ٻ����������");
        set_long(
                "This is a green cloak with some floral mark.\n",
                "����һ�����̵Ķ�������׺�������İ׻�ͼ�Σ�����������\n"
                "����Ĳ�ԭ���������������ϣ��...\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set( "weight", 90 );
        set( "value", ({ 1100, "silver" }) );
}