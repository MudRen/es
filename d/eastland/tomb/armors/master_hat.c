#include <mudlib.h>
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
        set( "material", "mage");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "evil":5, "divine":5, "mental":4 ]) );
        set( "weight", 60 );
        set( "value", ({ 450, "gold" }) );
}



