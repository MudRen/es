#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("gold dauist hat", "�Ͻ����");
        add( "id", ({ "hat" }) );
        set_short("�Ͻ����");
        set_long(
                "���Ǵ�˵��������ʹ�õĵ��ڣ��ܵõ�����������������Ե�� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "evil":7, "divine":-5, "mental":8 ]) );
        set( "weight", 60 );
        set( "value", ({ 450, "gold" }) );
}



