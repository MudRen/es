#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("enforcer robe","ִ����֮��");
        add("id",({"robe"}) );
        set_short("ִ����֮��");
	set_long(@C_LONG
��ֻ������һ������ͨͨ������,�������з������,�㼴ʹ����ɮ��,����������
������һ���¡�
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 3 );
	set( "value", ({ 500, "silver" }) );
}
