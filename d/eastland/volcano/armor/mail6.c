#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("golden scalemail", "�ƽ����Ӽ�");
        add( "id", ({ "mail" }) );
        set_short("�ƽ����Ӽ�");
        set_long(
                "�������������һƬƬ�Ļƽ���ܷ�϶��ɡ�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "heavy_metal");
        set( "armor_class", 35 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "mental":10 ]) );
        set( "weight", 250 );
        set( "no_sell",1);
        set( "value", ({ 400, "gold" }) );
}
