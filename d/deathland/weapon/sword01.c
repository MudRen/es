#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Mithril LongSword","�����ﳤ��");
       add("id",({"sword","longsword",}) );
       set_short("�����ﳤ��");
      	set_long(
           "�����õ������ﳤ��\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 28 );
    set("type","longblade");
	set( "min_damage", 10 );
	set( "max_damage", 28 );
	set( "weight", 100 );
	set( "value", ({ 120, "gold" }) );

}
