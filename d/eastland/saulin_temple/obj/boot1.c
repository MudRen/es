#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("cloud boots", "�����Ь");
        add( "id", ({ "boots","boot" }) );
        set_short("�����Ь");
        set_long(@C_LONG
����ɮ��֮Ь�ӳ�Ϊ��Ь, ��ɮЬҲ��
������ʴ�۴͸�̫���Ͼ���Ь��, �ഫ����Ȼ�ص����������ˡ�
C_LONG
        );
        set("material","cloth");
        set( "unit", "˫");
        set( "type", "feet" );
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "weight", 120 );
        set( "value", ({ 2450, "silver" }) );
        set( "no_sale", 1 );
}
