#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's shield","����֮��");
        add("id",({"shield"}) );
        set_short("����֮��");
	set_long(@C_LONG
һ���ò��Ϸ��ƶ��ɵĶ��ƣ�����մ�������Ѫ�պ͵��ĺۼ���
C_LONG	         );
	set( "unit", "��" );
	set( "weight",70 );
	set( "type", "shield" );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "value", ({ 2000, "silver" }) );
}
