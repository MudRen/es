#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("holy ring","��Ⱦ������ָ");
    add("id",({"ring"}) );
    set_short( "��Ⱦ������ָ");
	set_long(@C_LONG
�����������֮һ �� ��Ⱦ����ʹ�ù��Ľ�ָ,�����������
����֮ʿ, ����������֮���ӻ���ġ�
C_LONG
       	        );
	set( "unit", "��" );
	set( "weight", 12 );
	set( "type", "finger" );
	set( "material","stone");
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
	set( "value", ({ 300, "gold" }) );
}
