#include <mudlib.h>
#include <ansi.h>
inherit MONSTER ;

void create()
{
        ::create();
        set_level(1);
        set_name("richman",""+HIB"����"+NOR"");
        add( "id", ({ "rat" }) );
        set_short(""+HIB"����"+NOR"");
        set_long(""+HIR"��ʿ���ϴ󣬺̱ܿ���"+NOR"\n");
        set("unit", "ֻ");
        set_perm_stat("int", 1);
        set ("wealth", ([ "gold": 30000 ]) );
    equip_armor( "/d/mage/tower/armors/wizard_amulet" );
}
