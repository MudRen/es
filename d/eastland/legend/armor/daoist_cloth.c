#include <mudlib.h>

inherit ARMOR;

void create()
{
      set_name("daoist's cloth","茅山八卦袍");
      add("id",({"cloth"}) );
      set_short("茅山八卦袍");
      set_long(@C_LONG
一件茅山道士所穿的衣服，後面绣著一个八卦的图形。
C_LONG           );
      set( "unit", "件" );
      set( "weight",100 );
      set( "type", "body" );
      set("material","mage");
      set( "armor_class", 34);
      set( "defense_bonus", 7 );
      set("special_defense",
          (["fire":30,"evil":30,"magic":30,"cold":-30,"mental":-70]) );
      set( "value", ({1500, "silver" }) );
}                                                                                                             