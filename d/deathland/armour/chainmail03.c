#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("gray chainmail","��ɫ����");
        add("id",({"chainmail"}) );
        set_short( "a gray chainmail","��ɫ����");
	    set_long(
  "����һ����������\��ʿ�������ġ���,������������Ѿ���ɻ�ɫ��\n"
	);
	set( "unit", "��" );
	set( "weight", 230 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 15 );
	set( "defense_bonus", 0 );
	set( "value", ({ 400, "silver" }) );
}
