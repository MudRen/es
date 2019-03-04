#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky headband", "幸运头巾");
   add( "id", ({ "headband" }) );
        set_short( "幸运头巾" );
        set_long(
@C_LONG
这是张乳白色的头巾，在扎发的尾端织有小刀的标记，看起来大方
而自然，可能也是毕老爹遗失的东西吧！
C_LONG
        );
        set( "unit", "条");
        set( "type", "head" );
        set( "material", "cloth" );
        set( "armor_class", 2 );
   set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "poison": 5, "fire": 10, "cold" : -15 ]) );
        set( "weight", 30 );
        set( "value", ({ 1960, "silver" }) );
   set( "no_sale", 1 );
        set( "equip_func","equip_headband" );
        set( "unequip_func","unequip_headband" );
}

void equip_headband()
{
        string cla,him;
        him=this_player()->query( "c_name" );
        cla=this_player()->query( "class" );
        if( cla!="thief" )
        {
         tell_object(this_player(),"\n只有小偷才能引发它的幸运魔力啦！\n\n");
         tell_room(environment(this_player()),
         "\n你看到"+him+"戴上幸运头巾後，像乩童般的跳起舞来，还流一地口水，天啊。\n\n",this_player());
        }
        else
        {
         tell_room(environment(this_player()),"\n你看见"+him+"戴上幸运头巾後，举起手作Ｖ手势，神经！\n\n"
         ,this_player());
         tell_object(this_player(),"\n你戴上头巾後，感觉精神一震！似乎幸运女神就在你身边！\n\n"
         );    
   set( "armor_class", 6 );
   set("material","thief");
   set( "defense_bonus", 5 );
        }
        return ;
}

void unequip_headband()
{
        set( "armor_class",2 );
   set( "defense_bonus", 2 );
        return ;
}
                                                                                                
