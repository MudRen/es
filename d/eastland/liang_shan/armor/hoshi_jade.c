#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("hoshi jade", "�����");
        add( "id", ({ "jade" }) );
        set_short("�����");
        set_long(
                "������������ĺ���赣����Ͽ�ɫ����֬��������������·���\n"
                "��: ������죬�����Ҳ����ഫ�ǳ��˱�������֣��������ϣ�\n"
        );
        set( "no_sale",1);
        set( "unit", "��");
        set( "type", "misc" );
        set( "material", "element");
        set( "armor_class", 0);
        set( "defense_bonus", 8 );
        set( "special_defense",
             ([ "evil":8, "none":-7,"poison":5 ]) );
        set( "weight", 30 );
        set( "value", ({ 1880, "silver" }) );
}
