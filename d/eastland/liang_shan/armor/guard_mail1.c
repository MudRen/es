#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("Soft mail","��Ϻ����");
    add("id",({"plate","mail"}) );
    set_short( "soft mail","��Ϻ����");
	set_long(
		"\n",
		"���ս���������Ϻ���Ƴɣ����͵ı�ƤӦ�ܷ�������˸յ�Ч����\n"
	);
	set( "unit", "��" );
	set( "weight", 140 );
	set( "type", "body" );
	set( "armor_class", 31 );
        set("material","element");
	set( "defense_bonus", 3 );
	set( "value", ({ 77, "gold" }) );
                                    
}
