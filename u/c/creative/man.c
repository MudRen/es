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
    equip_armor( "/d/mage/tower/armors/wizard_robe" );
    equip_armor( "/d/mage/tower/armors/wizard_shoe" );
    equip_armor( "/d/mage/tower/armors/wizard_cloak" );
    equip_armor( "/d/mage/tower/armors/wonderful_hat" );
    equip_armor( "/d/island/forest/obj/leggings" );
    equip_armor( "/d/eastland/saulin_temple/obj/eagle_bracer" );
    equip_armor("/d/monk/guild/armors/holy_ring");
}
