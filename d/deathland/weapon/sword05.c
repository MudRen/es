#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("skeleton longblade","�׹ǳ���");
       add("id",({"longblade",}) );
       set_short("�׹ǳ���");
      	set_long(
           "������ʹ�õİ׹ǳ���.\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 30 );
    set("type","longblade");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 150 );
	set( "value", ({ 10, "gold" }) );
	set("no_sale",1);
}
