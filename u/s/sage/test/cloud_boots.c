#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("cloud boots", "�����Ь");
        add( "id", ({ "boots","boot" }) );
        set_short("a pair of cloud boots", "�����Ь");
        set_long(
"A pair of boots made of clouds  .\n",
"����ɮ��֮Ь�ӳ�Ϊ��Ь, ��ɮЬҲ��\n"
"������ʴ�۴͸�̫���Ͼ���Ь��, �ഫ����Ȼ�ص����������ˡ�\n"
        );
        set("material","cloth");
        set( "unit", "˫");
        set( "type", "feet" );
        set( "armor_class", 8 );
        set( "defense_bonus", 4 );
        set( "weight", 120 );
        set( "value", ({ 2450, "silver" }) );
        set( "no_sale", 1 );
}
