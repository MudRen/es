#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("Necklace of love","�������");
        add("id",({"necklace"}) );
         set_short( "Necklace of love","�������");
	set_long(
"This is a magic necklace , it is growing and you feel you got a strong mind .\n",
"����һ��ϵ��һ�ѽ�ɫԿ�׵��������������Կ��ɢ����һ�ֺ�������\n"+
"�Ĺ�â�������������������Ҳ�������ˡ�\n"
	);
	set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 20 );
        set("material","light_metal");
	set( "type", "misc" );
	set( "armor_class", 0 );
        set( "defense_bonus", 6 );
	set( "value", ({ 200, "gold" }) );
        set("special_defense",(["mental":30, ]));
        set("extra_stats",(["con":-1 ]));

}
