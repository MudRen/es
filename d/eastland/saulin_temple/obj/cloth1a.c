#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("damo plate","��ħʥ��");
    add("id",({"plate","damo"}) );
    set_short( "��ħʥ��");
	set_long(@C_LONG
����һ���������ƾɵ�ս��, �ഫ�ǵ��������Ͱ�����ս��ʱ����������, ������
��Χ��һ�����, ɢ����һ����ʥ����Ϣ... 
C_LONG
    	         );
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 360 );
	set( "type", "body" );
    set( "material","monk");
	set( "armor_class", 30 );
	set( "defense_bonus", 5 );
	set( "value", ({ 200, "gold" }) );
}
