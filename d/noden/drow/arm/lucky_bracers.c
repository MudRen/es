#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky-bracers","幸运手镯");
        add( "id", ({"bracers" }) );
   set_short("幸运手镯");
        set_long(
"这是一个能带给你幸运的漂亮手镯，可是，好像只有给一些不守正道的人．．\n"
                );
        set( "unit", "个");
        set ( "type", "hands" );
   set("armor_class",5);
      set("defense_bonus",3);
   set( "material", "thief" );
        set( "weight", 22 );
        set( "value", ({ 200, "gold" }) );
        set( "no_sale",1);
        set("extra_skills",(["backstab":10,"dodge":5]));
}
