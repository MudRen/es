#include "../takeda.h"
inherit ARMOR;

void create()
{
        set_name("Blue amulet", "��Ы�ƻ�");
        add( "id", ({ "amulet" }) );
        set_short("blue amulet", "��Ы�ƻ�");
        set_long(
                " .\n",
                "����һ�����ξ��ɵĻ������������һ����ɫ��Ы��\n"
                "��ͼ�����ʡ���ɫ���ƺ��������ص����������У�\n"
        );
        set( "unit", "��");
        set( "type", "misc" );
        set( "material", "elemental");
        set( "armor_class", 0);
        set( "defense_bonus", 6 );
        set( "special_defense",
             ([ "evil":-4, "divine":-8,"poison":10 ]) );
        set( "weight", 20 );
        set( "value", ({ 1500, "silver" }) );
}
