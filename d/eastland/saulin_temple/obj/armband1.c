#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("armband of gun-in", "�����ۻ�");
        add( "id", ({"armband", }) );
        set_short("�����ۻ�");
        set_long(@C_LONG
�ۻ�һ����ͷ��ʹ�õķ���, ����һЩɮ��Ҳʹ�ñۻ������ӷ��������ˡ�
�����ۻ��ഫ�ǹ�����ʿ�͸������콫������, ��һ����������ʥ�����硣
C_LONG
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "material","leather" );
        set( "weight", 38 );
        set( "value", ({ 950, "silver" }) );
}
