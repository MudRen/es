#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("cloth","ů��");
        add("id",({"cloth"}) );
        set_short("ů��");
	set_long(@C_LONG
�ⲻ����һ��Ѱ�����·���
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 4 );
	set("special_defense",
	     (["fire":5,"cold":5]) );
	set( "value", ({ 350, "silver" }) );
}
