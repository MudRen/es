#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("damo plate","��ħʥ��");
    add("id",({"plate","damo"}) );
    set_short( "damo plate","��ħʥ��");
	set_long(
"This is a suit of plate, and it is worn by damo.\n",
"����һ���������ƾɵ�ս��, �ഫ�ǵ��������Ͱ�����ս��ʱ����������, ������\n"
"��Χ��һ�����, ɢ����һ����ʥ����Ϣ... \n"
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 360 );
	set( "type", "body" );
    set( "material","monk");
	set( "armor_class", 40 );
	set( "defense_bonus", 5 );
	set( "value", ({ 200, "gold" }) );
}
