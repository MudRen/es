#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("god armbands", "�����ۻ�");
        add( "id", ({"armband","armbands" }) );
        set_short("a god armbands", "�����ۻ�");
        set_long(
        "An armband used by great monk.\n",
		"�ۻ�һ����ͷ��ʹ�õķ���, ����һЩɮ��Ҳʹ�ñۻ������ӷ��������ˡ�\n"
		"�����ۻ��ഫ�ǹ�����ʿ�͸������콫������, ��һ����������ʥ�����硣\n"
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "material","leather" );
        set( "weight", 38 );
        set( "no_sale", 1);
        set( "value", ({ 950, "silver" }) );
}
