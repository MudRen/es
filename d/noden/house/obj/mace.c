#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "crimson mace", "Ѫ�춤ͷ�" );
   add("id",({"mace",}));
   set_short("Ѫ�춤ͷ�");
   set_long(
        "һ����ͨ��Ѫ�춤ͷ鳡�\n"
               );
	set( "unit", "��" );
   set( "weapon_class", 17 );
   set( "type", "blunt" );
   set( "min_damage", 9 );
   set( "max_damage", 20 );
   set( "weight", 150 );
   set( "value", ({ 50, "gold" }) );
   set("extra_skills",(["anatomlogy": 5]));
}
