#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("jade cloth","����\��\��");
    add("id",({"jade","cloth"}) );
    set_short( "����\��\��");
	set_long(
		"����һ������\��\�£����ڶ����˵����п��Ա�а��ħ���������ˣ�\n"
		"����·���ȫ�����Ƴɣ����������в���˼���Ч����\n"
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 220 );
	set( "type", "body" );
	set( "armor_class", 31 );
        set("material","element");
	set( "defense_bonus", 10 );
	set( "value", ({ 290, "gold" }) );
        set( "special_defense",(["evil":10,"poison":8,"devine":-10,"acid":6,"none":7]));
        set( "extra_stats",(["dex":-3,"kar":1,"str":-1]));
                                    
}
