#include <mudlib.h>

inherit ARMOR;
void create()
{
     set_name( "God-Dragon shield","ÉıÁú¶Ü" );
     add( "id",({ "shield" }) );
     set_short( "ÉıÁú¶Ü" );
     set_long(@C_LONG
Ò»Ãæ²ÁÊÃµÄºÜÇ¬¾»µÄ¶ÜÅÆ£¬ÉÏ»æÒ»Ë«ÕÅÑÀÎè×¦µÄ·ÉÁú£¬èòèòÈçÉú¡£
C_LONG
     );
     set( "weight",50 );
     set( "unit", "Ãæ");
     set( "type", "shield" );
     set( "material","element" );
     set( "armor_class",7 );
     set( "defense_bonus",5 );
     set( "value",({ 3000,"silver" }) );
     set( "equip_func","equip_cloth");
     set( "unequip_func","unequip_cloth" );
}
int equip_cloth()
{
    set("light",1);
    this_player()->add_temp("can_pass_spell",1 );
    return 1;
}
int unequip_cloth()
{
    delete("light");
    this_player()->add_temp("can_pass_spell",-1);
    return 1;
}