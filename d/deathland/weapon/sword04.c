#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("holy longsword","��ʥ����");
       add("id",({"sword","longsword",}) );
       set_short("a holy longsword","��ʥ����");
      	set_long(
           "A holy longsword used by holy guard.\n",
           "��ʥ����ʹ�õ���ʥ����.\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
    set("type","longblade");
	set( "min_damage", 22 );
	set( "max_damage", 33 );
	set( "weight", 150 );
	set( "value", ({ 300, "gold" }) );

}
