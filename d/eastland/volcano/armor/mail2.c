#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("volcano-rocks mail", "��ɽ���ۼ�");
        add( "id", ({ "mail" }) );
        set_short( "��ɽ���ۼ�");
        set_long(
                "����ۼ������û�ɽ���Ƴɡ�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "stone");
        set( "armor_class", 13 );
        set( "weight", 270 );
        set( "value", ({ 100, "gold" }) );
}






