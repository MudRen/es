#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("Gurad mail","��з��");
    add("id",({"plate","mail"}) );
    set_short( "guard mail","��з��");
	set_long(
		"\n",
		"���ս���ɺ�з���Ƴɣ���Ӳ�ı�ƤӦ�ֵܵ�һ��Ĺ�����\n"
	);
	set( "unit", "��" );
	set( "weight", 220 );
	set( "type", "body" );
	set( "armor_class", 33 );
        set("material","element");
	set( "defense_bonus", 6 );
	set( "value", ({ 70, "gold" }) );
                                    
}
