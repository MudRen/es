#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("emporer armband", "���ͱۻ�");
    add( "id", ({"armband", }) );
    set_short("���ͱۻ�");
    set_long(@C_LONG
�ۻ�һ����ͷ��ʹ�õķ���, ����һЩɮ��Ҳʹ�ñۻ������ӷ��������ˡ�
���ͱۻ�������������ɮ����������������ʱ, �������ͱ��õ�ʥ��... 
��������, ����������ɮ���������Ϊ�١�
C_LONG
              );
    set( "unit", "��");
    set( "type", "arms" );
    set( "armor_class", 4 );
	set("material","stone");
    set( "defense_bonus", 4 );
    set( "weight", 30 );
    set( "value", ({ 150, "gold" }) );
}
